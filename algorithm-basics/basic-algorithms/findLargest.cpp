#include<iostream>
#include<vector>
using namespace std;

// find the largest number in an array
template <typename T>
T findLargest(vector<T> array){
    T largest = array.at(0);
    for(size_t i(1); i < array.size(); i++){
        if(array.at(i) > largest){
            largest = array.at(i);
        }
    }
    return largest;
}

int main(){
    vector<int> vec = {9, 9, 8, 8, 8, 10};
    cout<<findLargest(vec);
    return 0;
}