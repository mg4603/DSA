#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> arrayChange(std::vector<int>& nums, 
                    std::vector<std::vector<int>>& operations) {
        std::ios::sync_with_stdio(0);
        std::unordered_map<int, int> f_mp;
        std::unordered_map<int, int> b_mp;

        for(std::vector<int> &op: operations) {
            if(b_mp.count(op[0])) {
                f_mp[b_mp[op[0]]] = op[1];
                b_mp[op[1]] = b_mp[op[0]];
            }
            else {
                f_mp[op[0]] = op[1];
                b_mp[op[1]] = op[0];
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!f_mp.count(nums[i]))continue;
            nums[i] = f_mp[nums[i]];
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums = {1,2,4,6};
        std::vector<std::vector<int>> operations = {{1,3},{4,7},{6,1}};
        std::vector<int> res = {3,2,7,1};
        assert(sol.arrayChange(nums, operations) == res);
    }
    return 0;
}