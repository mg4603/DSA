#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int minimumRecolors(std::string blocks, int k) 
    {
        int res = 0;
        for(int i = 0; i < k; i++)
        {
            if(blocks[i] == 'W')
            {
                res++;
            }
        }

        int count = res;
        for(int i = k; i < blocks.length(); i++)
        {
            if(blocks[i - k] == 'W')
            {
                count--;
            }
            if(blocks[i] == 'W')
            {
                count++;
            }
            if(count < res)
            {
                res = count;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string blocks = "WBBWWBBWBW";
        int k = 7;
        int res = 3;
        assert(sol.minimumRecolors(blocks, k) == res);
    }
    {
        std::string blocks = "WBWBBBW";
        int k = 2;
        int res = 0;
        assert(sol.minimumRecolors(blocks, k) == res);
    }
    return 0;
}