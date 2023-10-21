#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minOperations(std::string s) {
        std::vector<char> start0 = {'0', '1'};
        std::vector<char> start1 = {'1', '0'};
        int flips0 = 0;
        int flips1 = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != start0[i%2])
            {
                flips0++;
            }
            if(s[i] != start1[i%2])
            {
                flips1++;
            }
        }
        return std::min(flips0, flips1);
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "0100";
        int res = 1;
        assert(sol.minOperations(s) == res);
    }
    {
        std::string s = "10";
        int res = 0;
        assert(sol.minOperations(s) == res);
    }
    {
        std::string s = "1111";
        int res = 2;
        assert(sol.minOperations(s) == res);
    }
    return 0;
}