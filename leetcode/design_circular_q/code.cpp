#include <iostream>
#include <assert.h>

#include <vector>

class MyCircularQueue {
    std::vector<int> q;
    int front = 0;
    int back = -1;
    int k;
    int size;
public:
    MyCircularQueue(int k) 
    {
        q.resize(k);
        this->k = k;
        size = 0;
    }
    
    bool enQueue(int val) 
    {
        if(this->isFull())
        {
            return false;
        }
        size++;
        back++;
        back %= k;
        q[back] = val;
        return true;
    }
    
    bool deQueue() 
    {
        if(this->isEmpty())
        {
            return false;
        }
        size--;
        front++;
        front %= k;
        return true;
    }
    
    int Front() 
    {
        if(size > 0)
        {
            return q[front];
        }
        return -1;
    }
    
    int Rear() 
    {
        if(size > 0)
        {
            return q[back];
        }
        return -1;
    }
    
    bool isEmpty() 
    {
        return size == 0;
    }
    
    bool isFull() 
    {
        return size == k;
    }
};

int main()
{
    MyCircularQueue obj(3);
    assert(obj.enQueue(1) == true);
    assert(obj.enQueue(2) == true);
    assert(obj.enQueue(3) == true);
    assert(obj.enQueue(4) == false);
    assert(obj.Rear()     == 3);
    assert(obj.isFull()   == true);
    assert(obj.deQueue()  == true);
    assert(obj.enQueue(4) == true);
    assert(obj.Rear()     == 4);
    return 0;
}