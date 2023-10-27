#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> answerQueries(std::vector<int>& nums, 
                                    std::vector<int>& queries) 
    {
        int q_size = queries.size();
        int n_size = nums.size();

        std::sort(nums.begin(), nums.end());
        std::vector<int> res(q_size, -1);

        for(int i = 1; i < n_size; i++)
        {
            nums[i] += nums[i - 1];
        }
        
        for(int i = 0; i < q_size; i++)
        {
            for(int j = 0; j < n_size; j++)
            {
                if(queries[i] < nums[j])
                {
                    res[i] = j;
                    break;
                }
            }
            if(res[i] == -1)
            {
                res[i] = n_size;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {4,5,2,1};
        std::vector<int> queries = {3,10,21};
        std::vector<int> res = {2,3,4};
        assert(sol.answerQueries(nums, queries) == res);
    }
    {
        std::vector<int> nums = {2,3,4,5};
        std::vector<int> queries = {1};
        std::vector<int> res = {0};
        assert(sol.answerQueries(nums, queries) == res);
    }
    return 0;
}