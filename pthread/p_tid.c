#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

static pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

static void * thr_fn(void *arg)
{
    printids("new thread: ");

    return ((void *)0);
}

int main(void)
{
    int err;

    err = pthread_create(&ntid, NULL, thr_fn, NULL);

    printids("main thread: ");

    /* 主线程需要休眠 否则进程退出 新线程可能没机会运行 */
    sleep(1);

    exit(0);    
}


