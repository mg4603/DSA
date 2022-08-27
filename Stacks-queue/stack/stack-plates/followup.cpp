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

    public:
        SetOfStacks(T capacity){
            this->capacity = capacity;
        }    

        
};

int main(){

    return 0;
}