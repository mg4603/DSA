#include <iostream>
#include <assert.h>

class Solution {
public:
    bool halvesAreAlike(std::string s) {
        std::ios_base::sync_with_stdio(0);

        std::string vowels = "aeiouAEIOU";

        int n = s.length();
        int first = 0;
        for(int i = 0; i < n/ 2; i++)
        {
            if(vowels.find(s[i]) != std::string::npos)
            {
                first++;
            }
        }
        int second = 0;
        for(int i = n/2; i < n; i++)
        {
            if(vowels.find(s[i]) != std::string::npos)
            {
                second++;
            }
        }
        return first == second;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "book";
        bool res = true;
        assert(sol.halvesAreAlike(s) == res);
    }
    {
        std::string s = "textbook";
        bool res = false;
        assert(sol.halvesAreAlike(s) == res);
    }
    return 0;
}