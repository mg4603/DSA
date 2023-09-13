#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool hasAlternatingBits(int n) {
        std::vector<bool> bin;
        while(n)
        {
            bin.push_back(n % 2);
            n /= 2;
        }
        for(int i(1); i < bin.size(); i++)
        {
            if(bin[i] ^ bin[i - 1] == 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {

        assert(sol.hasAlternatingBits(5) == true);
        assert(sol.hasAlternatingBits(7) == false);
        assert(sol.hasAlternatingBits(11) == false);
    }
    return 0;
}