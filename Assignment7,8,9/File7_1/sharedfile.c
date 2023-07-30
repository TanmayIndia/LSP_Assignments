#include<stdio.h>
#include "sharedfile.h"


void Addition()
{
int No1=20,No2=4,iAns=0;
iAns= No1+No2;
printf("The addition of %d and %d is: %d\n", No1,No2,iAns);
}
void Subtraction()
{
int No1=20,No2=4,iAns=0;
iAns= No1-No2;
printf("The subtraction of %d and %d is: %d\n", No1,No2,iAns);
}

void Multiplication()
{
int No1=20,No2=4,iAns=0;
iAns= No1*No2;
printf("The multiplication of %d and %d is: %d\n", No1,No2,iAns);
}

void Division()
{
int No1=20,No2=4,iAns=0;
iAns= No1/No2;
printf("The division of %d and %d is: %d\n", No1,No2,iAns);
}



// To create .o file
// gcc -c -fPIC sharedfile.c

// To create .so file
// gcc -shared -o library.so sharedfile.o
