/*
 * file: fifo.h
 * Created on: 2017年7月21日
 * Author: lihong@gzseeing.com
 */

#ifndef SRC_FIFO_H_
#define SRC_FIFO_H_

#include <stdio.h>

/* FIFO 调试信息 */
// #define FIFO_DEBUG

#ifdef FIFO_DEBUG
#define FIFO_PRINTF(format, ...) printf(format, ##__VA_ARGS__)
#else
#define FIFO_PRINTF(format, ...) do{}while(0)
#endif

/* FIFO 的深度 */

#define FIFO_SIZE 4096

/* FIFO 存储的数据类型 */

typedef char data_type;

typedef struct {
    data_type Buf[FIFO_SIZE];

    volatile unsigned long Write;
    volatile unsigned long Read;

    volatile unsigned long WriteCnt;
    volatile unsigned long ReadCnt;
}FIFO;

void fifo_init(void);
void fifo_write(data_type data);
data_type fifo_read(void);

#endif /* SRC_FIFO_H_ */

