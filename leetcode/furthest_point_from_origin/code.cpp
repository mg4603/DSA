#include <iostream>
#include <assert.h>

class Solution {
public:
    int furthestDistanceFromOrigin(std::string moves) {
        int l(0);
        int r(0);
        for(char c: moves)
        {
            if(c == 'L')
            {
                l++;
            }
            else if(c == 'R')
            {
                r++;
            }
            
        }
        return moves.size() - 2 * std::min(l, r);
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.furthestDistanceFromOrigin("L_RL__R") == 3);
        assert(sol.furthestDistanceFromOrigin("_R__LL_") == 5);
        assert(sol.furthestDistanceFromOrigin("_______") == 7);
    }
    return 0;
}