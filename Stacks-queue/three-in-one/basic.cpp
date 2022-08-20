#include<iostream>
#include<vector>
using namespace std;

template <typename T, typename Q>
class FixedMultiSizedStack{
        T stackCapacity;
        int numOfStacks;
        vector<T> sizes;
        vector<Q> values;
    public:
        FixedMultiSizedStack(int stackSize);
        bool push(int stackNum, Q value);
        Q pop(int stackNum);
        Q peek(int stackNum);
        T indexOfTop(int stackNum);
        bool isEmpty(int stackNum);
        bool isFull(int stackNum);
};
template <typename T, typename Q>
FixedMultiSizedStack<T,Q>::FixedMultiSizedStack(int stackSize){
    numOfStacks = 3;
    stackCapacity = stackSize;
    sizes = vector<T>(numOfStacks, 0);
    values = vector<Q>(stackCapacity*numOfStacks, 0);
}
template<typename T, typename Q>
bool FixedMultiSizedStack<T,Q>::push(int stackNum, Q value){
    if(isFull(stackNum)){
        throw "Stack Full:"+static_cast<char>(stackNum);
        return false;
    }
    sizes[stackNum]++;
    values[indexOfTop(stackNum)] = value;
    return true;
}

template<typename T, typename Q>
Q FixedMultiSizedStack<T,Q>::pop(int stackNum){
    if(isEmpty(stackNum)){
        throw "Stack Empty: "+static_cast<char>(stackNum);
    }
    T topIndex(indexOfTop(stackNum));
    Q value = values[topIndex];
    values[topIndex] = 0;
    sizes[stackNum]--;
    return value;
}

template<typename T, typename Q>
Q FixedMultiSizedStack<T,Q>::peek(int stackNum){
    if(isEmpty(stackNum)){
        throw "Stack Empty: "+static_cast<char>(stackNum);
    }
    return values[indexOfTop(stackNum)];
}

template<typename T, typename Q>
T FixedMultiSizedStack<T,Q>::indexOfTop(int stackNum){
    return sizes[stackNum];
}
template<typename T, typename Q>
bool FixedMultiSizedStack<T,Q>::isEmpty(int stackNum){
    return sizes[stackNum] == 0;
}
template<typename T, typename Q>
bool FixedMultiSizedStack<T,Q>::isFull(int stackNum){
    return sizes[stackNum] ==  stackCapacity;
}

int main(){
    FixedMultiSizedStack<int, int> *fmss = new FixedMultiSizedStack<int, int>(3);
    fmss->push(3, 3);
    cout<<fmss->peek(3);
    return 0;
}