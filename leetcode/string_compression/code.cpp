#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int compress(std::vector<char>& chars) 
    {
        std::vector<char> res;
        int count = 0;
        char ch = chars[0];

        for(int i = 0; i < chars.size(); i++)
        {
            if(chars[i] == ch)
            {
                count++;
            }
            else
            {
                res.push_back(ch);
                if(count > 1)
                {
                    for(char ch: std::to_string(count))
                    {
                        res.push_back(ch);
                    }
                }
                
                count = 1;
                ch = chars[i];
            }
        }

        res.push_back(ch);
        if(count > 1)
        {
            for(char ch: std::to_string(count))
            {
                res.push_back(ch);
            }
        }

        chars = res;
        return res.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<char> chars = {'a','a','b','b','c','c','c'};
        std::vector<char> res = {'a','2','b','2','c','3'};
        sol.compress(chars);
        assert(chars == res);
    }
    {
        std::vector<char> chars = {'a'};
        std::vector<char> res = {'a'};
        sol.compress(chars);
        assert(chars == res);
    }
    {
        std::vector<char> chars = {'a','b','b','b','b','b',
                                   'b','b','b','b','b','b','b'};
        std::vector<char> res = {'a','b','1','2'};
        sol.compress(chars);
        assert(chars == res);
    }
    return 0;
}