#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    ssize_t cnt;
    char buf[2048] = {0x11, 0x22, 0x33};

    fd = open("tmpfile", O_RDWR | O_CREAT);
    if (fd < 0)
    {
        printf("open file error!\n");
        return -1;
    }

     if (write(fd, buf, 2048) != 2048)
     {
        printf("write file error!\n");
        close(fd);
        return -1;
     }

#if 1
     if (unlink("tmpfile") < 0)
     {
        printf("unlink file error!\n");
        close(fd);
        return -1;
     }
     else
     {
        printf("unlink file success!\n");
     }

     sleep(15);
     printf("done\n");
#endif

     // 关闭该文件 文件内容才被删除
     close(fd);


    return 0;
}