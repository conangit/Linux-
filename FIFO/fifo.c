/*
 * fifo.c
 *
 * Created on: 2017年7月21日
 * Author: think
 */

#include "fifo.h"

static FIFO mFIFO;

void fifo_init(void)
{
    unsigned long i;

    for(i = 0; i < FIFO_SIZE; i++)
    {
        mFIFO.Buf[i] = 0;
    }
    mFIFO.Read = 0;
    mFIFO.Write = 0;
    mFIFO.ReadCnt = 0;              /* FIFO初始可读数据为0 */
    mFIFO.WriteCnt = FIFO_SIZE;     /* FIFO初始可写数据为FIFO_SIZE */
}


void fifo_write(data_type data)
{
    unsigned long wr_cnt = mFIFO.WriteCnt;

    if(wr_cnt == 0)
    {
        FIFO_PRINTF("FIFO is full, do not allow to write.\n");
        return;
    }
    else
    {
        mFIFO.Buf[mFIFO.Write] = data;

        if(++mFIFO.Write >= FIFO_SIZE)
        {
            mFIFO.Write = 0;
        }

        mFIFO.WriteCnt--;
        mFIFO.ReadCnt++;
    }
}


data_type fifo_read(void)
{
    unsigned long rd_cnt = mFIFO.ReadCnt;
    data_type rd_val;

    if(rd_cnt == 0)
    {
        FIFO_PRINTF("FIFO is empty, do not allow to read.\n");
        return 0;
    }
    else
    {
        rd_val = mFIFO.Buf[mFIFO.Read];

        if(++mFIFO.Read >= FIFO_SIZE)
        {
            mFIFO.Read = 0;
        }

        mFIFO.ReadCnt--;
        mFIFO.WriteCnt++;

        return rd_val;
    }
}

