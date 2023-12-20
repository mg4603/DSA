#include <iostream>
#include <assert.h>

#include <vector>
#include <limits>

class Solution {
public:
    int nextGreaterElement(int m) 
    {
        long n = m;    

        int prevRem = -1;
        int currRem = -1;
        std::vector<int> digits(10, 0);
        int flag = 1;

        while(n)
        {
            prevRem = currRem;
            currRem = n % 10;

            digits[currRem]++;
            n/=10;
            if(prevRem > currRem)
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            return -1;
        }

        for(int i = currRem + 1; i < 10; i++)
        {
            if(digits[i] > 0)
            {
                digits[i]--;
                n *= 10;
                n += i;
                break;
            }
        }

        for(int i = 0; i < 10; i++)
        {
            while(digits[i]-- > 0)
            {
                n *= 10;
                n += i;
            }
        }

        if(n > std::numeric_limits<int>::max())
        {
            return -1;
        }
        return n;

    }
};

int main()
{
    Solution sol;
    {
        int n = 12;
        int res = 21;
        assert(sol.nextGreaterElement(n) == res);
    }
    {
        int n = 21;
        int res = -1;
        assert(sol.nextGreaterElement(n) == res);
    }
    return 0;
}