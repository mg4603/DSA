#include <iostream>
#include <assert.h>

class Solution {
    std::string transform(std::string num)
    {
        int res = 0;
        for(int i = 0; i < num.length(); i++)
        {
            res += (num[i] - '0');
        }
        return std::to_string(res);
    }
public:
    int getLucky(std::string s, int k) 
    {
        std::ios_base::sync_with_stdio(0);
        std::string num;
        for(int i = 0; i < s.length(); i++)
        {
            num += std::to_string(s[i] - 'a' + 1);
        }
        while(k--)
        {
            num = transform(num);
        }
        return std::stoi(num);
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "iiii";
        int k = 1;
        int res = 36;
        assert(sol.getLucky(s, k) == res);
    }
    {
        std::string s = "leetcode";
        int k = 2;
        int res = 6;
        assert(sol.getLucky(s, k) == res);
    }
    {
        std::string s = "zbax";
        int k = 2;
        int res = 8;
        assert(sol.getLucky(s, k) == res);
    }
    return 0;
}