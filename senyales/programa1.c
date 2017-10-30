#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void gestor_senyal(int);

void gestor_senyal(int senyal){
	if(senyal == SIGUSR1){

	printf("hola mundo\n");

	}else if (senyal == SIGUSR2){
		printf("adios mundo\n");
		kill(getpid(),SIGINT);
	}
}

int main(int argc, char const *argv[])
{
	printf("%d\n", getpid());
	signal(SIGUSR1, gestor_senyal);
	signal(SIGUSR2, gestor_senyal);
	int i=0;
	while(1){
		sleep(1);
		printf("%d\n", i++);
	}
	return 0;
}