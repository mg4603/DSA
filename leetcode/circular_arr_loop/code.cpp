#include <iostream>
#include <assert.h>

#include <unordered_set>
#include <vector>

class Solution {
public:
    bool circularArrayLoop(std::vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
        {
            return false;
        }

        std::unordered_set<int> visited;

        for(int i = 0; i < n; i++)
        {
            if(visited.find(i) == visited.end())
            {
                int prev = i;
                int curr = (nums[i] > 0) ? 
                                (i + nums[i]) % n : 
                                ((n + (i + nums[i]) % n) % n);

                std::unordered_set<int> cycle;
                cycle.insert(prev);
                visited.insert(prev);
                while(prev != curr && 
                      (nums[curr] > 0 == nums[prev] > 0))
                {
                    if(cycle.find(curr) != cycle.end())
                    {
                        return true;
                    }         
                    cycle.insert(curr);
                    visited.insert(curr);
                    prev = curr;
                    curr = (nums[prev] > 0) ? (prev + nums[prev]) % n :
                            ((n + (prev + nums[prev]) % n) % n);
                }
            }
        }
        return false;         
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {2,-1,1,2,2};
        bool res = true;
        assert(sol.circularArrayLoop(nums) == res);
    }
    {
        std::vector<int> nums = {-1,-2,-3,-4,-5,6};
        bool res = false;
        assert(sol.circularArrayLoop(nums) == res);
    }
    {
        std::vector<int> nums = {1,-1,5,1,4};
        bool res = true;
        assert(sol.circularArrayLoop(nums) == res);
    }
    return 0;
}