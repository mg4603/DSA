#include <iostream>
#include <assert.h>

class Solution {
public:
    int percentageLetter(std::string s, char letter) 
    {
        int cnt = 0;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == letter)
            {
                cnt++;
            }
        }
        return (cnt / static_cast<double>(n)) * 100;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "foobar";
        char letter = 'o';
        int res = 33;
        assert(sol.percentageLetter(s, letter) == res);
    }
    {
        std::string s = "jjjj";
        char letter = 'k';
        int res = 0;
        assert(sol.percentageLetter(s, letter) == res);
    }
    return 0;
}