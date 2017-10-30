#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void gestor_senyal(int);
void gestor_senyal2(int);

void gestor_senyal(int senyal){
	printf("hola mundo\n");
	signal(SIGINT, gestor_senyal2);
}

void gestor_senyal2(int senyal){
	printf("adios mundo\n");
	signal(SIGINT, gestor_senyal);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", getpid());
	signal(SIGINT, gestor_senyal);
	int i=0;
	while(1){
		sleep(1);
		printf("%d\n", i++);
	}
	return 0;
}