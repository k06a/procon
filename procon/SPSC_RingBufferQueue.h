#pragma once

template<typename T>
class SPSC_RingBufferQueue
{
    int maxSize;
    T ** arr;
    volatile int front;
    volatile int back;
    
public:
    SPSC_RingBufferQueue(int maxSize)
        : maxSize(maxSize+1)
        , arr(new T * [maxSize+1])
        , front(0)
        , back(0)
    { 
    }

    ~SPSC_RingBufferQueue()
    {
        delete [] arr;
    }

    // producer-side
    void push(T * val)
    {
        int old_front = front;
        if (next(back) == old_front) // full
            while (front == old_front);

        arr[back] = val;
        back = next(back);  
    }

    // consumer-side
    T * pop()
    {
        int old_back = back;
        if (old_back == front) // empty
            while (back == old_back);

        T * val = arr[front];
        front = next(front);

        return val;
    }

    // producer-side
    bool tryPush(T * val)
    {
        if (next(back) == front) // full
            return false;

        arr[back] = val;
        back = next(back);
        return true;
    }

    // consumer-side
    T * tryPop()
    {
        if (back == front) // empty
            return NULL;

        T * val = arr[front];
        front = next(front);

        return val;
    }

    int size() const
    {
        int sz = back - front;
        return (sz < 0) ? (sz + maxSize) : sz;
    }

    bool empty() const
    {
        return (back == front);
    }

    bool full() const
    {
        return (next(back) == front);
    }

private:
    int next(int index) const
    {
        ++index;
        return (index == maxSize) ? 0 : index;
    }
};