#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> goodDaysToRobBank(std::vector<int>& security, 
                                        int time) {
        std::ios::sync_with_stdio(0);
        int n = security.size();
        std::vector<int> increasing(n, 0);
        std::vector<int> decreasing(n, 0);

        for(int i = 1; i < n; i++)
        {
            if(security[i] <= security[i - 1])
            {
                decreasing[i] = decreasing[i - 1] + 1;
            }
            if(security[n - i] >= security[n - i - 1])
            {
                increasing[n - i - 1] = increasing[n - i] + 1;
            }
        }

        std::vector<int> res;
        for(int i = time; i < n - time; i++)
        {
            if(decreasing[i] >= time && increasing[i] >= time)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> security = {5,3,3,3,5,6,2};
        int time = 2;
        std::vector<int> res = {2, 3};
        assert(sol.goodDaysToRobBank(security, time) == res);
    }
    return 0;
}