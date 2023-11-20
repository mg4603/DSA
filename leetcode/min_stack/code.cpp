#include <iostream>
#include <assert.h>

#include <stack>

class MinStack {
    std::stack<std::pair<int, int>> st;

public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(std::make_pair(val, val));
        }    
        else
        {
            int temp = st.top().second;
            if(val < temp)
            {
                temp = val;
            }
            st.push(std::make_pair(val, temp));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main()
{
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    assert(obj.getMin() == -3);
    obj.pop();
    assert(obj.top() == 0);
    assert(obj.getMin() == -2);

    return 0;
}