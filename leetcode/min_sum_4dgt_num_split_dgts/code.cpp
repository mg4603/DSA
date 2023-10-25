#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
    std::vector<int> getDigits(int num)
    {
        std::vector<int> digits(static_cast<int>(std::log10(num)) + 1, 0);
        int i = 0;
        while(num)
        {
            digits[i] = num % 10;
            num /= 10;
            i++;
        }
        return digits;
    }
public:
    int minimumSum(int num) {
        std::vector<int> digits = getDigits(num);
        std::sort(digits.begin(), digits.end());
        int a = 0;
        int b = 0;
        for(int i = 0; i < digits.size(); i += 2)
        {
            a *= 10;
            b *= 10;
            a += digits[i];
            if(i + 1 < digits.size())
            {
                b += digits[i + 1];
            }
        }
        return a + b;
    }
};

int main()
{
    Solution sol;
    {
        int num = 2932;
        int res = 52;
        assert(sol.minimumSum(num) == res);
    }
    {
        int num = 4009;
        int res = 13;
        assert(sol.minimumSum(num) == res);
    }
    return 0;
}