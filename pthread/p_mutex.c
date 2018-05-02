#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

static pthread_mutex_t mutex;

static void * thr_fn(void * arg)
{
	static int i = 1;
	pthread_t tid;

	pthread_mutex_lock(&mutex);

	tid = pthread_self();

	printf("i = %d\n", i++);
	printf("tid = 0x%lx\n", (unsigned long)tid);

	pthread_mutex_unlock(&mutex);

	return ((void*)0);
}


int main(void)
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&tid1, NULL, thr_fn, NULL);
	pthread_create(&tid2, NULL, thr_fn, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid1, NULL);


	pthread_mutex_destroy(&mutex);

    return 0;
}

