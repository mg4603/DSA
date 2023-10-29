#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int splitNum(int num) {
        std::vector<int> digits;
        while(num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        std::sort(digits.begin(), digits.end());
        
        int num1 = 0;
        int num2 = 0;

        for(int i = 0; i < digits.size(); i += 2)
        {
            num1 *= 10;
            num1 += digits[i];
            if(i + 1 < digits.size())
            {
                num2 *= 10;
                num2 += digits[i + 1];        
            }
        }
        return num1 + num2;
    }
};

int main()
{
    Solution sol;
    {
        int num = 4325;
        int res = 59;
        assert(sol.splitNum(num) == res);
    }
    {
        int num = 687;
        int res = 75;
        assert(sol.splitNum(num) == res);
    }
    return 0;
}