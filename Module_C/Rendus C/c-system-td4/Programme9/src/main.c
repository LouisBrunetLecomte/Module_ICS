#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>   // nécessaire pour sprintf

// variable globale
int global_var = 100;  // variable globale initialisée

// fonction appelée à la fin du processus
void say_bye(void) {
    printf("Bye\n");
}

int main() {
    int n;
    pid_t p;

    // enregistre say_bye pour le père
    atexit(say_bye);

    printf("Combien de fils (moins que 10) ? ");
    scanf("%d", &n);

    while (n >= 10 || n <= 0) {
        printf("Non... reessaye (n<10) : ");
        scanf("%d", &n);
    }

    srand(time(NULL));

    for (int i = 1; i <= n; i++) {
        p = fork();

        if (p == -1) {
            perror("fork");
            return 1;
        }

        if (p == 0) {  // code du fils
            // enregistre say_bye pour le fils
            atexit(say_bye);

            int t = rand() % 111 + 10;
            sleep(t);  // attente aléatoire

            printf("Je suis le fils numero %d, PID %d, père %d\n", i, getpid(), getppid());
            printf("Avant modification, global_var = %d\n", global_var);

            int modif = rand() % 50;  // valeur aléatoire
            global_var += modif;

            printf("Après modification par le fils %d, global_var = %d\n", i, global_var);

            // -------------------------------
            // EXÉCUTION DE RANDOMGENERATOR
            // -------------------------------
            int nb = 10 + rand() % 11; // nombre aléatoire entre 10 et 20
            char str_nb[4];
            sprintf(str_nb, "%d", nb);

            execl("../ICS_RandomGeneratorV2/output/main", "main", "-n", str_nb, NULL);

            // Si execl échoue
            perror("execl échoué");
            exit(1);
        }
    }

    // le père attend tous les fils
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("fini (père)\n");
    return 0; // say_bye du père sera appelé ici
}
