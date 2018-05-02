#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

char buf1[] = "abcdefgh";
char buf2[] = "ABCDEFGH";

int main(void)
{
    int fd;

    if ((fd = creat("file.hole", FILE_MODE)) < 0)
    {
        printf("creat error\n");
    }

    if (write(fd, buf1, 8) != 8)
    {
        printf("buf1 write error\n");
    }

    if (lseek(fd, 16, SEEK_SET) == -1)
    {
        printf("lseek error\n");
    }

    if (write(fd, buf2, 8) != 8)
    {
        printf("buf2 write error\n");
    }

    close(fd);

    return 0;
}

/*
od -c file.hole
ls -s file.hole
*/