#include<iostream>
#include<vector>
using namespace std;

// O(N^2) time
template<typename T>
bool containsDuplicates(vector<T> array){
    if(array.size() == 0)
        return false;
    T largest = array.at(0);
    for(size_t i(0); i < array.size(); i++){
        for(size_t j(0); j < array.size(); j++){
            if(i != j){
                if(array.at(i) == array.at(j))
                    return true;
            }
        }
    }
    return false;
}

int main(){
    return 0;
}