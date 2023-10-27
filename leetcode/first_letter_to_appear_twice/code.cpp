#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    char repeatedCharacter(std::string s) 
    {
        std::vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++)
        {
            int temp = ++freq[s[i] - 'a'];
            if(temp == 2)
            {
                return s[i];
            }
        }    
        return ' ';
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abccbaacz";
        char res = 'c';
        assert(sol.repeatedCharacter(s) == res);
    }
    {
        std::string s = "abcdd";
        char res = 'd';
        assert(sol.repeatedCharacter(s) == res);
    }
    return 0;
}