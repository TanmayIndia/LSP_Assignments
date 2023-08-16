#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
int Fd=0;
char *path= "/tmp/myfifo";
char buf[30]= {'\0'};

Fd=open(path,O_RDONLY);

if(Fd==-1)
{
printf("Unable to open named pipe.\n");
return -1;
}

printf("Client is reading from pipe.\n");
read(Fd,buf,30);
printf("Data Received: %s\n",buf);
close(Fd);
}
