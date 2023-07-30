#include<stdio.h>
#include<string.h>
#include "sharedfile.h"

int main(int agrc, char *argv[])
{
    char Fname[30];
    strcpy(Fname,argv[1]);
    DisplayInfo(Fname);
    return 0;
}

// gcc client.c -o Myexe

// gcc -static client.c -o Myexe sharedfile.a

// ./Myexe
