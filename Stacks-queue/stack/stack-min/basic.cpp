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

};

