#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool isOneBitCharacter(std::vector<int>& bits) {
        int n = bits.size();
        int i(0);
        while(i < n)
        {
            if(bits[i] == 0)
            {
                if(i + 1 == n)
                {
                    return true;
                }
                i++;
            }
            if(bits[i] == 1)
            {
                i += 2;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> bits = {1,0,0};
        assert(sol.isOneBitCharacter(bits) == true);
    }
    {
        std::vector<int> bits = {1,1,1,0};
        assert(sol.isOneBitCharacter(bits) == false);
    }
    return 0;
}