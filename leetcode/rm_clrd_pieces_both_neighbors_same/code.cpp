#include <iostream>
#include <assert.h>

class Solution {
public:
    bool winnerOfGame(std::string colors) {
        std::ios::sync_with_stdio(0);
        if(colors.size() < 3)return 0;
        int alice = 0;
        int bob = 0;
        for(int i = 0; i < colors.size() - 2; i++) {
            if(colors[i] == colors[i + 1] && 
                colors[i + 1] == colors[i + 2]){
                if(colors[i] == 'A')alice++;
                else bob++;
            }
        }
        return alice > bob;
    }
};

int main()
{
    Solution sol;
    {
        std::string colors = "AAABABB";
        bool res = true;
        assert(sol.winnerOfGame(colors) == res);
    }
    return 0;
}