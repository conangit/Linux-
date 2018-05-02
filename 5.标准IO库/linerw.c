#include <stdio.h>

// 系统似乎忽略了此值的大小？
#define MAXSIZE 10

int main(void)
{
    char buf[MAXSIZE];

    while (fgets(buf, MAXSIZE, stdin) != NULL)
    {
        if (fputs(buf, stdout) == EOF)
            printf("output error\n");
    }

    if (ferror(stdin))
        printf("input error\n");

    return 0;
}
