
// fork , exit , getpid are used

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pid,pid1,pid2;
	pid = fork();
	if(pid==-1)
	{
		printf("Error in process creation");
		exit(1);
	}
	if(pid!=0)
	{
		pid1 = getpid();
		printf("\nThe parent process ID is %d",pid1);
	}
	else
	{
		pid2 = getpid();
		printf("\nThe child process ID is %d",pid2);
	}
}
