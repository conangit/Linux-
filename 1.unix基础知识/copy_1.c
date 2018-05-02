#include <stdio.h>
#include <unistd.h>


#define BUFSIZE 4096

int main(void)
{
    int n;
    char buf[BUFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            printf("write error\n");
        }
    }

    if (n < 0)
    {
        printf("read error\n");
    }

    return 0;

}

/*
STDIN_FILENO 0
STDOUT_FILENO 1
*/


