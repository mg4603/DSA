#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> evenOddBit(int n) 
    {
        int even = 0;
        int odd = 0;
        int cnt = 0;
        while(n)
        {
            if(n % 2 == 1)
            {
                if(cnt % 2 == 0)
                {
                    even++;
                }
                else
                {
                    odd++;
                }
            }
            n /= 2;
            cnt++;
        }
        return {even, odd};
    }
};

int main()
{
    Solution sol;
    {
        int n = 17;
        std::vector<int> res = {2, 0};
        assert(sol.evenOddBit(n) == res);
    }
    {
        int n = 2;
        std::vector<int> res = {0, 1};
        assert(sol.evenOddBit(n) == res);
    }
    return 0;
}