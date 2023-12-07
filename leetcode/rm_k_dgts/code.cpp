#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) 
    {
        std::string res;
        int n = num.length();
        int i;

        for(i = 0; i < n; i++)
        {
            while(k > 0 && res.length() > 0 && num[i] < res.back())
            {
                k--;
                res.pop_back();
            }
            res += num[i];
        }

        i = 0;
        while(res[i] == '0')
        {
            i++;
        }

        res = res.substr(i);

        while(k-- > 0 && res.size())
        {
          res.pop_back();
        }

        if(res.length() == 0)
        {
            return "0";
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string num = "1432219";
        int k = 3;
        std::string res = "1219";
        assert(sol.removeKdigits(num, k) == res);
    }
    {
        std::string num = "10200";
        int k = 1;
        std::string res = "200";
        assert(sol.removeKdigits(num, k) == res);
    }
    {
        std::string num = "10";
        int k = 2;
        std::string res = "0";
        assert(sol.removeKdigits(num, k) == res);
    }
    return 0;
}