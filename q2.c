//2.Write a program that demonstrates repositioning of file offset using SEEK_SET, SEEK_END
//and SEEK_END.

#include<stdio.h>
#include<fcntl.h>

int main()
{

    int fd1, fd2, fd3,x,current;
    int len;

    char write_buff[] = "Linux internal tool assignment question 2\n";

    fd1 = open("q2write.txt", O_CREAT | O_RDWR, 777);
    len=write(fd1 , write_buff, sizeof(write_buff));
    printf("fd1 is: %d and data of size: %d\n",fd1,len);
    char read_buff[len];
    lseek(fd1, 0, SEEK_SET);


    read(fd1, read_buff, len);
    printf("Data: %s",read_buff);
    char buffer[]="Question 2";
    current = lseek(fd1, 0, SEEK_CUR);
    printf("Current position: %d\n",current);

    fd2 = open("write.txt", O_RDWR, 777);
    lseek(fd2, 0, SEEK_END);
    x = write(fd2 , buffer, sizeof(buffer));
    printf("fd2 is: %d and data of size: %d\n",fd2,x);
    lseek(fd2, len, SEEK_SET);
    
    char buf1[x];
    read(fd2, buf1, x);
    printf("Data: %s",buf1);

    close(fd1);
    close(fd2);

    return 0;
}