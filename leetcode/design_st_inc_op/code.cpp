#include <iostream>
#include <assert.h>

#include <vector>

class CustomStack {
    std::vector<std::pair<int, int>> stack;
    int size;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stack.resize(maxSize);
        size = 0;
    }
    
    void push(int x) {
        if(size < maxSize) {
            stack[size].first = x;
            size++;
        }
    }
    
    int pop() {
        if(size == 0)return -1;

        size--;
        int back = stack[size].first;
        int inc = stack[size].second;
        stack[size].second = 0;
        if(size > 0) {
            stack[size - 1].second += inc;
        }
        return back + inc;

    }
    
    void increment(int k, int val) {
        if(size == 0)return;
        if(size < k) {
            stack[size - 1].second += val;
        }else {
            stack[k - 1].second += val;
        }
    }
};

int main()
{
    CustomStack stk(3);
    stk.push(1);                          
    stk.push(2);                          
    assert(stk.pop() == 2);
    stk.push(2);                          
    stk.push(3);                          
    stk.push(4);                          
    stk.increment(5, 100);                
    stk.increment(2, 100);               
    assert(stk.pop() == 103);
    assert(stk.pop() == 202);
    assert(stk.pop() == 201);
    assert(stk.pop() == -1);        
    return 0;
}