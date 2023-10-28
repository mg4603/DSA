#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maximumValue(std::vector<std::string>& strs) 
    {
        int res = 0;
        for(int i = 0; i < strs.size(); i++)
        {
            int digits = 0;
            for(int j = 0; j < strs[i].size(); j++)
            {
                if(std::isdigit(strs[i][j]))
                {
                    digits++;                    
                }
            }
            int length = strs[i].length();
            int val = 0;
            if(digits == length)
            {
                val = std::stoi(strs[i]);
            }
            else
            {
                val = length;
            }
            if(val > res)
            {
                res = val;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> strs = {"alic3","bob","3","4","0000"};
        int res = 5;
        assert(sol.maximumValue(strs) == res);
    }
    {
        std::vector<std::string> strs = {"1","01","001","0001"};
        int res = 1;
        assert(sol.maximumValue(strs) == res);
    }
    return 0;
}