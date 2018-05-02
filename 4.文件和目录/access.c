#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s <pathname>\n", argv[0]);
        return -1;
    }

    if (access(argv[1], R_OK) < 0)
    {
        printf("access error for %s\n", argv[1]);
    }
    else
    {
        printf("%s read access OK\n", argv[1]);
    }

    if (open(argv[1], O_RDONLY) < 0)
    {
        printf("open error: %s\n", argv[1]);
    }
    else
    {
        printf("%s open for reading OK\n", argv[1]);
    }

    return 0;
}

