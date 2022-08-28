#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// T: size val type
// Q: value type
template<typename T, typename Q>
class SetOfStack{
    vector<Stack<Q>> stacks;
    T capacity;
    stack<T>* getLastStack(){
        if(stacks.size() == 0){
            throw "Stack Empty";
        }
        return stacks.back();
    }

    void addStack(value){
        stack<Q> *newStack = new stack<Q>();
        newStack->push(value);
        stacks.push_back(newStack);
    }

    public:
        SetOfStacks(T capacity){
            this->capacity = capacity;
        }    

        void push(Q value){
            if(stacks.size() == 0){
                addStack(value);
            }else{
                stack<Q> *lastStack = this->getLastStack();
                if(lastStack->size() == this->capacity){
                    lastStack->push(value);
                }else{
                    addStack(value);
                }
            }
        }

        Q pop(){
            if(stacks.size() == 0){
                throw "Stack Empty";
            }else{
                stack<Q> *lastStack = this->getLastStack();
                Q value = lastStack->top();
                lastStack->pop();
                if(lastStack->size() == 0){
                    stacks.pop_back();
                }
                return value;
            }
        }

        Q popAt(T index){
            return leftShift(index, true);
        }

        


};

int main(){

    return 0;
}