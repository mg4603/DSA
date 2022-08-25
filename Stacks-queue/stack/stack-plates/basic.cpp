#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Q is value type 
// T is size type 
template<typename T, typename Q>
class SetOfStacks{
    vector<Stack<Q>> stacks;
    T capacity;
    Stack<Q> getLastStack(){
        return *stacks.back()
    }
    public:
        SetOfStacks(T capacity){
            this->capacity = capacity;
        }
        void push(Q value){
            Stack<Q> lastStack = getLastStack();
            if(lastStack.size() != capacity){
                lastStack.push(value);
            }else{
                Stack<Q> stack = new Stack<Q>();
                stack.push(value);
                stacks.push_back(stack);
            }
        }

        Q pop(){
            Stack<Q> lastStack = getLastStack();
            if(lastStack.size() == 1){
                Q value = lastStack.pop()
                stacks.pop_back();
                return value
            }else{
                return lastStack.pop();
            }
        }
        
        
};

int main(){
    return 0;
}