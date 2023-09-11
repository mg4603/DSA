#include <iostream>
#include <assert.h>

#include <map>

class Solution {
public:
    bool judgeCircle(std::string moves) {
        int horizontal(0);
        int vertical(0);
        std::map<char, int> move_mp{
            {'U', 1},
            {'D', -1},
            {'L', 1},
            {'R', -1}
        };
        for(char move: moves)
        {
            if(move == 'U' || move == 'D')
            {
                horizontal += move_mp[move];
            }
            if(move == 'L' || move == 'R')
            {
                vertical += move_mp[move];
            }
        }
        return horizontal == 0 && vertical == 0;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.judgeCircle("UD") == true);
        assert(sol.judgeCircle("LL") == false);
    }
    return 0;
}