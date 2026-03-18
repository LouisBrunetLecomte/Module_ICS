# Rendu C systeme B

## 2

**Question 2.1 :**<br>
La fonction sigaction permet de définir un 'handler' pour un signal. En respectant les points particuliers mis en exergue dans les paragraphes précédents vous devez : Écrire un programme qui se « forke » en 5 enfants. Toutes les secondes sur une durée de 30 secondes, le processus père doit envoyer un signal SIGUSR1 a l’un des enfants.
Le processus recevant le signal SIGUSR1 doit afficher le message « Hello from PID », PID étant le pid du processus enfant. Une fois les 30 secondes écoulées, le processus parent doit envoyer un signal SIGINT aux 5 processus enfants (Attention aux processus Zombie) <br>
```c
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>


void handler(int signum) {
    printf("Hello from PID %d\n", getpid());
}

void setHandler() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = SIGUSR1;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
}

void finish(int signum) {
    printf("PID %d : finished\n", getpid());
    exit(0);
}

void setFinish() {
    struct sigaction sa;
    sa.sa_handler = finish;
    sa.sa_flags = SIGINT;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

void processChild() {
    setHandler();
    setFinish();
    printf("setting hander\n");
    for(;;) {
        sleep(1);
    }
}

int main() {
    srand(time(NULL));
    int pidTab[5];
    int pid;
    for(int i=0;i<5;i++) {
        pid = fork();
        if(pid < 0) {
            perror("error when creating fork.");
            return 1;
        }
        if(pid == 0) {
            processChild();
            exit(-1);
        }
        pidTab[i] = pid;
    }
    sleep(1);
    for(int i=0;i<10;i++) {
        kill(pidTab[rand() % 5], SIGUSR1);
        sleep(1);
    }
    for(int i=0;i<5;i++) {
        kill(pidTab[i], SIGINT);
        wait(NULL);
    }
    return 0;
}
```
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

// Handler pour le signal SIGUSR1
void handle_sigusr1(int sig) {
    printf("Hello from PID %d\n", getpid());
}

void init_handler_sigusr1() {
    struct sigaction sa;
    sa.sa_handler = handle_sigusr1;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
}

// Handler pour le signal SIGINT
void handle_sigint(int sig) {
    printf("finish PID %d\n", getpid());
	exit(0);
}

void init_handler_sigint() {
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
}

int main() {
    pid_t children[5];

    // Création des 5 enfants
    for (int i = 0; i < 5; i++) {
        if ((children[i] = fork()) == 0) {
            // Code enfant
            // On établit les handlers
			init_handler_sigusr1();
			init_handler_sigint();
            while (1) {
                pause(); // Attendre un signal
            }
            exit(0); // Ne doit jamais être atteint
        }
    }

	sleep(1); // on attend que tous les handlers soient en place avant de commencer

    // Processus parent
    for (int i = 0; i < 30; i++) {
        kill(children[rand() % 5], SIGUSR1);
        sleep(1);
    }
	
    for (int i = 0; i < 5; i++) {
        kill(children[i], SIGINT);
    }

	sleep(1); // on attend que tous aient réagit au signal avant de continuer

    // Attendre la fin des enfants pour éviter les zombies
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    return 0;
}
```

<br><br>

**Question 2.2 :**<br>
Il existe une fonction signal qui permet de faire presque la même chose que sigaction. Pourtant son utilisation est fortement déconseillée. Pourquoi ?<br>

signal() fait quasiment la meme chose que sigaction mais elle est qualifiée d'imprévisible et elle peut avoir des comportements qui changent selon les systèmes. Et elle ne peut pas de décortiquer et analyser les signaux. Alors pourquoi utiliser une fonction qui est dépréciée et qui est moins précise ?

<br><br>


## 3

**Question 3.1 :**<br>
```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/stat.h>

char * shared_memory;
int segment_id;

void handle(int sig) {
	printf("Hello from PID %d | randNum = %s\n", getpid(), shared_memory);
	shmdt(shared_memory);
	shared_memory = (char *) shmat(segment_id, 0, 0);

}

void setHandler() {
    struct sigaction sa;
    sa.sa_handler = handle;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
}

void finish(int signum) {
    printf("PID %d : finished\n", getpid());
    exit(0);
}

