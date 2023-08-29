#include <iostream>
#include <assert.h>

#include <queue>

class MyStack {
    std::queue<int> stack;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        stack.push(x);
    }
    
    int pop() {
        std::queue<int> temp;
        while(stack.size() > 1)
        {
            temp.push(stack.front());
            stack.pop();
        }
        
        int pop_val = stack.front();
        stack.pop();
        stack = temp;
        return pop_val;
    }
    
    int top() {
        std::queue<int> temp;
        while(stack.size() > 1)
        {
            temp.push(stack.front());
            stack.pop();
        }
        
        int top_val = stack.front();
        temp.push(top_val);
        stack = temp;
        return top_val;
    }
    
    bool empty() {
        if(stack.empty())
        {
            return true;
        }
        return false;
    }
};



int main()
{
    MyStack stack;
    
    stack.push(1);
    stack.push(2);
    assert(stack.top() == 2);
    assert(stack.pop() == 2);
    assert(stack.empty() == false);
    return 0;
}