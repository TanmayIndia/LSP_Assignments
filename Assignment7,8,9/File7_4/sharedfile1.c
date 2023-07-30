#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include "sharedfile.h"

int Loader()
{
void *ptr=NULL;
void (*fptr)();

ptr=dlopen("//home/tanmay27/Desktop/Assignments/Assignment7/File7_4/library.so",RTLD_LAZY);

if(ptr==NULL)
{
	printf("Unable to load library.\n");
}

fptr=dlsym(ptr,"Factorial");

if(fptr==NULL)
{
	printf("Unable to load function.\n");
}

fptr();

return 0;
}

