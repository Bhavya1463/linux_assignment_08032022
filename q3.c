//Write program that returns “ls -l ” kind of structure of information from an existing file or
//opend file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{

	
	execl("/bin/ls", "ls", "-l", 0);
	printf("ls -l\n");
	
	
	return 0;
}