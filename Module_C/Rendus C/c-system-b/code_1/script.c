
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

// Fonction du processus enfant
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
    int pid;
    pid = fork();
    if(pid < 0) {
        perror("error when creating fork.");
        return 1;
    }
    if(pid == 0) {
        processChild();
        exit(-1);
    }

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