#include <assert.h>
#include <iostream>

#include <vector>
#include <algorithm>

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array);
};

std::vector<int> Kata::sortArray(std::vector<int> array){
    std::vector<int> odds;
    for(int num: array){
        if(num % 2 == 1){
            odds.push_back(num);
        }
    }
    std::sort(odds.begin(), odds.end());
    int count(0);
    for(int &num: array){
        if(num % 2 == 1){
            num = odds.at(count++);
        }
    }
    return array;
}

void dotest(const std::vector<int> in, const std::vector<int> expected){
    Kata kata;
    std::vector<int> actual = kata.sortArray(in);
    for(size_t i(0); i < actual.size(); i++){
        assert(actual.at(i) == expected.at(i));
    }
}

int main(){
        
    dotest({ 5, 3, 2, 8, 1, 4 }, { 1, 3, 2, 8, 5, 4 });
    dotest({ 5, 3, 1, 8, 0 }, { 1, 3, 5, 8, 0 });
    dotest({}, {});

}