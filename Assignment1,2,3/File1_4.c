#include<stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{

struct stat statBuf;
 
if(argc!=2)
{
		printf("Insufficient arguments\n");
		return -1;
}

stat(argv[1],&statBuf);

if (stat(argv[1], &statBuf) == -1) {
	printf("Error\n");
        return -1;
}
else
{
printf("Mode = %o", statBuf.st_mode);
printf("Inode Number= %li", statBuf.st_ino);
//printf("File Type = %F", statBuf.st_type);
printf("File Size in bytes = %ld", statBuf.st_size);
printf("User name = %U", statBuf.st_uid);
printf("Last status change:       %s", ctime(&statBuf.st_ctime));
printf("Last file access:         %s", ctime(&statBuf.st_atime));
printf("Last file modification:   %s", ctime(&statBuf.st_mtime));
}

return 0;
}
