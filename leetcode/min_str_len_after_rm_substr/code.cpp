#include <iostream>
#include <assert.h>

class Solution {
public:
    int minLength(std::string s) 
    {
        std::string res;
        for(int i = 0; i < s.length(); i++)
        {
            if(res != "")
            {
                if(s[i] == 'B' && res.back() == 'A')
                {
                    res.pop_back();
                }
                else if(s[i] == 'D' && res.back() == 'C')
                {
                    res.pop_back();
                }
                else
                {
                    res += s[i];
                }
            }
            else
            {
                res += s[i];
            }
        }
        return res.length();
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "ABFCACDB";
        int res = 2;
        assert(sol.minLength(s) == res);
    }
    {
        std::string s = "ACBBD";
        int res = 5;
        assert(sol.minLength(s) == res);
    }
    return 0;
}