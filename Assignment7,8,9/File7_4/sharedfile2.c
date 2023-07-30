#include<stdio.h>
#include<stdlib.h>
#include "sharedfile.h"

void Factorial()
{
int Num=0;
long Fact=1;
int i=0;
printf("Please enter a number.\n");
scanf("%d",&Num);
if(Num<0)
{
Num = -Num;
}
for(i=Num; i>0; i--)
{
	Fact=Fact*i;
}
printf("The factorial of the given number is: %ld.\n",Fact);
}
