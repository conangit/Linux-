#include <stdio.h>

main()
{
    printf("hello world\n");
}

/*
编译方式：
gcc hello.c
gcc -std=c99 hello.c

查看警告信息
gcc -std=c99 -Wall hello.c


查看main()函数返回终止码
$ echo $?
 */

