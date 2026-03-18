# Rendu TP 5 C :

## 2 : 
**[2A] Vous devez écrire un programme qui se « forke » :** <br>
- Le processus parent devra envoyer « n » valeurs aléatoires comprises entre 0 et 9 au processus fils a travers un tube. La valeur de « n » est comprise entre 5 et 20.
- Le processus fils devra lire les toutes les valeurs qui lui sont transmises, calculer leur somme et quitter.
- Le processus parent doit se terminer lorsque le processus fils a fini sa tache. <br>
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    srand(time(NULL));
    int p[2], inbuf[sizeof(int)], randInt; // inbuf = variable par laquelle les infos passent. Le p c'est le contenu (0 = lecture, 1 = ecriture)
   
   
    if (pipe(p) < 0) {
        perror("error when creating pipe.");
        return 1;
    }

    int nbInts = (rand() % 16) + 5; // nombres de valeurs créées entre 5 et 20

    int pid = fork();

    if(pid < 0) {
        perror("error when creating fork.");
        return 1;
    } 
    
    
    else if(pid > 0) {
        // parent
        sleep(1);
        for(int i=0;i<nbInts;i++) {
            randInt = rand() % 10; // valeur créée entre 0 et 9
            printf("nb %d from parent : %d\n", i+1, randInt);
            write(p[1], &randInt, sizeof(int)); // p[1] = écriture
        }
        wait(NULL); // attend la fin du process fils.
    } 
    
    
    else {
        // enfant
        int sum = 0;
        int nbytes;
        int count = 0;

        while ((nbytes = read(p[0], inbuf, sizeof(int))) > 0) { // inbuf = variable par laquelle les infos passent // p[0] = lecture
            printf("received from child : %d\n", *inbuf);
            sum += *inbuf;
            count++;
            if(count >= nbInts) { // quand tu atteint le nb de valeurs t'arrètes.
                break;
            }
        }
        if (nbytes != 0) {
            exit(2);
        }
        printf("\nres from child : %d\n", sum);
        
    }

    return 0;
}
```
<br>

**[2B] Quelle est le rôle/intérêt de la commande dup2?**<br>
Son role est qu'il duplique un descripteur de fichier pour qu'un autre processus puisse y avoir accès. Son intérêt est de rediriger facilement l’entrée ou la sortie d’un programme. 
<br>

**[2C] A quoi servent les commandes popen et pclose?**<br>
La commande "popen" sert à lancer une commande externe et à créer un flux pour lire sa sortie ou lui écrire des données.
La commande "pclose" sert à fermer ce flux et attendre la fin du processus lancé par popen.
<br>
<br><br>

**[3A] Vous devez écrire deux programme sans nécessairement utiliser fork**<br>
- Le premier programme appelé send_rand qui écrit « n » valeurs aléatoires dans un tube nommé. Ce programme prendra en argument le nom du tube, et l'option -n qui sera suivi du nombre de valeurs aléatoires à envoyer dans le tube. Ce programme devra créer le tube dans le répertoire /tmp si celui-ci n'existe pas déjà. Exemple de syntaxe : send_rand mypipe -n 30 qui enverra 30 valeurs aléatoires dans le tube nommé « mypipe »
- Le second programme appelé get_rand lira toutes les valeurs présentes dans le tube, et affichera la moyenne des valeurs avant de quitter. <br>

<br><br>

**[4A] En utilisant les sockets UNIX, vous devez écrire un programme client et un serveur. Le client enverra une valeur numérique unique au serveur via les sockets UNIX. Ce client sera exécuté simultanément 2 fois. Chacun des processus contactera le même serveur et chacun devra envoyer une valeur aléatoire au serveur via les sockets. Le processus serveur attendra d’avoir deux valeurs numériques. Il devra alors calculer la somme des deux valeurs, l’afficher**<br>

code client :
```c
#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>

int main(int argc, char const* argv[])
{
    int sockD = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port
        = htons(9001); // use some unused port number
    servAddr.sin_addr.s_addr = INADDR_ANY;

    int connectStatus
        = connect(sockD, (struct sockaddr*)&servAddr,
                  sizeof(servAddr));

    if (connectStatus == -1) {
        printf("Error...\n");
    }

    else {
        int nb = atoi(argv[1]);

        send(sockD, &nb, sizeof(nb), 0); //&nb : vas chercher les bits qu'il y a a l'adresse mémoire de la variable
    }

    return 0;
}
```

code serveur :
```c
#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{

    // create server socket similar to what was done in
    // client program
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);

    // string store data to send to client


    // define server address
    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to the specified IP and port
    bind(servSockD, (struct sockaddr*)&servAddr,
         sizeof(servAddr));

    // listen for connections
    listen(servSockD, 1);

    // integer to hold client socket.
    int clientSocket1 = accept(servSockD, NULL, NULL);
    int clientSocket2 = accept(servSockD, NULL, NULL);

    int nb1, nb2;

    // receive messages to client socket
    read(clientSocket1, &nb1, 255);
    read(clientSocket2, &nb2, 255);

    printf("Somme: %d\n", nb1+nb2);

    return 0;
}
```