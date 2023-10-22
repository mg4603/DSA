#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    int countMatches(std::vector<std::vector<std::string>>& items, 
                     std::string ruleKey, std::string ruleValue) {
        int res = 0;
        std::map<std::string, int> key_mp{
                {"type", 0}, {"color", 1}, {"name", 2}};
        int key_idx = key_mp[ruleKey];
        for(int i = 0; i < items.size(); i++)
        {
            if(items[i][key_idx] == ruleValue)
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<std::string>> items = {
            {"phone","blue","pixel"},{"computer","silver","lenovo"},
            {"phone","gold","iphone"}};
        std::string ruleKey = "color";
        std::string ruleValue = "silver";
        int res = 1;
        assert(sol.countMatches(items, ruleKey, ruleValue) == res);
    }
    {
        std::vector<std::vector<std::string>> items = {
            {"phone","blue","pixel"},{"computer","silver","phone"},
            {"phone","gold","iphone"}};
        std::string ruleKey = "type";
        std::string ruleValue = "phone";
        int res = 2;
        assert(sol.countMatches(items, ruleKey, ruleValue) == res);
    }
    return 0;
}