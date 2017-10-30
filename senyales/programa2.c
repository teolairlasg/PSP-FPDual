#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void gestor(int senyal){

	int j = 40;
	while(j>0){
		printf("gestor: %d\n", j--);
	}
}


int main(int argc, char const *argv[])
{
	int i=0;
	signal(SIGUSR1, gestor);
	while(i<100){
		if (i == 50)
		{
			kill(getpid(),SIGUSR1);
		}
		printf("%d\n", i++);
	}
	return 0;
}