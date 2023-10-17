#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string reformat(std::string s) {
        std::string alpha;
        std::string num;
        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i]))
            {
                alpha += s[i];
            }
            else
            {
                num += s[i];
            }
        }
        std::string res = "";

        if(std::abs(static_cast<int>(alpha.length()) - 
            static_cast<int>(num.length())) > 1)
        {
            return res;
        }
        int i = 0;
        int j = 0;
        if(alpha.length() > num.length())
        {
            res += alpha[i++];
            while(i < alpha.length() && j < num.length())
            {
                res += num[j++];
                res += alpha[i++];
            }
        }
        else if(num.length() > alpha.length())
        {
            res += num[j++];
            while(i < alpha.length() && j < num.length())
            {
                res += alpha[i++];
                res += num[j++];
            }
        }
        else
        {
            while(i < alpha.length() && j < num.length())
            {
                res += alpha[i++];
                res += num[j++];
            }
        }
       
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "a0b1c2";
        std::string res = "0a1b2c";
        assert(sol.reformat(s) == res);
    }
    {
        std::string s = "leetcode";
        std::string res = "";
        assert(sol.reformat(s) == res);
    }
    {
        std::string s = "1229857369";
        std::string res = "";
        assert(sol.reformat(s) == res);
    }
    return 0;
}