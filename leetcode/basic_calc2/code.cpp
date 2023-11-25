#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int calculate(std::string s) 
    {
        s += '+';
        int res = 0;
        int curr = 0;
        
        char op = '+';
        std::vector<int> vec;

        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                curr *= 10;
                curr += (s[i] - '0');
            }
            else if(s[i] != ' ')
            {
                if(op == '*')
                {
                    curr *= vec.back();
                    vec.pop_back();
                }
                else if(op == '/')
                {
                    curr = vec.back() / curr;
                    vec.pop_back();
                }
                else if(op == '-')
                {
                    curr = -curr;
                } 
                vec.push_back(curr);
                op = s[i];
                curr = 0;
            }
        }

        for(int i = 0; i < vec.size(); i++)
        {
            res += vec[i];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "3+2*2";
        int res = 7;
        assert(sol.calculate(s) == res);
    }
    {
        std::string s = " 3/2 ";
        int res = 1;
        assert(sol.calculate(s) == res);
    }
    {
        std::string s = " 3+5 / 2 ";
        int res = 5;
        assert(sol.calculate(s) == res);
    }
    return 0;
}