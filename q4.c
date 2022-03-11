#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd1, fd2;
	char readbuff[100];
	int len;
	
	fd1 = creat("q4.txt", 777);			
	fd2 = open("q4data.txt", O_RDONLY, 777);		
	len = read(fd2, readbuff, 60);				
	printf("Data in data.txt -\n%s\n",readbuff);	
	
	
	len = write(fd1, readbuff, 60);		
	
	printf("Data written to new.txt\n");
	
	lseek(fd2, 0, SEEK_SET);			
	read(fd2, readbuff, 50);
	printf("data = %s\n",readbuff);
	
	close(fd2);
	close(fd1);
}