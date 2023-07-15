#include<stdio.h>
#include<fcntl.h>

int main()
{
int fd=0;
char fname[20];

printf("Please enter the file name\n");

scanf("%s",fname);

fd=open(fname,O_RDONLY);

if(fd==-1)
{
	printf("Unable to open specified file\n");
	return -1;
}
else
printf("The file is opened with fd: %d\n",fd);

close(fd);

return 0;
}
