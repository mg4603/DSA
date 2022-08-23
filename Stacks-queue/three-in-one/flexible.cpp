#include<iostream>
#include<vector>
using namespace std;

template <typename T, typename Q>
T adjustIndex(vector<Q> values, T index){
    T max = values.size();
    return ((index % max)+max)%max;
}

template <typename T, typename Q>
T lastIndex(vector<Q> values, T start, T end){
    return adjustIndex(values, start + end - 1);
}


template <typename T, typename Q>
 // Class to hold metadata about each stack 
class StackInfo{
    T size, start, capacity;
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
            return start <= contiguousIndex && contiguousIndex < end;
        }
    
        bool isFull(){
            return size == capacity;
        }

        bool isEmpty(){
            return size == 0;
        }



        T getStart(){
            return start;
        }

        T getCapacity(){
            return capacity;
        }

        T getSize(){
            return size;
        }

        void incrementSize(){
            this->size++;
        }

        void incrementCapacity(){
            this->capacity++;
        }

        void incrementStart(){
            this->start++;
        }

        void decrementSize(){
            this->size--;
        }
        void decrementCapacity(){
            this->capacity--;
        }
        void decrementStart(){
            this->start--;
        }
};


template<typename T, typename Q>
class MultiStack{
    vector<Q> values;
    

    T nextIndex(T index){
        return this->adjustIndex(index+1);
    }
    
    T previousIndex(T index){
        return this->adjustIndex(index-1);
    }
   
    vector<StackInfo> info;
    
    void expand(T stackNum){
        shift((stackNum+1)%info.size());
        info[stackNum].capacity++;
    }

    public:
        MultiStack(T numberOfStacks, T defaultSize){
            for(T i(0); i < numberOfStacks; i++){
                StackInfo *stackInfo = new StackInfo(i*defaultSize, defaultSize);
                info.push_back(stackInfo);
            }
            values = vector<Q>(numberOfStacks*defaultSize, 0);
        }
        void push(T stackNum, Q value){
            if(allStacksAreFull()){
                throw "All Stacks Are Full";
            }

            StackInfo *stack = info[stackNum];
            if(stack->isFull()){
                expand(stackNum);
            }

            stack->size++;
            values[stack->lastElementIndex()] = value;
            
        }
        Q pop(T stackNum){
            StackInfo *stack = info[stackNum];
            if(stack->isEmpty()){
                throw "Stack is empty: "+to_string(stackNum);
            }
            T value = values[stack->lastElementIndex()];
            values[stack->lastElementIndex()] = 0;
            stack->size--;
            return value;
        }
        
        Q peek(T stackNum){
            StackInfo *stack = info[stackNum];
            if(stack->isEmpty()){
                throw "Stack is empty"+to_string(stackNum);
            }
            return values[stack->lastElementIndex()];
        }

        // shift over the elements of the stack and shrink it's size by one
        // if there is no space, then shift the next stack too
        void shift(T stackNum){
            StackInfo *stack = info[stackNum];
            
            if(stack->size >= stack->capacity){
                T nextStack = (stackNum + 1) % info.size();
                shift(nextStack);
                stack->capacity++;
            }

            T index(stack->lastCapacityIndex());
            while(stack->isWithinStackCapacity(index)){
                values[index] = values[previousIndex(index)];
                index = previousIndex(index);
            }

            values[stack->start] = 0;
            stack->start = nextIndex(stack->start);
            stack->capacity--;
        }

        T numberOfElements(){
            T size(0);
            for(StackInfo *stack: info){
                size += stack->size;
            }
            return size;
        }

        bool allStacksAreFull(){
            return values.size() == numberOfElements();
        }

        
};

int main(){
    MultiStack<int, int> *multiStack = new MultiStack<int, int>(3, 5);
    multiStack->push(1, 4);
    multiStack->push(3, 2);
    multiStack->push(1, 6);
    cout<<multiStack->peek(1)<<endl;
    cout<<multiStack->peek(3)<<endl;
    try{
        cout<<multiStack->peek(2);
    }
    catch(const char* error)
    {
        cout<<error<<endl;
    }


    return 0;
}