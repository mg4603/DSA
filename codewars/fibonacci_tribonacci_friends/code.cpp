#include <assert.h>
#include <iostream>

#include <vector>
#include <numeric>

std::vector<int> xbonacci(std::vector<int> signature, int n){
    int x = signature.size();
    if(n < x){
        return std::vector<int>(signature.begin(), signature.begin() + n);
    }
    while(signature.size() < n){
        signature.push_back(std::accumulate(signature.end() - x, signature.end(), 0, [](int a, int b){
            return a + b;
        }));
    }
    return signature;
}

void Test_1()
{
    std::vector<int> signature = {0, 1};
    std::vector<int> expected = {0,1,1,2,3,5,8,13,21,34};
    assert(xbonacci(signature, 10) == expected);
}
void Test_2()
{
    std::vector<int> signature = {1, 1};
    std::vector<int> expected = {1,1,2,3,5,8,13,21,34,55};
    assert(xbonacci(signature, 10) == expected);


}
void Test_3()
{
    std::vector<int> signature = {0,0,0,0,1};
    std::vector<int> expected = {0,0,0,0,1,1,2,4,8,16};
    assert(xbonacci(signature, 10) == expected);

}
void Test_4()
{
    std::vector<int> signature = {1,0,0,0,0,0,1};
    std::vector<int> expected = {1,0,0,0,0,0,1,2,3,6};
    assert(xbonacci(signature, 10) == expected);

    
}
void Test_5()
{
    std::vector<int> signature = {1,0,0,0,0,0,0,0,0,0};
    std::vector<int> expected = {1,0,0,0,0,0,0,0,0,0,1,1,2,4,8,16,32,64,128,256};
    assert(xbonacci(signature, 20) == expected);

}
void Test_6()
{
    std::vector<int> signature = {1,2,3,4,5,6,7,8,9,0};
    std::vector<int> expected = {1,2,3,4,5,6,7,8,9};
    assert(xbonacci(signature, 9) == expected);

    
}
void Test_7()
{
    std::vector<int> signature = {1,2,3,4,5,6,7,8,9,0};
    std::vector<int> expected = {};
    assert(xbonacci(signature, 0) == expected);

}

int main()
{
    Test_1();
    Test_2();
    Test_3();
    Test_4();
    Test_5();
    Test_6();
    Test_7();
    return 0;
}
    
