#ifdef WIN32
#include <Windows.h>
#else

#endif

#include <gmock/gmock.h>
#include <gtest/gtest.h>

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
    {
        int * val = new int(i);
        while (!context->queue.tryPush(val))
            ;
    }
}

static void consumer(void * param)
{
    Context * context = (Context*)param; 

    for(int i = 0; i < context->N; i++)
    {
        int * val;
        while ((val = context->queue.tryPop()) == NULL)
            ;
        EXPECT_EQ(i, *val);
        delete val;
    }
}

//////////////////////////////////////////////////////////////////////////

#ifdef WIN32

TEST(SPSC_RingBufferQueue, TryPushPop_10K_via_1K)
{
    Context * context = new Context(10000,1000);

    HANDLE threads[] =
    {
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,context,0,NULL),
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer,context,0,NULL),
    };

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);
}

#else

TEST(SPSC_RingBufferQueue, TryPushPop_10K_via_1K)
{
    // POSIX version
}

#endif

//////////////////////////////////////////////////////////////////////////

#ifdef WIN32

TEST(SPSC_RingBufferQueue, TryPushPop_10K_via_2)
{
    Context * context = new Context(10000,2);

    HANDLE threads[] =
    {
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,context,0,NULL),
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer,context,0,NULL),
    };

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);
}

#else

TEST(SPSC_RingBufferQueue, TryPushPop_10K_via_2)
{
    // POSIX version
}

#endif

//////////////////////////////////////////////////////////////////////////

#ifdef WIN32

TEST(SPSC_RingBufferQueue, TryPushPop_10K_via_1)
{
    Context * context = new Context(10000,1);

    HANDLE threads[] =
    {
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,context,0,NULL),
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer,context,0,NULL),
    };

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);
}

#else

TEST(SPSC_RingBufferQueue, TryPushPop_10K_via_1)
{
    // POSIX version
}

#endif

//////////////////////////////////////////////////////////////////////////