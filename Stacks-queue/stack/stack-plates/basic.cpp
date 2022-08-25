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
    public:
        SetOfStacks(T capacity){
            this->capacity = capacity;
        }
        
};

int main(){
    return 0;
}