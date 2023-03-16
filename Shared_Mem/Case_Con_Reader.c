#include<string.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<stdio.h>
#include<ctype.h>

int main()
{
	/* the size (in bytes) of shared memory object */
	const int SIZE=4096;
	
	/* name of the shared memory object */	
	const char *name = "OS";
	
	/* shared memory file descriptor */
	int shm_fd;
	
	/* pointer to shared memory obect */	
	char *ptr;
	
	/* open the shared memory object */
	shm_fd = shm_open(name, O_RDONLY, 0666);
	
	/* memory map the shared memory object */
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	
	printf("Data read from memory: %s\n",ptr);
	while(ptr) 
	{
		char temp = *ptr;
		if((int)temp < 97) 
		{
			printf("%c",tolower(temp));
		}
		else
			printf("%c",toupper(temp));
		ptr += 1;
		if((*ptr) == '\0') break;
	}
	
	/* remove the shared memory object */
	shm_unlink(name);
	
	return 0;
}
