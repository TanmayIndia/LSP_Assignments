	#include<stdio.h>
	#include<unistd.h>
	#include<sys/mman.h>
	#include<sys/types.h>
	#include<sys/stat.h>
	#include<fcntl.h>

	int main(int argc, char * argv[])
	{
	int Ret=0,Fd=0,iCnt=0;
	char *map=NULL;
	struct stat Fobj;

	if(argc<2)
	{
	printf("Please enter sufficient arguments\n");
	return -1;
	}

	Fd=open(argv[1],O_RDONLY);

	if(Fd==-1)
	{
	printf("Not able to open file: %s",argv[1]);
	return -1;
	}

	fstat(Fd,&Fobj);

	if(!S_ISREG(Fobj.st_mode))
	{
	printf("This is not a regular file.\n");
	return -1;
	}

	map=mmap(0,Fobj.st_size,PROT_READ,MAP_SHARED,Fd,0);

	for(iCnt=0;iCnt<Fobj.st_size;iCnt++)
	{
	printf("%c",map[iCnt]);
	}
	
	if(munmap(map,Fobj.st_size)==-1)
	{
	printf("Error while un-mapping memory.\n");
	return -1;
	}

	return 0;
	}
