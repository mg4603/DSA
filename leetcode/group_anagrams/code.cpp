#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(
                                            std::vector<std::string>& strs) 
    {
        std::map<std::vector<int>, std::vector<std::string>> mp;

        for(int i = 0; i < strs.size(); i++)
        {
            std::vector<int> freq(26, 0);
            for(int j = 0; j < strs[i].length(); j++)
            {
                freq[strs[i][j] - 'a']++;
            }
            mp[freq].push_back(strs[i]);
        }    
        std::vector<std::vector<std::string>> res;
        for(auto it: mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> strs = {""};
        std::vector<std::vector<std::string>> res = 
                            {{""}};
        assert(sol.groupAnagrams(strs) == res);
    }
    {
        std::vector<std::string> strs = {"a"};
        std::vector<std::vector<std::string>> res = 
                            {{"a"}};
        assert(sol.groupAnagrams(strs) == res);
    }
    {
        std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
        std::vector<std::vector<std::string>> res = 
                            {{"tan", "nat"},{"eat","tea","ate"},{"bat"}};
        assert(sol.groupAnagrams(strs) == res);
    }
    return 0;
}