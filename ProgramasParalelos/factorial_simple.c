#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if(argc != 2){
		fprintf(stderr, "Error en el uso del programa\n");
		fprintf(stderr, "Uso:\n\t %s número\n\n", argv[0]);
		exit(-1);
	}
	int objetivo = atoi(argv[1]);
	long int resultado = 1;
	while (objetivo >= 1){
		resultado*=objetivo;
		objetivo--;
	}
	fprintf(stdout,"El factorial del número %s es %ld\n\n", argv[1], resultado);

	return 0;
}