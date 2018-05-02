#include <stdio.h>
#include <unistd.h>


int main(int argc, char * argv[])
{
    int ch;

    // 记录optind opterr初始值
    printf("optind:%d, opterr:%d\n", optind, opterr);
    printf("--------------------\n");

    // 一个冒号表示这个选项后面必须带有参数,这个参数可以和选项连在一起写,也可以用空格隔开
    // 两个冒号的就表示这个选项的参数是可选的,即可以有参数,也可以没有参数,但参数与选项之间不能有空格
    while( (ch = getopt(argc, argv, "ab:c:de::")) != -1 )
    {
        printf("after scan optind:%d\n", optind);

        switch(ch)
        {
            case 'a':
                printf("have option: -a\n");
                break;

            case 'b':
                printf("have option: -b\n");
                printf("the arguement of -b is: %s\n", optarg);
                break;
                    
            case 'c':
                printf("have option: -c\n");
                printf("the arguement of -c is: %s\n", optarg);
                break;

            case 'd':
                printf("have option: -d\n");
                break;

            case 'e':
                printf("have option: -e\n");
                printf("the arguement of -e is: %s\n", optarg);
                break;

            case '?':
                printf("unknown option: %c\n", (char)optopt);
                break;
        }
    }


    printf("test over\n");

    return 0;
}


/*
 *推荐阅读
 *http://blog.csdn.net/huangxiaohu_coder/article/details/7475156 
 */
