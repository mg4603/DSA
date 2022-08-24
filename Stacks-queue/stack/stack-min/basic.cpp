#include<iostream>
#include<vector>
using namespace std;

template <typename T, typename Q>
class StackInfo{
    T start, size, capacity;
    public:
        StackInfo(T start, T capacity){
            this->start = start;
            this->capacity = capacity;
            this->size = 0;
        }

        bool isWithinStackCapacity(vector<Q> values, T index){
            if(index < 0 || index >= values.size()){
                return false;
            }
            T contiguousIndex(index < start ? index + values.size() : index);
            T end(start + capacity);
            return start <= contiguousIndex && contiguousIndex <= end;
        }

        T getStart(){
            return this->start;
        }

        T getSize(){
            return this->size;
        }

        T getCapacity(){
            return this->capacity;
        }

        void setStart(T start){
            this->start = start
        }

        void incrementSize(){
            this->size--;
        }

        void incrementCapacity(){
            this->capacity++;
        }

        void decrementSize(){
            this->size--;
        }

        void decrementCapacity(){
            this->capacity--;
        }

        bool isEmpty(){
            return size == 0;
        }

        bool isFull(){
            return size == capacity;
        }

};

// All identifier are numeric

template<typename T, typename Q>
T adjustIdentifier(vector<Q> vec, T identifier){
    return ((identifier % vec.size())+vec.size())%vec.size();
}

template<typename T, typename Q>
T nextIdentifier(vector<Q> vec, T identifier){
    return adjustIdentifier(vec, identifier + 1);
}

template<typename T, typename Q>
T previousIdentifier(vector<Q> vec, T identifier){
    return adjustIdentifier(vec, identifier - 1);
}

template <typename T, typename Q>
T lastIdentifier(vector<Q> vec, T start, T end){
    return adjustIdentifier(vec, start + end -1);
}

template <typename T, typename Q>
class Stack{
    vector<StackInfo<T, Q>*> info;
    vector<Q> values;

    void expand(T stackNum){
        StackInfo<T, Q> *stack = info[stackNum];
        shift(nextIdentifier(info, stackNum));
        stack->incrementCapacity();
    }

    void shift(T stackNum){
        StackInfo<T, Q> *stack = info[stackNum];
        if(stack->getSize() >= stack->getCapacity()){
            shift(nextIdentifier(info, stackNum));
            stack->incrementCapacity();
        }


    }

    public:
        Stack(T numberOfStacks, T defaultSize){
            for(T i(0); i < numberOfStacks; i++){
                StackInfo<T, Q> *stack = new StackInfo(i*defaultSize, defaultSize);
                info.push_back();
            }
            values = vector<Q>(defaultSize*numberOfStacks, 0);
        }

        

};








int main(){

    return 0;
}