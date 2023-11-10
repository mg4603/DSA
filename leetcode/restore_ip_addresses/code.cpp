#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    void helper(std::vector<std::string> &res, std::string s,  
                int start, std::vector<std::string> temp)
    {
        if(start == s.length())
        {
            if(temp.size() == 4)
            {
                std::string str;
                for(int i = 0; i < 4; i++)
                {
                    if(i != 0)
                    {
                        str += '.';
                    }
                    str += temp[i];
                }
                res.push_back(str);
            }
            return;
        }

        if(start < s.length() && temp.size() == 4)
        {
            return;
        }

        if(s[start] == '0')
        {
            temp.push_back("0");
            helper(res, s, start + 1, temp);
            temp.pop_back();
        }
        else
        {
            for(int i = 1; i <= s.length() - start; i++)
            {
                std::string str = s.substr(start, i);
                if(std::stoi(str) >= 0 && std::stoi(str) <= 255)
                {
                    temp.push_back(str);
                    helper(res, s, start + i, temp);
                    temp.pop_back();
                }
                else
                {
                    break;
                }
            }
        }
    }
public:
    std::vector<std::string> restoreIpAddresses(std::string s) 
    {
        std::vector<std::string> res;
        helper(res, s, 0, {});
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "25525511135";
        std::vector<std::string> res = {"255.255.11.135","255.255.111.35"};
        assert(sol.restoreIpAddresses(s) == res);
    }
    {
        std::string s = "0000";
        std::vector<std::string> res = {"0.0.0.0"};
        assert(sol.restoreIpAddresses(s) == res);
    }
    {
        std::string s = "101023";
        std::vector<std::string> res = {"1.0.10.23","1.0.102.3",
                                        "10.1.0.23","10.10.2.3",
                                        "101.0.2.3"};
        assert(sol.restoreIpAddresses(s) == res);
    }
    return 0;
}