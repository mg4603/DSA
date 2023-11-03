#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string countAndSay(int n) 
    {
        std::string res = "1";
        for(int i = 1; i < n; i++)
        {
            std::string temp;
            int count = 1;
            char prev = res[0];
            for(int j = 1; j < res.length(); j++)
            {
                if(res[j] == prev)
                {
                    count++;
                }
                else
                {
                    temp += std::to_string(count);
                    temp += prev;
                    prev = res[j];
                    count = 1;
                }
            }
            if(count > 0)
            {
                temp += std::to_string(count);
                temp += prev;
            }
            res = temp;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int n = 1;
        std::string res = "1";
        assert(sol.countAndSay(n) == res);
    }
    {
        int n = 4;
        std::string res = "1211";
        assert(sol.countAndSay(n) == res);
    }
    return 0;
}