#include <iostream>
#include <assert.h>

int pick;

int guess(int num)
{
    if(num > pick)
    {
        return -1;
    }
    else if(num < pick)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int low(0);
        int high(n);
        
        while(low <= high)
        {
            int mid(low + (high - low) / 2);
            if(guess(mid) == 1)
            {
                low = mid + 1;
            }
            else if(guess(mid) == -1)
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    {
        pick = 6;
        assert(sol.guessNumber(10) == 6);
    }
    {
        pick = 1;
        assert(sol.guessNumber(1) == 1);
    }
    {
        pick = 1;
        assert(sol.guessNumber(2) == 1);
    }
    return 0;
}