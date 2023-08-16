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
int id=0,Flag=1;
key_t Key=1234;
long int Type=1;
char Buffer[SIZE]={'\0'};
struct my_msg_st Mymsg;

Mymsg.msgType=Type;

id=msgget(Key,IPC_CREAT | 0666);


if(id==-1)
{
printf("Unable to create message queue.\n");
return -1;
}

while(Flag)
{
if(msgrcv(id, &Mymsg, SIZE, Mymsg.msgType, 0)==-1)
{
printf("Error while receiving msg\n");
return -1;
}

printf("Message received: %s", Mymsg.msg);

  if(strncmp(Mymsg.msg, "end",3)==0)
  {
	Flag=0;
  }
}
return 0;
}

