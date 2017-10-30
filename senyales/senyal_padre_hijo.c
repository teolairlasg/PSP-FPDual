#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

void gestor(int senyal){
	printf("Soy el proceso: %d y he recibido una señal\n", getpid());
}

int main(int argc, char const *argv[])
{
	
	pid_t pid;

	pid = fork();

	switch(pid){
		case -1:
			perror("Error en el fork");
			exit(-1);
			break;
		case 0: //Hijo!
			signal(SIGUSR1, gestor);
			pause();
			break;
		default:
			printf("Soy el proceso: %d y voy a enviar una señal a mi hijo: %d\n", getpid(), pid);
			sleep(1);
			kill(pid,SIGUSR1);
			wait(NULL);
	}
	return 0;
}