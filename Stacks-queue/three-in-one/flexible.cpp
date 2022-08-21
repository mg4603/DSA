#include<iostream>
#include<vector>
using namespace std;

template<typename T, typename Q>
class MultiStack{
    vector<T> values;
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
};

int main(){

    return 0;
}