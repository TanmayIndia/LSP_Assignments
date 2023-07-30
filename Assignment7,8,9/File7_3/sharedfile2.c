#include<stdio.h>
#include<stdlib.h>
#include "sharedfile2.h"

void Perfect()
{
int Num=0;
int divisor=0,addition=0,i=0;
printf("Please enter a number to check.\n");
scanf("%d",&Num);
for(i=1; i< Num; i++)
{
if(Num%i==0)
{
addition=addition+i;
}
}
if(Num==addition)
{
printf("The given number is a perfect number.\n");
}
else
{
printf("The given number is not a perfect number.\n");
}
}

//
//
//
//
