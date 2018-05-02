#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
    {
        printf("usage:%s directory_name\n", argv[0]);
        return 0;
    }

    if ((dp = opendir(argv[1])) == NULL)
    {
        printf("can't open %s\n", argv[1]);
        return 0;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        printf("name:%s\n", dirp->d_name);
        // printf("type:%d\n", dirp->d_type);
    }

    closedir(dp);

    return 0;
}

