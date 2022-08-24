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
        }

        bool isWithinStackCapacity(vector<Q> values, T index){
            if()
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