#include <iostream>
#include <assert.h>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int n);

class Solution {
public:
    int firstBadVersion(int n) {

        if(n == 1)
        {
            return n;
        }

        int low(1);
        int high(n);

        while(low < high)
        {
            int mid = (low + (high - low) / 2);
            if(isBadVersion(mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int bad_ver(4);

bool isBadVersion(int n)
{
    return  n >= bad_ver;
}


int main()
{
    Solution sol;
    {
        assert(sol.firstBadVersion(5) == 4);
    }
    {
        bad_ver = 1;
        assert(sol.firstBadVersion(1) == 1);
    }
    
    return 0;
}