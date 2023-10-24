#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> twoOutOfThree(
                            std::vector<int>& nums1, 
                            std::vector<int>& nums2, 
                            std::vector<int>& nums3) 
    {
        std::unordered_set<int> st1;
        std::unordered_set<int> st2;
        std::unordered_set<int> st3;
        for(int i = 0; i < nums1.size(); i++)
        {
            st1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            st2.insert(nums2[i]);
        }
        for(int i = 0; i < nums3.size(); i++)
        {
            st3.insert(nums3[i]);
        }

        std::unordered_map<int, int> mp;
        for(auto it: st1)
        {
            mp[it]++;
        }
        for(auto it: st2)
        {
            mp[it]++;
        }
        for(auto it: st3)
        {
            mp[it]++;
        }
        std::vector<int> res;
        for(auto it: mp)
        {
            if(it.second >= 2)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> nums1 = {1,1,3,2};
        std::vector<int> nums2 = {2,3};
        std::vector<int> nums3 = {3};
        std::vector<int> res = {3,2};
        assert(sol.twoOutOfThree(nums1, nums2, nums3) == res);
    }
    {
        std::vector<int> nums1 = {3,1};
        std::vector<int> nums2 = {2,3};
        std::vector<int> nums3 = {1,2};
        std::vector<int> res = {2,3,1};
        assert(sol.twoOutOfThree(nums1, nums2, nums3) == res);
    }
    {
        std::vector<int> nums1 = {1,2,2};
        std::vector<int> nums2 = {4,3,3};
        std::vector<int> nums3 = {5};
        std::vector<int> res = {};
        assert(sol.twoOutOfThree(nums1, nums2, nums3) == res);
    }
    return 0;
}