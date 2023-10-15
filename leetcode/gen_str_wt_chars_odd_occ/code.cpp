#include <iostream>
#include <assert.h>

#include <unordered_map>

class Solution {
public:
    std::string generateTheString(int n) {
        std::string res;
        if(n % 2 == 0)
        {
            res = std::string(n - 1, 'a');
            res += 'b';
        }
        else
        {
            res = std::string(n, 'a');
        }
        return res;
    }
};

void checkAns(std::string res)
{
    std::unordered_map<char, int> mp;
    for(int i = 0; i < res.length(); i++)
    {
        mp[res[i]]++;
    }
    for(auto pair: mp)
    {
        assert(pair.second % 2 == 1);
    }
}

int main()
{
    Solution sol;
    {
        int n = 4;
        std::string res = sol.generateTheString(n);
        checkAns(res);
    }
    {
        int n = 2;
        std::string res = sol.generateTheString(n);
        checkAns(res);
    }
    {
        int n = 7;
        std::string res = sol.generateTheString(n);
        checkAns(res);
    }
    return 0;
}