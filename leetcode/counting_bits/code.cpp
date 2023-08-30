#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    int getNumOnBits(int num)
    {
        int count(0);
        while(num)
        {
            if(num % 2 == 1)
            {
                count++;
            }
            num /= 2;
        }
        return count;
    }
public:
    std::vector<int> countBits(int n) {
        std::vector<int> res;
        for(int i(0); i <= n; i++)
        {
            res.push_back(getNumOnBits(i));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.countBits(3) == std::vector<int>({0, 1, 1}));
        assert(sol.countBits(5) == std::vector<int>({0,1,1,2,1,2}));
    }
    return 0;
}