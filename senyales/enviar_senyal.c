#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (argc != 2){		
		fprintf(stderr, "Escribe %s número_de_pid\n", argv[0] );
		exit(-1);
	}

	pid_t pid = atoi(argv[1]);
	int retorno;
	retorno = kill(pid, SIGINT);
	if(retorno == -1){
		perror("Error en el envío de la señal");
	}

	return 0;
}