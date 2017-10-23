#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(argc != 2){
		fprintf(stderr, "Error, el uso es\n\t%s (1 o 2)\n",argv[0]);
		exit(-1);
	}
	int n_programa = atoi(argv[1]);

	char tuberia_salida[20];
	char tuberia_entrada[20];

	if(n_programa == 1){
		strcpy(tuberia_salida,"./TUB1");
		strcpy(tuberia_entrada,"./TUB2");
	}else if(n_programa == 2){
		strcpy(tuberia_salida,"./TUB2");
		strcpy(tuberia_entrada,"./TUB1");
	}else{
		fprintf(stderr, "Error, el uso es\n\t%s (1 o 2)\n",argv[0]);
		fprintf(stderr, "El parámetro tiene que ser un 1 o un 2\n");
		exit(-1);	
	}

	pid_t pid;
	int tub;
	char mensaje[100];
	pid = fork();

	switch (pid){
		case -1:
			fprintf(stderr, "Error en la creación del hijo\n");
			exit(-1);
			break;
		case 0: //Hijo, lee del teclado y escribe en tubería
			
			tub = open(tuberia_entrada,O_WRONLY);
			if (tub == -1){
				fprintf(stderr, "Error abriendo %s\n", tuberia_entrada);
				exit(-1);
			}
			while(strcmp(mensaje,"/exit") != 0 ){
				char bluf;
				scanf("%[^\n]%c",mensaje,&bluf);
				write(tub,mensaje,sizeof(mensaje));
			}
			close(tub);
			break;

		default: //Padre, lee de la tubería e imprime lo leído.
			tub = open(tuberia_salida,O_RDONLY);
			if (tub == -1){
				fprintf(stderr, "Error abriendo %s\n", tuberia_salida);
				exit(-1);
			}
			while(strcmp(mensaje,"/exit") != 0 ){
				read(tub,mensaje,sizeof(mensaje));
				fprintf(stdout, "%s\n", mensaje);
			}
			close(tub);
			break;
	}
	return 0;
}