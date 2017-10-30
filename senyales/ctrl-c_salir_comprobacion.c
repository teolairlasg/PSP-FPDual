#include <stdio.h>
#include <sys/types.h>
#include <signal.h>


void gestor(int senyal){
	fprintf(stderr, "Has pulsado Ctrl-c, ¿seguro que quieres salir?\n");
	fprintf(stderr, "Si es así vuelve a pulsar Ctrl-c\n");
	signal(SIGINT,SIG_DFL);


}

int main(int argc, char const *argv[])
{
	
	signal(SIGINT,gestor);
	while(1);
	return 0;
}