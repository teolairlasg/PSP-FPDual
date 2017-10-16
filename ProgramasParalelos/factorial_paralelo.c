#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	if(argc != 2){
		fprintf(stderr, "Error en el uso del programa\n");
		fprintf(stderr, "Uso:\n\t %s número\n\n", argv[0]);
		exit(-1);
	}
	long int resultado = 1;
	int objetivo = atoi(argv[1]);
	int objetivo_hijo = objetivo/2;
	pid_t pid;
	FILE* fichero;

	pid = fork();

	switch (pid){

		case -1:
			fprintf(stderr, "Error en la creación del proceso hijo\n");
			exit(-1);
		case 0: //Hijo
			while (objetivo_hijo >= 1){
				resultado*=objetivo_hijo;
				objetivo_hijo--;
			}
			fprintf(stdout, "resultado hijo: %ld\n", resultado);
			fichero = fopen("/tmp/factorial.txt","w+");
			fprintf(fichero, "%ld\n",resultado);
			fclose(fichero);
			break;
		default:
			while (objetivo > objetivo_hijo){
				resultado*=objetivo;
				objetivo--;
			}
			fprintf(stdout, "resultado padre: %ld\n", resultado);
			wait(NULL);
			long int resultado_hijo;
			fichero = fopen("/tmp/factorial.txt","r");
			fscanf(fichero,"%ld",&resultado_hijo);
			fclose(fichero);
			fprintf(stdout, "resultado final: %ld\n", resultado*resultado_hijo);

	}
	return 0;
}