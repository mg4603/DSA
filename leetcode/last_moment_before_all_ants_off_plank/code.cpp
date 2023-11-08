#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int getLastMoment(int n, std::vector<int>& left, 
                      std::vector<int>& right) 
    {
        int res = 0;
        for(int i = 0; i < left.size(); i++)
        {
            if(left[i] > res)
            {
                res = left[i];
            }
        }
        for(int i = 0; i < right.size(); i++)
        {
            if(n - right[i] > res)
            {
                res = n - right[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> left = {4,3};
        std::vector<int> right = {0,1};
        int n = 4;
        int res = 4;
        assert(sol.getLastMoment(n, left, right) == res);
    }
    {
        std::vector<int> left = {};
        std::vector<int> right = {0,1,2,3,4,5,6,7};
        int n = 7;
        int res = 7;
        assert(sol.getLastMoment(n, left, right) == res);
    }
    {
        std::vector<int> left = {0,1,2,3,4,5,6,7};
        std::vector<int> right = {};
        int n = 7;
        int res = 7;
        assert(sol.getLastMoment(n, left, right) == res);
    }
    return 0;
}