#include <iostream>
#include <assert.h>

class Solution {
public:
    int binaryGap(int n) {
        std::string bin;
        while(n)
        {
            bin = std::to_string(n % 2) + bin;
            n /= 2;
        }
        int l(0);
        int max_gap(0);
        for(char ch: bin)
        {
            if(ch == '1')
            {
                if(l > max_gap)
                {
                    max_gap = l;
                }
                l = 0;
            }
            l++;
        }
        if(max_gap == bin.length())
        {
            return 0;
        }
        return max_gap;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.binaryGap(22) == 2);
        assert(sol.binaryGap(8) == 0);
        assert(sol.binaryGap(5) == 2);
    }
    return 0;
}