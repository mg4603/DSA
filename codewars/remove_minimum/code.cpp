#include <vector>
#include <string>
#include<assert.h>
#include<algorithm>

std::vector<unsigned int> removeSmallest(const std::vector<unsigned int>& numbers) {
    std::vector<unsigned int> res (numbers);
    if(numbers.size() == 0)return {};
    unsigned int minimum_element = *std::min_element(res.begin(), res.end());

    res.erase(std::find(res.begin(), res.end(), minimum_element));

    return res;
}

int main(){
    std::vector<unsigned int> n = { 1, 2, 3, 4, 5 }, 
                                r = { 2, 3, 4, 5 };

    assert(removeSmallest(n) == r);
    n = { 5, 3, 2, 1, 4 }, r = { 5, 3, 2, 4 };
    assert(removeSmallest(n) == r);
    n = { 2, 2, 1, 2, 1 }, r = { 2, 2, 2, 1 };
    assert(removeSmallest(n) == r);
    n = { 2 },             r = {};
    assert(removeSmallest(n) == r);
    n = {},                r = {};
    assert(removeSmallest(n) == r);
    return 0;
}
