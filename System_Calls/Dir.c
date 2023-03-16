
//opendir , exit , readdir , closedir are used

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

struct dirent *rd;

int main()
{
	char dir[100];
	DIR *ds;
	printf("Enter the directory name : ");
	scanf("%s",dir);
	if((ds = opendir(dir)) == NULL)
	{
		printf("The given directory does not exist");
		exit(1);
	}
	while(rd = readdir(ds))
	{
		printf("%s",rd->d_name);
	}
	closedir(ds);
}
