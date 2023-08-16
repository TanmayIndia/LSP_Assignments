#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
int Fd=0;
char *path= "/tmp/myfifo";
char msg[30]= "\nHappy Indipendance day.\n";

Fd=mkfifo(path,0666);

if(Fd==-1)
{
printf("Unable to create named pipe.\n");
return -1;
}

Fd=open(path,O_WRONLY);

printf("Server is writing into pipe.\n");
write(Fd,msg,strlen(msg));
printf("Data is successfully written into pipe.\n");
close(Fd);
}
