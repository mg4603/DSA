#include <iostream>
#include <assert.h>

#include <vector>

class MyCircularDeque {
    std::vector<int> q;
    int size;
    int back;
    int front;
    int k;
public:
    MyCircularDeque(int k) {
        q.resize(k);
        size = 0;
        front = -1;
        back = -1;
        this->k = k;
    }
    
    bool insertFront(int value) {
        
        if(size < k)
        {
            if(size == 0)
            {
                front = 0;
                back = 0;
            }
            else
            {
                front--;
                if(front < 0)
                {
                    front += k;
                }
    
            }
            front %= k;
            q[front] = value;
            size++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(size < k)
        {
            if(size == 0)
            {
                front = 0;
                back = 0;
            }
            else
            {
                back++;
            }

            back %= k;
            q[back] = value;
            size++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(size > 0)
        {
            size--;
            front++;
            front %= k;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(size > 0)
        {
            size--;
            back--;
            if(back < 0)
            {
                back += k;
            }
            back %= k;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(size == 0)
        {
            return -1;
        }
        return q[front];
    }
    
    int getRear() {
        if(size == 0)
        {
            return -1;
        }
        return q[back];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};



int main()
{
    MyCircularDeque myCircularDeque(3);
    assert(myCircularDeque.insertLast(1)  == true);
    assert(myCircularDeque.insertLast(2)  == true);
    assert(myCircularDeque.insertFront(3) == true);
    assert(myCircularDeque.insertFront(4) == false);
    assert(myCircularDeque.getRear()      == 2);
    assert(myCircularDeque.isFull()       == true);
    assert(myCircularDeque.deleteLast()   == true);
    assert(myCircularDeque.insertFront(4) == true);
    assert(myCircularDeque.getFront()     == 4);
    return 0;
}