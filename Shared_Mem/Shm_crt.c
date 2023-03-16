#include<sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main()
{
	char id[20];
	printf("Enter the id : ");
	scanf("%s",id);
 	key_t key=ftok(id,29);
 	int shmid =shmget(key,1024,IPC_CREAT);
        char *str=(char *)shmat(shmid,(void*)0,0);
	printf("\nEnter the data to write : ");
	scanf("%s",str);
	printf("%s",str);
        shmdt(str); 
}
