#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0)
        {
            return 0;
        }
        std::vector<int> vec(n + 1, 0);
        
        vec[0] = 0;
        vec[1] = 1;
        int res = 1;
        for(int i = 2; i < n + 1; i++)
        {
            if(i % 2 == 0)
            {
                vec[i] = vec[i / 2];
            }
            else
            {
                int temp = i / 2;
                vec[i] = vec[temp] + vec[temp + 1];
            }
            if(vec[i] > res)
            {
                res = vec[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 7;
        int res = 3;
        assert(sol.getMaximumGenerated(n) == res);
    }
    {
        int n = 2;
        int res = 1;
        assert(sol.getMaximumGenerated(n) == res);
    }
    {
        int n = 3;
        int res = 2;
        assert(sol.getMaximumGenerated(n) == res);
    }
    return 0;
}