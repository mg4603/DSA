#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool checkZeroOnes(std::string s) {
        std::vector<int> longest(2, 0);

        std::vector<int> current(2, 0);
        current[s[0] - '0']++;

        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == s[i - 1])
            {
                current[s[i] - '0']++;
            }

            if(s[i] != s[i - 1])
            {
                current[s[i] - '0'] = 1;
                if(current[s[i - 1] - '0'] > longest[s[i - 1] - '0'])
                {
                    longest[s[i - 1] - '0'] = current[s[i - 1] - '0'];
                }
            }
        }
        
        if(current[s.back() - '0'] > longest[s.back() - '0'])
        {
            longest[s.back() - '0'] = current[s.back() - '0'];
        }
        return longest[1] > longest[0];

    }
};

int main()
{
    Solution sol;
    {
        std::string s = "1101";
        int res = 1;
        assert(sol.checkZeroOnes(s) == res);
    }
    {
        std::string s = "111000";
        int res = 0;
        assert(sol.checkZeroOnes(s) == res);
    }
    {
        std::string s = "110100010";
        int res = 0;
        assert(sol.checkZeroOnes(s) == res);
    }
    return 0;
}