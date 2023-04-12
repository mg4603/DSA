#include<vector>
#include<assert.h>

std::vector<int> digitize(unsigned long n){
    std::vector<int> res = std::vector<int>();
    if(n == 0){
        res.push_back(0);
    }
    while(n){
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

int main(){
    assert(digitize(348597) == std::vector<int>({ 7,9,5,8,4,3 }));
    assert(digitize(35231) == std::vector<int>({ 1,3,2,5,3 }));
    assert(digitize(0) == std::vector<int>({ 0 }));
    return 0;
}