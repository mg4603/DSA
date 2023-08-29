#include <iostream>
#include <assert.h>

#include <stack>

class MyQueue {
    std::stack<int> queue;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        queue.push(x);
    }
    
    int pop() {
        std::stack<int> temp;
        while(queue.size() > 1)
        {
            temp.push(queue.top());
            queue.pop();
        }
        int res = queue.top();
        queue = temp;
        temp = std::stack<int>();

        while(!queue.empty())
        {
            temp.push(queue.top());
            queue.pop();
        }
        queue = temp;
        return res;
    }
    
    int peek() {
        std::stack<int> temp;
        while(queue.size() > 1)
        {
            temp.push(queue.top());
            queue.pop();
        }

        int res = queue.top();
        temp.push(res);
        queue = temp;
        temp = std::stack<int>();

        while(!queue.empty())
        {
            temp.push(queue.top());
            queue.pop();
        }
        queue = temp;
        return res;
    }
    
    bool empty() {
        return queue.empty();
    }
};



int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    assert(q.peek() == 1);
    assert(q.pop() == 1);
    assert(q.empty() == false);
    return 0;
}