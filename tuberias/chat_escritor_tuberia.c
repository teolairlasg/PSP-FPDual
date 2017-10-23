#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int tub;

	tub = open("./TUBERIA",O_WRONLY);

	if (tub == -1){
		fprintf(stderr, "Error en la creación de la tubería\n");
	}else{
		char mensaje[100];
		while(1){
			scanf("%s.",mensaje);
			write(tub,mensaje,sizeof(mensaje));
		}
	}


	return 0;
}