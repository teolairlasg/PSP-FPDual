#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("PID: %d\n", getpid());
	while(1);
	return 0;
}