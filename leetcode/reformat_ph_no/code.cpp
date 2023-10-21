#include <iostream>
#include <assert.h>

#include <queue>

class Solution {
public:
    std::string reformatNumber(std::string number) 
    {
        std::queue<char> num;
        for(int i = 0; i < number.size(); i++)
        {
            if(std::isdigit(number[i]))
            {
                num.push(number[i]);
            }
        }

        int n = num.size();
        int remainder = 0;
        if(n % 3 == 2)
        {
            n -= 2;
            remainder = 2;
        }
        else if(n % 3 == 1)
        {
            n -= 4;
            remainder = 4;
        }

        std::string res;
        while(n)
        {
            for(int i = 0; i < 3; i++)
            {
                res += num.front();
                num.pop();
            }
            res += '-';
            n -= 3;
        }
        
        if(remainder == 0)
        {
            res.pop_back();
        }
        else if(remainder == 2)
        {
            for(int i = 0; i < 2; i++)
            {
                res += num.front();
                num.pop();
            }
        }
        else if(remainder == 4)
        {
            for(int i = 0; i < 2; i++)
            {
                if(i != 0)
                {
                    res += '-';
                }
                
                for(int j = 0; j < 2; j++)
                {
                    res += num.front();
                    num.pop();
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string number = "1-23-45 6";
        std::string res = "123-456";
        assert(sol.reformatNumber(number) == res);
    }
    {
        std::string number = "123 4-567";
        std::string res = "123-45-67";
        assert(sol.reformatNumber(number) == res);
    }
    {
        std::string number = "123 4-5678";
        std::string res = "123-456-78";
        assert(sol.reformatNumber(number) == res);
    }
    return 0;
}