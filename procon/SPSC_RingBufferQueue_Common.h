#pragma once

#ifdef WIN32
#include <Windows.h>
#else
// POSIX threads include
#endif

//////////////////////////////////////////////////////////////////////////

#ifdef WIN32

template<typename F1, typename F2, typename T>
void SPSC_RingBufferQueue_Test_NoAffinity(F1 * producer, F2 * consumer, T * context)
{
    HANDLE threads[] =
    {
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,context,0,NULL),
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer,context,0,NULL),
    };

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
}

template<typename F1, typename F2, typename T>
void SPSC_RingBufferQueue_Test_AffinityTo1(F1 * producer, F2 * consumer, T * context)
{
    HANDLE threads[] =
    {
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,context,CREATE_SUSPENDED,NULL),
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer,context,CREATE_SUSPENDED,NULL),
    };

    SetThreadAffinityMask(threads[0], 0x00000001);
    SetThreadAffinityMask(threads[1], 0x00000001);

    ResumeThread(threads[0]);
    ResumeThread(threads[1]);

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
}

template<typename F1, typename F2, typename T>
void SPSC_RingBufferQueue_Test_AffinityTo12(F1 * producer, F2 * consumer, T * context)
{
    HANDLE threads[] =
    {
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,context,CREATE_SUSPENDED,NULL),
        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer,context,CREATE_SUSPENDED,NULL),
    };

    SetThreadAffinityMask(threads[0], 0x00000001);
    SetThreadAffinityMask(threads[1], 0x00000002);

    ResumeThread(threads[0]);
    ResumeThread(threads[1]);

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
}

#else

template<typename F1, typename F2, typename T>
void SPSC_RingBufferQueue_Test_NoAffinity(F1 producer, F2 consumer, T context)
{
    // POSIX version
}

template<typename F1, typename F2, typename T>
void SPSC_RingBufferQueue_Test_AffinityTo1(F1 * producer, F2 * consumer, T * context)
{
    // POSIX version
}

template<typename F1, typename F2, typename T>
void SPSC_RingBufferQueue_Test_AffinityTo12(F1 * producer, F2 * consumer, T * context)
{
    // POSIX version
}

#endif

//////////////////////////////////////////////////////////////////////////

template<typename F1, typename F2, typename T>
void SPSC_RingBufferQueue_Test(F1 * producer, F2 * consumer, T * context)
{
    SPSC_RingBufferQueue_Test_NoAffinity(producer,consumer,context);
    //SPSC_RingBufferQueue_Test_AffinityTo1(producer,consumer,context);
    SPSC_RingBufferQueue_Test_AffinityTo12(producer,consumer,context);
}

//////////////////////////////////////////////////////////////////////////
