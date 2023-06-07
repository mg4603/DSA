#include <assert.h>
#include <iostream>

#include <set>
#include <vector>
#include <cmath>

template<typename T>
unsigned long long estSubsets(const std::vector<T>& arr) {
    
    unsigned int s(std::set<T>(arr.begin(), arr.end()).size());
    unsigned long long ans(1);
    for(unsigned int i(0); i < s; i++)
    {
      ans *= 2;
    }
    return ans - 1;
}

int main()
{
    std::vector<int> a = {1, 2, 3, 4};
    assert(estSubsets(a) == 15);
    std::vector<char> b = {'a', 'b', 'c', 'd', 'd'};
    assert(estSubsets(b) == 15);
    a = {2, 3, 4, 5, 5, 6, 6, 7, 8, 8};
    assert(estSubsets(a) == 127);
    b = {'a', 'z', 'z', 'z', 'b', 'j', 'f', 'k', 'b', 'd', 'j', 'j', 'n', 'm', 'm'};
    assert(estSubsets(b) == 511);
    a = {1,1,1,1,1,1,1,1};
    assert(estSubsets(a) == 1);
    a = {};
    assert(estSubsets(a) == 0);
    return 0;
};