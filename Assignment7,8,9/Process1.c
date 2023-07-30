#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<string.h>
int main()
{
int Ret=0,fd1=0,fd2=0,iCnt=0,i=0;
char Buffer[1024];

fd1=open("Demo.txt",O_RDONLY);

if(fd1==-1)
{
printf("Unable to open file.\n");
return -1;
}

fd2=open("count.txt",O_WRONLY);

if(fd2==-1)
{
printf("Unable to open file.\n");
return -1;
}

while((Ret=read(fd1,Buffer,sizeof(Buffer))) != 0)
{
for(i=0;i<=Ret;i++)
{
if(Buffer[i] >='a' && Buffer[i] <='z')
{
	iCnt++;
}
}
}
sprintf(Buffer,"%s%d","The number of small charactes is:",iCnt);

write(fd2,Buffer,sizeof(Buffer));

close(fd1);
close(fd2);

return 0;
}
