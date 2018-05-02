#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    fprintf(stderr, "EBUSY: %s\n", strerror(EBUSY));

    fprintf(stderr, "ENOENT: %s\n", strerror(ENOENT));
    errno = ENOENT;
    perror(argv[0]);
    
    return 0;
}


