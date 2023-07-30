#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr= NULL;
    void (*fptr)();
    void (*fptr1)();
   
    ptr = dlopen("/home/tanmay27/Desktop/Assignments/dynamic2/library.so",RTLD_LAZY);//RTLD_LAZY
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

   fptr = dlsym(ptr,"Prime");
   fptr1 = dlsym(ptr,"Perfect");
   
    if(fptr == NULL)
    {    
        printf("Unable to load the address of function\n");
        return -1;
    }
    fptr();
    fptr1();
    
    return 0;
}

// gcc -rdynamic -o Myexe client.c
// gcc -ldl -o Myexe client.c

// ./Myexe
