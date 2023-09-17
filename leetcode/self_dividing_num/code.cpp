#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
    std::vector<int> getDigits(int num)
    {
        std::vector<int> digits;
        while(num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        return digits;
    }
public:
    std::vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> res;
        for(int i(left); i <= right; i++)
        {
            int cnt(0);
            for(int num: getDigits(i))
            {
                if(num && i % num == 0)
                {
                    cnt++;
                }
            }
            if(cnt == std::floor(std::log10(i)) + 1)
            {
                res.push_back(i);
            }

        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int left = 1;
        int right = 22;
        std::vector<int> res = {1,2,3,4,5,6,7,8,9,11,12,15,22};
        assert(sol.selfDividingNumbers(left, right) == res);
    }
    {
        int left = 47;
        int right = 85;
        std::vector<int> res = {48,55,66,77};
        assert(sol.selfDividingNumbers(left, right) == res);
    }
    return 0;
}