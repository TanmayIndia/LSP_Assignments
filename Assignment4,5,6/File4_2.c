#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{

int dp = 0;
char DirName[20];

printf("Enter directory name\n");
scanf("%s", DirName);

dp=mkdir(DirName,0777);
if(dp==-1)
{
printf("Unable to create directory\n");
}
else
{
printf("Directory is succesfully created.\n");
}


close(dp);
return 0;
}
