#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

//#include "SPSC_RingBufferQueue.h"

//using namespace std;

////////////////////////////////////////////////////////////////////////////
//
//typedef SPSC_RingBufferQueue<int> MyRingBuffer;
//const int N = 100000000;
//const int K = 10;
//bool stop_watcher = false;
//
////////////////////////////////////////////////////////////////////////////
//
//void producer(void * param)
//{
//    MyRingBuffer * buffer = (MyRingBuffer*)param; 
//
//    int * val = new int(0xDEADBEEF);
//    for(int i = 0; i < N; i++)
//    {
//        buffer->push(val);
//        //while (!buffer->tryPush(val));
//    }
//}
//
////////////////////////////////////////////////////////////////////////////
//
//unsigned sumTime = 0;
//
//void consumer(void * param)
//{
//    MyRingBuffer * buffer = (MyRingBuffer*)param;
//
//    DWORD t1 = GetTickCount();
//    for(int i = 0; i < N; i++)
//    {
//        int * val = buffer->pop();
//        //while (buffer->tryPop() == NULL);
//
//        //if (*val != 0xDEADBEEF)
//        //    cout << "Error at i = " << i << " got value = " << *val << endl;
//    }
//    DWORD t2 = GetTickCount();
//    stop_watcher = true;
//
//    unsigned nowTime = t2 - t1;
//    cout << "Time  = " << nowTime << "ms" << '\t';
//    cout << "Speed = " << N*1000.0/nowTime/1000000 << "M/s" << endl;
//    sumTime += nowTime;
//}
//
////////////////////////////////////////////////////////////////////////////
//
//std::vector<unsigned short> buffer_sizes;
//
//void watcher(void * param)
//{
//    MyRingBuffer * buffer = (MyRingBuffer*)param;
//
//    while(!stop_watcher)
//    {
//        buffer_sizes.push_back(buffer->size());
//    }
//}
//
////////////////////////////////////////////////////////////////////////////

int main(int argc, char * argv[])
{
    //MyRingBuffer * buf = new MyRingBuffer(1000);
    //
    //for (int i = 0; i < K; i++)
    //{
    //    HANDLE threads[] =
    //    {
    //        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,buf,CREATE_SUSPENDED,NULL),
    //        CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer,buf,CREATE_SUSPENDED,NULL),
    //        //CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)watcher, buf,CREATE_SUSPENDED,NULL),
    //    };
    //
    //    SetThreadAffinityMask(threads[0], 1 << 0);
    //    SetThreadAffinityMask(threads[1], 1 << 1);
    //    //SetThreadAffinityMask(threads[2], 1 << 2);
    //
    //    ResumeThread(threads[0]);
    //    ResumeThread(threads[1]);
    //    //ResumeThread(threads[2]);
    //
    //    WaitForMultipleObjects(2, threads, TRUE, INFINITE);
    //}
    //
    //cout << "Average values for " << K << " trys:" << endl;
    //cout << "Time  = " << sumTime/K << "ms" << '\t';
    //cout << "Speed = " << N*K*1000.0/sumTime/1000000 << "M/s" << endl;
    //
    //std::ofstream stream("1.csv");
    //for(unsigned i = 0; i < buffer_sizes.size(); i+=1000)
    //    stream << buffer_sizes[i] << endl;

    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}