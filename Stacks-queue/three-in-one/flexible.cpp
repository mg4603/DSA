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
            return adjustIndex(start + size -1);
        }

        bool isFull(){
            return size == capacity;
        }

        bool isEmpty(){
            return size == 0;
        }

    };
    vector<StackInfo> info;
    
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
            
        }

};

int main(){

    return 0;
}