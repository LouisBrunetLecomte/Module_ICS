#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat/h>

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
            if(count >= nbInts) {
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
