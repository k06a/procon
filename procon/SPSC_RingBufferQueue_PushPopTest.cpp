#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "SPSC_RingBufferQueue_Common.h"

#include "SPSC_RingBufferQueue.h"

//////////////////////////////////////////////////////////////////////////

typedef SPSC_RingBufferQueue<int> IntQueue;

struct Context
{
    int N;
    IntQueue queue;

    Context(int N, int bufferSize)
        : N(N), queue(bufferSize)
    {
    }
};

static void producer(void * param)
{
    Context * context = (Context*)param; 

    for(int i = 0; i < context->N; i++)
        context->queue.push(new int(i));
}

static void consumer(void * param)
{
    Context * context = (Context*)param; 

    for(int i = 0; i < context->N; i++)
    {
        int * val = context->queue.pop();
        EXPECT_EQ(i, *val);
        delete val;
    }
}

//////////////////////////////////////////////////////////////////////////

TEST(SPSC_RingBufferQueue, PushPop_1K_via_100)
{
    Context * context = new Context(1000,100);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

TEST(SPSC_RingBufferQueue, PushPop_1K_via_10)
{
    Context * context = new Context(1000,10);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

TEST(SPSC_RingBufferQueue, PushPop_1K_via_2)
{
    Context * context = new Context(1000,2);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

TEST(SPSC_RingBufferQueue, PushPop_1K_via_1)
{
    Context * context = new Context(1000,1);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

//////////////////////////////////////////////////////////////////////////

TEST(SPSC_RingBufferQueue, PushPop_100K_via_10K)
{
    Context * context = new Context(100000,10000);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

TEST(SPSC_RingBufferQueue, PushPop_100K_via_1K)
{
    Context * context = new Context(100000,1000);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

TEST(SPSC_RingBufferQueue, PushPop_100K_via_100)
{
    Context * context = new Context(100000,100);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

TEST(SPSC_RingBufferQueue, PushPop_100K_via_10)
{
    Context * context = new Context(100000,10);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

TEST(SPSC_RingBufferQueue, PushPop_100K_via_2)
{
    Context * context = new Context(100000,2);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

TEST(SPSC_RingBufferQueue, PushPop_100K_via_1)
{
    Context * context = new Context(100000,1);
    SPSC_RingBufferQueue_Test(producer,consumer,context);
}

//////////////////////////////////////////////////////////////////////////
