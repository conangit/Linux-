#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

static void * thr_fn1(void *arg)
{
    printf("thread 1 returning\n");

    return ((void*)1);
}

static void * thr_fn2(void *arg)
{
    printf("thread 2 exiting\n");

    pthread_exit((void*)2);
}

int main(void)
{
    int err;
    pthread_t tid1;
    pthread_t tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if(err != 0)
    {
        printf("can't create thread 1\n");
    }

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if(err != 0)
    {
        printf("can't create thread 2\n");
    }

    /* 调用线程将阻塞 直到线程返回、取消或调用pthread_exit */
    // int pthread_join(pthread_t thread, void **retval);
    err = pthread_join(tid1, &tret);
    if(err != 0)
    {
        printf("can't join with thread 1\n");
    }
    printf("thread 1 exit code: %ld\n", (long)tret);

    err = pthread_join(tid2, &tret);
    if(err != 0)
    {
        printf("can't join with thread 2\n");
    }
    printf("thread 2 exit code: %ld\n", (long)tret);

    //sleep(1);
    exit(0);    
}



