#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<stdio.h>

int main()
{
	/* the size (in bytes) of shared memory object */
	const int SIZE=4096;
	
	/* name of the shared memory object */
	const char *name = "OS";
	
	int count,i;
	char s = ' ';
	printf("Enter number of strings : ");
	scanf("%d", &count);
	
	char words[count][20];
 
	for(i=0; i<count; i++) 
	{
		printf("Enter word %d : ", i+1);
		scanf("%s", words[i]);
		strncat(words[i], &s, 1);
	}
	
	/* shared memory file descriptor */
	int shm_fd;
	
	/* pointer to shared memory obect */
	void *ptr;
	
	/* create the shared memory object */
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	
	/* configure the size of the shared memory object */
	ftruncate(shm_fd, SIZE);
	
	/* memory map the shared memory object */
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	
	for(i=0; i<count; i++) 
	{
		sprintf(ptr, "%s",words[i]);
		int length = strlen(words[i]);
		ptr += (length);			
	}
	return 0;
}

