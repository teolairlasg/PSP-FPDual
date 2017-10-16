#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	
	pid_t pid1, pid2;
	printf("hola\n");
	pid1=fork();

	if(pid1 == 0){ //Código del hijo
		sleep(1);
		printf("hola soy el hijo. Mi padre es: %d\n",getppid());
	}
	else{ //Código del padre
		pid2=fork();
		if (pid2 == 0){ //Código del 2º Hijo
			sleep(1);
			printf("hola soy el 2º hijo. Mi padre es: %d\n",getppid());
		}else{
			printf("hola soy el padre, mi pid es: %d\n",getpid());
			printf("he creado un proceso hijo cuyo pid es: %d\n",pid1);
			printf("he creado un proceso hijo cuyo pid es: %d\n",pid2);

			printf("El proceso %d terminó\n", wait(NULL));
			printf("El proceso %d terminó\n", wait(NULL));
		}
	}
	return 0;
}