void setFinish() {
    struct sigaction sa;
    sa.sa_handler = finish;
    sa.sa_flags = SIGINT;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

int main()
{
    struct shmid_ds shmbuffer;
    int segment_size;
    const int shared_segment_size = 0x400;

    segment_id = shmget(IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	int randNum;
	shared_memory = (char *) shmat(segment_id, 0, 0);

	srand(time(NULL));
	int p = fork();

	if(p < 0) {
		perror("error when creating fork.");
		return 1;
	} else if(p > 0) {
		// parent
		sleep(1);
		for(int i=0;i<5;i++) {
			randNum = rand() % 100;
			sprintf(shared_memory, "%d", randNum);
			printf("random number : %d\n", randNum);
			shmdt(shared_memory);
			shared_memory = (char *) shmat(segment_id, (void *) 0x5000000, 0);
			kill(p, SIGUSR1);
			sleep(1);
		}
		kill(p, SIGINT);
        wait(NULL);
	} else {
		// enfant
		setHandler();
		setFinish();
		printf("Handlers set\n");
		while(1) {
        	pause();
    	}
		exit(1); // on ne doit jamais arriver ici
	}

	return (0);
}
```
<br><br>

## 4<br>

**Question A :**<br>
Pour mettre en correspondance un fichier ordinaire avec la mémoire d’un processus, utilisez l’appel mmap. Cette fonction accepte 6 paramètres. Donnez le rôle de chacun des paramètres avec les valeurs possibles.<br>
Les 6 paramètres sont les suivants : 
- addr : Adresse mémoire souhaitée pour le mapping. NULL : le noyau choisit l’adresse. Adresse spécifique : utiliser avec MAP_FIXED.

- len : Taille du segment mémoire à mapper (en octets). Doit être > 0 et souvent multiple de la taille d’une page.

- prot : Permissions d’accès sur la zone mémoire.
PROT_READ   : lecture autorisée
PROT_WRITE  : écriture autorisée
PROT_EXEC   : exécution autorisée
PROT_NONE   : pas d’accès
(combinaison possible avec OR, ex : PROT_READ | PROT_WRITE)

- flags : Comportement du mapping.
MAP_SHARED   : modifications propagées au fichier
MAP_PRIVATE  : modifications locales (copy-on-write)
MAP_ANONYMOUS: pas de fichier associé (fd ignoré)
MAP_FIXED    : impose d’utiliser exactement addr
MAP_POPULATE : précharge les pages

- fd : Descripteur de fichier à mapper.
Obtenu avec open()
-1 si MAP_ANONYMOUS est utilisé

- offset : Décalage dans le fichier à partir duquel commence le mapping.
Doit être un multiple de la taille de page
Permet de mapper une partie spécifique du fichier

<br><br>

**Question B :**<br>
Que signifie la ligne « PROT_READ | PROT_WRITE » dans le fichier reader.c.<br>
Elles permettent de faire en sortes que le processus puisse lire et écrire dans la mémoire.

<br><br>

**Question C :**<br>
A quoi sert le drapeau MAP_SHARED ?<br>
Avec MAP_SHARED ce que je change dans la mémoire est aussi changé dans le fichier. Si d’autres programmes lisent ce fichier ils voient mes modifications.

<br><br>

**Question D :**<br>
Utilisez les fichiers reader.c et writer.c pour écrire deux programmes. Le premier programme écrira sous forme binaire le contenu d’un tableau d’entiers de 5 valeurs aléatoires dans la mémoire mappée. Le second programme devra lire ces valeurs depuis la mémoire mappée, et les afficher.<br>
```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


#define FILE_LENGTH sizeof(int) * 5  // 5 entiers

int main() {
    int fd;
    int *file_memory;

    srand(time(NULL));

    // Création du fichier ou ouverture s'il existe
    fd = open("shared.bin", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if(fd < 0) { perror("open"); exit(1); } //affiche une erreur si échec


    ftruncate(fd, FILE_LENGTH); // Fixer la taille du fichier

    
    // Mapping mémoire
    file_memory = (int *) mmap(NULL, FILE_LENGTH, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if(file_memory == (void*) -1) { perror("mmap"); exit(1); }

    close(fd); // fd plus nécessaire après mmap

    // Écriture des 5 entiers aléatoires (-100 à 100)
    for(int i = 0; i < 5; i++) {
        file_memory[i] = rand() % 201 - 100;
        printf("[WRITER] Valeur écrite : %d\n", file_memory[i]);
    }

    // Libération mémoire
    munmap(file_memory, FILE_LENGTH);


    // Ouverture du fichier existant
    fd = open("shared.bin", O_RDONLY);
    if(fd < 0) { perror("open"); exit(1); }

    // Mapping mémoire
    file_memory = (int *) mmap(NULL, FILE_LENGTH, PROT_READ, MAP_SHARED, fd, 0);
    if(file_memory == (void*) -1) { perror("mmap"); exit(1); }

    close(fd);

    // Lecture et affichage des 5 entiers
    for(int i = 0; i < 5; i++) {
        printf("[READER] Valeur lue : %d\n", file_memory[i]);
    }

    // Libération mémoire
    munmap(file_memory, FILE_LENGTH);

    return 0;
}
```