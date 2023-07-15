#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
int fd = 0; 
char Buffer[20];

if(argc!=2)
{
	printf("Insufficient arguments\n");
	return -1;
}

fd = open(argv[1],O_WRONLY);

if(fd==-1)
{
printf("Unable to open the file\n");
return -1;	
}

printf("Please enter a string\n");
scanf("%[^\n]", &Buffer); 

write(fd,Buffer,sizeof(Buffer));
close(fd);
return 0;
}

