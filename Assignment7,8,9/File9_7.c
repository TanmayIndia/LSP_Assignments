#include <stdio.h>
#include <stdlib.h>


int main()
{
char *home,*userName;

home=getenv("HOME");
userName=getenv("USERNAME");

printf("Home Directory: User Name\n");
printf("%s : %s\n",home,userName);

return 0;
}
