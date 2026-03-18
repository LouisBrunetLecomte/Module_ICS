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