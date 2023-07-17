#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{

    int fd=0;
    int Ret=0;
    int Offset=0;
  
  if(argc!=2)
  {
  printf("Insufficient arguments\n");
  return -1;
  }
  printf("Please enter the offset\n");
  scanf("%d",&Offset);
  
  fd=open(argv[1],O_WRONLY);
  
  if(fd==-1)
  {
  printf("Not able to open the file\n");
  return -1;
  }
  
  Ret=ftruncate(fd,Offset);
  if(Ret!=-1)
  {
  printf("The data has been removed from the file from the offset of: %d\n",Offset);
  }
  else
  {
  printf("Not able to remove the data.\n");
  return -1;
  }

    close(fd);
    return 0;
}
