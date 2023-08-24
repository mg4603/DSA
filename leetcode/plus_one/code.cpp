#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::reverse(digits.begin(), digits.end());
        if(digits.size() > 0)
        {
            digits[0]++;
        }
        else
        {
            digits.push_back(1);
        }
        int remainder(digits[0] / 10);
        digits[0] %= 10;
        for(int i(1); i < digits.size(); i++)
        {
            digits[i] += remainder;
            remainder = digits[i] / 10;
            digits[i] %= 10;
        }
        if(remainder > 0)
        {
            digits.push_back(remainder);
        }
        std::reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec;
    {
        vec = {1,2,3};
        assert(sol.plusOne(vec) == std::vector<int>({1,2,4}));
    }
    {
        vec = {4,3,2,1};
        assert(sol.plusOne(vec) == std::vector<int>({4,3,2,2}));
    }
    {
        vec = {9};
        assert(sol.plusOne(vec) == std::vector<int>({1,0}));
    }

    return 0;
}