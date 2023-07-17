#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct student
{
int Rollno;
char Sname[20];
float Marks;
int Age;
};

int main(int argc,char * argv[])
{
struct student sobj;
int fd=0;
char fname[20];

sobj.Rollno=11;
sobj.Marks=89.99f;
sobj.Age=25;
strcpy(sobj.Sname,"Rahul");

printf("Enter the file name\n");
scanf("%s",fname);

fd=creat(fname,0777);

write(fd,&sobj,sizeof(sobj));

return 0;
}
