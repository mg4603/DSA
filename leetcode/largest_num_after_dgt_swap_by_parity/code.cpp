#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int largestInteger(int num) {
        std::vector<int> odds;
        std::vector<int> evens;
        std::vector<int> digits;
        while(num)
        {
            int temp = (num % 10);
            if(temp % 2 == 1)
            {
                odds.push_back(temp);
            }
            else
            {
                evens.push_back(temp);
            }
            digits.push_back(temp);
            num /= 10;
        }

        std::sort(odds.begin(), odds.end(), std::greater<int>());
        std::sort(evens.begin(), evens.end(), std::greater<int>());

        int res = 0;
        int even_ptr = 0;
        int odd_ptr = 0;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            res *= 10;
            if(digits[i] % 2 == 0)
            {
                res += evens[even_ptr++]; 
            }
            else
            {
                res += odds[odd_ptr++];
            }
        }
        return res;

    }
};

int main()
{
    Solution sol;
    {
        int num = 1234;
        int res = 3412;
        assert(sol.largestInteger(num) == res);
    }
    {
        int num = 65875;
        int res = 87655;
        assert(sol.largestInteger(num) == res);
    }
    return 0;
}