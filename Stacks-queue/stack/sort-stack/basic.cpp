#include<iostream>
#include<stack>
using namespace std;

template <typename Q>
stack<Q> sortStack(stack<Q> unsortedStack){
    stack<Q> sortedStack;

    while(!unsortedStack.empty()){
        Q tmp = unsortedStack.top();
        unsortedStack.pop();
        while(!sortedStack.empty() && tmp > sortedStack.top()){
            unsortedStack.push(sortedStack.top());
            sortedStack.pop();
        }
        sortedStack.push(tmp);
    }
    return sortedStack;

}

int main(){
    
    return 0;
}