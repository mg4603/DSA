#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool isPalindrome(std::string s)
    {
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] != s[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    void helper(int i, int n, std::string s, 
                std::vector<std::string> &temp, 
                std::vector<std::vector<std::string>> &res)
    {
        if(i == n)
        {
            res.push_back(temp);
            return;
        }

        for(int j = 1; j <= n - i; j++)
        {
            std::string str = s.substr(i, j);
            if(isPalindrome(str))
            {
                temp.push_back(str);
                helper(i + j, n, s, temp, res);
                temp.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s) 
    {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> temp;
        int n = s.length();
        helper(0, n, s, temp, res);
        return res;        
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "aab";
        std::vector<std::vector<std::string>> res = {{"a","a","b"},
                                                     {"aa","b"}};
        assert(sol.partition(s) == res);
    }
    {
        std::string s = "a";
        std::vector<std::vector<std::string>> res = {{"a"}};
        assert(sol.partition(s) == res);
    }
    return 0;
}