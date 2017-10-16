#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int tub[2];
	int i, nhijos=10000;
	if(pipe(tub)==-1){fprintf(stderr, "Error en el pipe\n");}
	for(i=0;i<nhijos;i++){
		if(fork()==0){
			pid_t pid=getpid();
			write(tub[1],&pid,sizeof(pid_t));
			return 0;
		}
	}
	for(i=0;i<nhijos;i++){
		wait(NULL);
		pid_t hijo;
		read(tub[0],&hijo,sizeof(pid_t));
		fprintf(stdout, "El hijo %d ha acabado\n", hijo);
	}
	close(tub[0]);
	close(tub[1]);
	return 0;
}