#include <iostream>
#include <assert.h>

class Solution {
    void helper(std::string s, int i, int j, int &cnt)
    {
        while(i >= 0 && j < s.length() && s[i] == s[j])
        {
            cnt++;
            i--;
            j++;
        }
    }
public:
    int countSubstrings(std::string s) 
    {
        if(s.length() == 0)
        {
            return 0;
        }
        int res = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            helper(s, i, i, res);
            helper(s, i, i + 1, res);
        }
        return res;      
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abc";
        int res = 3;
        assert(sol.countSubstrings(s) == res);
    }
    {
        std::string s = "aaa";
        int res = 6;
        assert(sol.countSubstrings(s) == res);
    }
    return 0;
}