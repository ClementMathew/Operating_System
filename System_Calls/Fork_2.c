/*
	Q3: How many processes will be there? main() { for(i=0;i<10; i++) { if(i%2==0) { fork(); } } }
*/

#include <stdio.h>
#include <unistd.h>

int main() 
{ 
	int i;
	for(i=0;i<10; i++) 
	{ 
		if(i%2==0) 
		{ 
			fork(); 
		} 
	}
	printf("Hello\t");
}

/* Since 5 even numbers in i=0 to 10 (not including 10) 5 forks are called that is 2^5 processes
   ie 32 processes */
