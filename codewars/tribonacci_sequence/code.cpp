#include<vector>
#include<assert.h>
#include<random>
std::vector<int> tribonacci(std::vector<int> signature, int n);

int main(){

    std::vector<int> signature = { 1, 1, 1 };
    std::vector<int> expected = { 1, 1, 1, 3, 5, 9, 17, 31, 57, 105 };
    assert(tribonacci(signature, 10) == expected);

    signature = { 0, 0, 1 };
    expected = { 0,0,1,1,2,4,7,13,24,44 };
    assert(tribonacci(signature, 10) == expected);
    
    signature = { 0, 1, 1 };
    expected = { 0,1,1,2,4,7,13,24,44,81 };
    assert(tribonacci(signature, 10) == expected);

    signature = { 1, 0,  0 };
    expected = { 1, 0, 0, 1, 1, 2, 4, 7, 13, 24 };
    assert(tribonacci(signature, 10) == expected);

    signature = { 1,2,3 };
    expected = { 1,2,3,6,11,20,37,68,125,230 };
    assert(tribonacci(signature, 10) == expected);

    signature = { 1,2,3 };
    expected = { 1,2 };
    assert(tribonacci(signature, 2) == expected);

    int third = rand() % 10;
    signature = { 1,2, third };
    expected = {};
    assert(tribonacci(signature, 0) == expected);
}

std::vector<int> tribonacci(std::vector<int> signature, int n){
    std::vector<int> result;
    int a(signature[0]), b(signature[1]), c(signature[2]);
    for(int i = 0; i < n; i++){
        result.push_back(a);
        int sum(a + b + c);
        a = b;
        b = c;
        c = sum;
    }
    return result;
}