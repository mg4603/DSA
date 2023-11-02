#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> lastVisitedIntegers(std::vector<std::string>& words) 
    {
        std::vector<int> nums;
        std::vector<int> res;

        int count = 0;

        for(int i = 0; i < words.size(); i++)
        {
            try
            {
                int temp = std::stoi(words[i]);
                nums.push_back(temp);
                count = 0;
            }
            catch(...)
            {
                count++;
                int n = nums.size();
                if(count > n)
                {
                    res.push_back(-1);
                }
                else
                {
                    res.push_back(nums[nums.size() - count]);
                }
            }
        }    
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"1","2","prev","prev","prev"};
        std::vector<int> res = {2,1,-1};

        assert(sol.lastVisitedIntegers(words) == res);
    }
    {
        std::vector<std::string> words = {"1","prev","2","prev","prev"};
        std::vector<int> res = {1,2,1};
        
        assert(sol.lastVisitedIntegers(words) == res);
    }
    return 0;
}