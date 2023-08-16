#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>

#define SIZE 512

struct my_msg_st
{
long int msgType;
char msg[SIZE];
};

int main()
{
int Ret=0,Flag=1;
key_t Key=1234;
long int Type=1;
char Buffer[SIZE]={'\0'};
struct my_msg_st Mymsg;

Mymsg.msgType=Type;

Ret=msgget(Key,IPC_CREAT | 0666);


if(Ret==-1)
{
printf("Unable to create message queue.\n");
return -1;
}


while(Flag)
{
printf("Please enter message:\n");
fgets(Buffer,SIZE,stdin);

strcpy(Mymsg.msg,Buffer);

if(msgsnd(Ret, &Mymsg, SIZE ,0) == -1)
{
printf("Error while sending message.\n");
return -1;
}

if(strncmp(Buffer, "end",3)==0)
{
Flag=0;
}
}

return 0;
}

