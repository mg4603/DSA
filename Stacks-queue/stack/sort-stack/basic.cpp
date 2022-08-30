#include<iostream>
#include<stack>
using namespace std;

template <typename Q>
stack<Q> sortStack(stack<Q> unsortedStack){
    stack<Q> sortedStack;

    while(!unsortedStack.empty()){
        Q tmp = unsortedStack.top();
        unsortedStack.pop();
        while(!sortedStack.empty() && tmp < sortedStack.top()){
            unsortedStack.push(sortedStack.top());
            sortedStack.pop();
        }
        sortedStack.push(tmp);
    }
    return sortedStack;

}

int main(){
    stack<int> s;
    s.push(1);
    s.push(5);
    s.push(1);
    s.push(1);
    s.push(0);
    s.push(7);
    s.push(6);
    s.push(5);
    stack<int> sorted = sortStack(s);
    cout<<sorted.top()<<endl;
    return 0;
}