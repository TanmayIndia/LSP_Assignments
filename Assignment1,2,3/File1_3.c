#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char* argv[])
{
int fd=0;
int Mode=0;
if(argc!=3)
{
	printf("Insufficient arguments\n");
	return -1;
}

if(strcmp(argv[2],"Read")==0){
Mode= O_RDONLY;
}
else if(strcmp(argv[2],"Write")==0){
Mode= O_WRONLY;
}
else{
Mode= O_RDONLY;
}

fd = access(argv[1],Mode);

if(fd ==-1)
{
printf("Access is not permitted\n");
}
else
{
printf("User can access the file\n");
}
close(fd);
return 0;
}
