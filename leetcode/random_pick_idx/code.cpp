#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <algorithm>
#include <vector>

class Solution {
    std::unordered_map<int, std::vector<int>> mp;
public:
    Solution(std::vector<int>& nums) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.count(nums[i]) == 0)
            {
                mp[nums[i]] = {};
            }
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) 
    {
        int n = mp[target].size();
        return mp[target][rand() % n];    
    }
};

int main()
{
    std::vector<int> vec{1, 2, 3, 3, 3};
    Solution solution(vec);
    std::vector<int> res3{2, 3, 4};
    std::vector<int> res1{0};
    assert(std::find(res3.begin(), res3.end(), 
                        solution.pick(3)) != 
                            res3.end());
                            
    assert(std::find(res1.begin(), res1.end(), 
                        solution.pick(1)) != 
                            res1.end());
                            
    assert(std::find(res3.begin(), res3.end(), 
                        solution.pick(3)) != 
                            res3.end());
                            

 
    return 0;
}