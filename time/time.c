#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>


void test_use_timeval(void)
{
    struct timeval tv1, tv2;
    unsigned long val;

    gettimeofday(&tv1, NULL);
    sleep(1);
    gettimeofday(&tv2, NULL);

    val = (tv2.tv_sec * 1000000 + tv2.tv_usec) - (tv1.tv_sec * 1000000 + tv1.tv_usec);

    printf("%s() = %lu us\n", __func__, val);
}

void test_use_timespec(void)
{
    struct timespec ts1, ts2;
    unsigned long val;

    clock_gettime(CLOCK_REALTIME, &ts1);
    sleep(1);
    clock_gettime(CLOCK_REALTIME, &ts2);

    val = (ts2.tv_sec * 1000000000 + ts2.tv_nsec) - (ts1.tv_sec * 1000000000 + ts1.tv_nsec);

    printf("%s() = %lu ns\n", __func__, val);
}

int main(void)
{
    test_use_timeval();
    test_use_timespec();
    return 0;
}

