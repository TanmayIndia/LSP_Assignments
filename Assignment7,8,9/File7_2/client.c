#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*fptr)();

    ptr = dlopen("/home/tanmay27/Desktop/Assignments/dynamic1/library.so",RTLD_LAZY);//RTLD_LAZY
  
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

   fptr = dlsym(ptr,"Compare_files");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr();
    return 0;
}

// gcc -rdynamic -o Myexe client.c
// gcc -ldl -o Myexe client.c

// ./Myexe
