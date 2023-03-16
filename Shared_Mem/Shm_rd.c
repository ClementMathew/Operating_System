#include<sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main()
{
 	key_t key=ftok(id,29);
 	int shmid =shmget(key,1024,IPC_CREAT);
         char *str=(char *)shmat(shmid,(void*)0,0);
	printf("\nreaded data is : %s",str);
        shmdt(str);
}
