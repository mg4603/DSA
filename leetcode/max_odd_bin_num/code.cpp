#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string maximumOddBinaryNumber(std::string s) 
    {
        int n = s.length();
        std::string res(n, '0');
        
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                cnt++;
            }
        }

        cnt -= 1;
        res[n - 1] = '1';

        for(int i = 0; i < cnt; i++)
        {
            res[i] = '1';
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "010";
        std::string res = "001";
        assert(sol.maximumOddBinaryNumber(s) == res);
    }
    {
        std::string s = "0101";
        std::string res = "1001";
        assert(sol.maximumOddBinaryNumber(s) == res);
    }
    return 0;
}