#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isPossible(std::vector<int>& nums) {

        std::unordered_map<int, int> freq;
        std::unordered_map<int, int> need;

        for(int num: nums)
        {
            freq[num]++;
        }

        for(int num: nums)
        {
            if(freq[num] == 0)continue;
            freq[num]--;

            if(need[num] > 0)
            {
                need[num]--;
                need[num + 1]++;
            }
            else if(freq[num + 1] && freq[num + 2])
            {
                freq[num + 1]--;
                freq[num + 2]--;
                need[num + 3]++;
            }
            else
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
        std::vector<int> nums = {1,2,3,3,4,5};
        bool res = true;
        assert(sol.isPossible(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,3,4,4,5,5};
        bool res = true;
        assert(sol.isPossible(nums) == res);
    }
    {
        std::vector<int> nums = {1,2,3,4,4,5};
        bool res = false;
        assert(sol.isPossible(nums) == res);
    }
    return 0;
}