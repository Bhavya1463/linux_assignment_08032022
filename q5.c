//5.Write a program that creates a file with a 4K bytes free space.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char buf[]="\0";
int main()
{    
	int fd = creat("q5.txt", 777);
	
	if (fd < 0) 
	{
		printf("file not created");
		exit (1);
	}

	if (lseek(fd,4096, SEEK_SET) < 0)
	{
		printf("Error");
		exit(1);
	}
	if (write(fd, buf, sizeof(buf)) < 0)
	{	
        printf("Writing error");
        exit(1);
	}
return 0;
}