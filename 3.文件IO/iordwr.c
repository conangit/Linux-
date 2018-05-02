#include <stdio.h>
#include <unistd.h>


#define BUFFSIZE 4096

int main(void)
{
    ssize_t n;
    char buf[BUFFSIZE] = {0};

    if ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
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
    