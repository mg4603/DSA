#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> subdomainVisits(
                        std::vector<std::string>& cpdomains) {
        std::unordered_map<std::string, int> mp;
        for(int i = 0; i < cpdomains.size(); i++) {
            int visits = std::stoi(cpdomains[i]);
            cpdomains[i] = 
                    cpdomains[i].substr(cpdomains[i].find(' ') + 1);
            while(cpdomains[i].find('.') != std::string::npos) {
                mp[cpdomains[i]] += visits;
                cpdomains[i] = 
                    cpdomains[i].substr(cpdomains[i].find('.') + 1);
            }
            mp[cpdomains[i]] += visits;
        }
        
        std::vector<std::string> res;
        for(auto &it: mp) {
            res.push_back(std::to_string(it.second) + ' ' + it.first);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> cpdomains = 
                            {"9001 discuss.leetcode.com"};
        std::vector<std::string> res = {"9001 com",
                                        "9001 leetcode.com", 
                                        "9001 discuss.leetcode.com"};
        assert(sol.subdomainVisits(cpdomains) == res);
    }
    return 0;
}