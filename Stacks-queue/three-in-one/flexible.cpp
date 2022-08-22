#include<iostream>
#include<vector>
using namespace std;

template<typename T, typename Q>
class MultiStack{
    vector<Q> values;

    // Class to hold metadata about each stack 
    class StackInfo{
        public: 
        T size, start, capacity
        StackInfo(T start, T capacity){
            this.start = start;
            this.capacity = capacity;
        }

        bool isWithinStackCapacity(T index){
            if(index < 0 || index >= values.size()){
                return false;
            }

            T contiguousIndex(index < start ? index + values.size() : index);
            T end(start + capacity);
            return start <= contiguousIndex && contiguousIndex < end;
        }

        T lastCapacityIndex(){
            return adjustIndex(start + capacity - 1);
        }

        T lastElementIndex(){
            return adjustIndex(start + size - 1);
        }

        bool isFull(){
            return size == capacity;
        }

        bool isEmpty(){
            return size == 0;
        }

    };
    vector<StackInfo> info;
    
    void expand(T stackNum){
        shift((stackNum+1)%info.size());
        info[stackNum].capacity++;
    }

    public:
        MultiStack(T numberOfStacks, T defaultSize){
            for(T i(0); i < numberOfStacks; i++){
                info.push_back(new StackInfo(i*defaultSize, defaultSize));
            }
            values = vector<Q>(numberOfStacks*defaultSize, 0);
        }
        void push(T stackNum, Q value){
            if(allStacksAreFull()){
                throw "All Stacks Are Full";
            }

            StackInfo stack = info[stackNum];
            if(stack.isFull()){
                expand(stackNum);
            }

            stack.size++;
            values[stack.lastElementIndex()] = value;
            
        }
        Q pop(T stackNum){
            StackInfo stack = info[stackNum];
            if(stack.isEmpty()){
                throw "Stack is empty: "+static_cast<string>(stackNum);
            }
            T value = values[stack.lastElementIndex()];
            values[stack.lastElementIndex()] = 0;
            stack.size--;
            return value;
        }
        
        Q peek(T stackNum){
            StackInfo stack = info[stackNum];
            if(stack.isEmpty()){
                throw "Stack is empty"+static_cast<string>(stackNum);
            }
            return values[stack.lastElementIndex()];
        }

        // shift over the elements of the stack and shrink it's size by one
        // if there is no space, then shift the next stack too
        void shift(T stackNum){
            StackInfo stack = info[stackNum];
            
            if(stack.size >= stack.capacity){
                T nextStack = (stackNum + 1) % info.size();
                shift(nextStack);
                stack.capacity++;
            }

            T index(stack.lastCapacityIndex());
            while(stack.isWithinStackCapacity(index)){
                values[index] = values[previousIndex(index)];
                index = previousIndex(index);
            }

            values[stack.start] = 0;
            stack.start = nextIndex(stack.start);
            stack.capacity--;
        }

        T numberOfElements(){
            T size(0);
            for(StackInfo stack: info){
                size += stack.size;
            }
            return size;
        }

        bool allStacksAreFull(){
            return values.size() == numberOfElements();
        }

        T adjustIndex(T index){
            T max = values.size();
            return ((index % max)+max)%max;
        }

        
};

int main(){

    return 0;
}