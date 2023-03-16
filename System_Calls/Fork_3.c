
/* 
	Q1. Write a C program using fork() system call to print the given output : 2 4 1 4 1 4 3 4 
	
	Name : Clement Mathew
	Roll No : 29
*/

#include <stdio.h>
#include <unistd.h>
  
int main()
{
    if (fork()) 
    {
        if (!fork()) 
        {
            fork();
            printf("1 ");
        }
        else 
        {
            printf("2 ");
        }
    }
    else 
    {
        printf("3 ");
    }
    printf("4 ");
    return 0;
}
