#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    {
        printf(" cann't lseek\n");
    }
    else
    {
        printf("lseek ok\n");
    }

    return 0;
}
