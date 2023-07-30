#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr= NULL;
    void (*fptr)();
    ptr = dlopen("/home/tanmay27/Desktop/Assignments/Assignment7/File7_4/library.so",RTLD_LAZY);//RTLD_LAZY
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
   fptr = dlsym(ptr,"Loader");
   
    if(fptr == NULL)
    {    
        printf("Unable to load the address of function\n");
        return -1;
    }
    fptr();
}

// gcc -rdynamic -o Myexe client.c
// gcc -ldl -o Myexe client.c
// ./Myexe
