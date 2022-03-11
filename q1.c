//1.Write a program using file operations that demonstrates copying of data from input file and write
//into output file, untill reaches end of file data.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main()
{
	
	char read_buff[100];
	
	int fd1 = open("inputfile.txt", O_RDONLY, 777);    
	int fd2 = open("output.txt",O_CREAT | O_RDWR, 777);  

	int len;
	
	read(fd1, read_buff, 200);   
	printf("data read from file = %s\n",read_buff);


	len = write(fd2, read_buff, 200);    
	printf("data = %d \n", len);
	
	
	
	close(fd2);
	close(fd1);
	
}