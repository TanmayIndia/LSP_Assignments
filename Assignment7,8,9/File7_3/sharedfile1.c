#include<stdio.h>
#include<stdlib.h>
#include "sharedfile1.h"

void Prime()
{
int Num=0;
int i=0;
int flag=1;
printf("Please enter a number to check.\n");
scanf("%d",&Num);
if(Num<0 || Num == 0 || Num== 1)
{
printf("Please enter valid number.\n");
exit(-1);
}
if(Num==2)
{
printf("It is a prime number.\n");
}
for(i=2; i< Num; i++)
{
if(Num%i==0)
{
flag=0;
break;
}
}
if(flag)
{
printf("The given number is Prime number.\n");
}
else
{
printf("The given number is Not a prime number.\n");
}
}

