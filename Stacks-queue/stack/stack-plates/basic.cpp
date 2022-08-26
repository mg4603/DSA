#include<iostream>
#include<vector>
#include<stack>
#include<typeinfo>
using namespace std;

// Q is value type 
// T is size type 
template<typename T, typename Q>
class SetOfStacks{
    vector<stack<Q>*> stacks;
    T capacity;
    stack<Q>* getLastStack(){
        return stacks.back();
    }
    public:
        SetOfStacks(T capacity){
            this->capacity = capacity;
        }
        void addStack(Q value){
            stack<Q> *newStack = new stack<Q>();
            newStack->push(value);
            stacks.push_back(newStack);
        }

        void push(Q value){
            if(stacks.size() != 0){
                stack<Q> *lastStack = this->getLastStack();
                if(lastStack->size() == this->capacity){
                    addStack(value);
                }else{
                    lastStack->push(value);
                }
            }else{
                addStack(value);
            }
        }

        Q pop(){
            if(stacks.size() == 0){
                throw "Stacks empty";
            }
            stack<Q> *lastStack = this->getLastStack();
            if(lastStack->size() == 1){
                Q value = lastStack->top();
                lastStack->pop();
                stacks.pop_back();
                return value;
            }else{
                Q value =  lastStack->top();
                lastStack->pop();
                return value;
            }
        }
        
        
};

int main(){
    SetOfStacks<int, int> *setOfStacks = new SetOfStacks<int, int>(10);
    setOfStacks->push(1);
    setOfStacks->push(2);
    setOfStacks->push(3);
    setOfStacks->push(4);
    setOfStacks->push(5);
    setOfStacks->push(6);
    setOfStacks->push(7);
    setOfStacks->push(8);
    setOfStacks->push(9);
    setOfStacks->push(10);
    setOfStacks->push(11);
    cout<<setOfStacks->pop()<<endl;
    cout<<setOfStacks->pop()<<endl;
    return 0;
}