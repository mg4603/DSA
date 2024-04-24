#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    char shift(char c, int num)
    {
        return (((c - 'a') + num) % 26) + 'a';
    }

public:
    std::string shiftingLetters(std::string s, std::vector<int>& shifts) {
        std::ios::sync_with_stdio(0);
        int n = s.length();
        for(int i = n - 2; i >= 0; i--)    
        {
            shifts[i] += shifts[i + 1];
            shifts[i] %= 26;
        }

        for(int i = 0; i < n; i++)
        {
            s[i] = shift(s[i], shifts[i]);
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abc";
        std::vector<int> shifts = {3,5,9};
        std::string res = "rpl";
        assert(sol.shiftingLetters(s, shifts) == res);
    }
    return 0;
}