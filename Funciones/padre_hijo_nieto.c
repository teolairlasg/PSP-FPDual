#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	pid_t pid;
	printf("Comenzando...\n");

	if (pid = fork() == -1){
		exit(-1);
	}

	if (pid == 0){ //Soy el hijo
		if (pid = fork() == -1){
			exit(-1);
		}
		if (pid == 0){//Soy el nieto
			fprintf(stdout, "Soy el nieto. \n");
			fprintf(stdout, "PID: %d PPID: %d \n",getpid(),getppid() );
		}else{ //Vuelvo a ser el hijo
			fprintf(stdout, "Soy el hijo. \n");
			sleep(1);
			fprintf(stdout, "PID: %d PPID: %d \n",getpid(),getppid() );
			fprintf(stdout, "Mi hijo es: %d\n", pid);
			fprintf(stdout,"Mi hijo %d terminó.\n",wait(NULL));
		}
	}else{ //Soy el padre
		fprintf(stdout, "Soy el padre. \n");
		fprintf(stdout, "PID: %d PPID: %d \n",getpid(),getppid() );
		fprintf(stdout, "Mi hijo es: %d\n", pid);
		fprintf(stdout,"Mi hijo %d terminó.\n",wait(NULL));
	}
	fprintf(stdout, "PID: %d terminando...\n", getpid());
	return 0;
}