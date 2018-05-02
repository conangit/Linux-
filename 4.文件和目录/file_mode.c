#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;

    for (i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);
        //if (stat(argv[i], &buf) < 0)
        if (lstat(argv[i], &buf) < 0)
        {
            printf("lstat error!\n");
            continue;
        }

        if (S_ISREG(buf.st_mode))
            printf("regular\n");
        else if (S_ISDIR(buf.st_mode))
            printf("directory\n");
        else if (S_ISLNK(buf.st_mode))
            printf("symboluc link\n");
        else if (S_ISCHR(buf.st_mode))
            printf("character special\n");
        else if (S_ISBLK(buf.st_mode))
            printf("block special\n");
        else if (S_ISFIFO(buf.st_mode))
            printf("fifo\n");
        else if (S_ISSOCK(buf.st_mode))
            printf("socket\n");
        else
            printf("unknow mode\n");
    }

    return 0;
}

