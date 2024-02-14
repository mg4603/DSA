#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
    bool helper(std::vector<int> &weights, 
                int days, int weight)
    {
        int day_cnt = 1;
        int total = 0;
        for(int i = 0; i < weights.size(); i++)
        {
            total += weights[i];
            if(total > weight)
            {
                total = weights[i];
                day_cnt++;
                if(day_cnt > days)
                {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int shipWithinDays(std::vector<int>& weights, 
                        int days) {
        int left = *std::max_element(weights.begin(), 
                                    weights.end());

        int right = std::accumulate(weights.begin(), 
                                    weights.end(), 0);

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(helper(weights, days, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
        int days = 5;
        int res = 15;
        assert(sol.shipWithinDays(weights, days) == res);
    }
    return 0;
}