#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>


void gestor(int senyal){
	fprintf(stdout, "Alarma disparada!!!\n");
	usleep(500000);
	fprintf(stdout, "Alarma disparada!!!\n");
	sleep(1);
	fprintf(stdout, "Alarma disparada!!!\n");

}

int main(int argc, char const *argv[])
{
	
	signal(SIGALRM,gestor);
	alarm(10);

	while(1);

	return 0;
}