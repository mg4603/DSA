#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string evaluate(std::string s,  
            std::vector<std::vector<std::string>>& knowledge) {
        std::ios::sync_with_stdio(0);
        std::unordered_map<std::string, std::string> mp;

        for(std::vector<std::string> & it: knowledge) {
                mp[it[0]] = it[1];
        }

        int flag = 0;
        std::string res;
        std::string temp;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '('){
                flag = 1;
                continue;
            }
            if(s[i] == ')'){
                flag = 0;
                if(mp.count(temp))res += mp[temp];
                else res += "?";
                temp = "";
                continue;
            }
            if(flag) {
                temp += s[i];
            }else {
                res += s[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "(name)is(age)yearsold";
        std::vector<std::vector<std::string>> knowledge = 
                            {{"name","bob"},{"age","two"}};
        std::string res = "bobistwoyearsold";
        assert(sol.evaluate(s, knowledge) == res);
    }
    return 0;
}