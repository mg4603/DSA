#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string originalDigits(std::string s) 
    {
        std::vector<int> count(10, 0);
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'z')
            {
                count[0]++;
            }
            else if(s[i] == 'o')
            {
                count[1]++;
            }
            else if(s[i] == 'w')
            {
                count[2]++;
            }
            else if(s[i] == 'h')
            {
                count[3]++;
            }
            else if(s[i] == 'u')
            {
                count[4]++;
            }
            else if(s[i] == 'f')
            {
                count[5]++;
            }
            else if(s[i] == 'x')
            {
                count[6]++;
            }
            else if(s[i] == 's')
            {
                count[7]++;
            }
            else if(s[i] == 'g')
            {
                count[8]++;
            }
            else if(s[i] == 'i')
            {
                count[9]++;
            }
        }

        count[5] -= count[4];
        count[7] -= count[6];
        count[3] -= count[8];
        count[1] -= (count[0] + count[2] + count[4]);
        count[9] -= (count[8] + count[6] + count[5]);

        std::string res;
        for(int i = 0; i <= 9; i++)
        {
            if(count[i] > 0)
            {
                res += std::string(count[i], '0' + i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "owoztneoer";
        std::string res = "012";
        assert(sol.originalDigits(s) == res);
    }
    {
        std::string s = "fviefuro";
        std::string res = "45";
        assert(sol.originalDigits(s) == res);
    }
    return 0;
}