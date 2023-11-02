#include <iostream>
#include <assert.h>

#include <numeric>
#include <cmath>

class Solution {
public:
    int countSymmetricIntegers(int low, int high) 
    {
        int res = 0;
        for(int i = low; i <= high; i++)
        {
            if(static_cast<int>(std::log10(i)) % 2 == 0)continue;
            std::string temp = std::to_string(i);
            int n = temp.length() / 2;
            if(std::accumulate(temp.begin(), temp.begin() + n, 0) ==
                 std::accumulate(temp.begin() + n, temp.end(), 0))
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int low = 1;
        int high = 100;
        int res = 9;
        assert(sol.countSymmetricIntegers(low, high) == res);
    }
    {
        int low = 1200;
        int high = 1230;
        int res = 4;
        assert(sol.countSymmetricIntegers(low, high) == res);
    }
    return 0;
}