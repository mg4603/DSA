#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        int i(0); 
        int j(s.size() - 1);
        std::string vowels = "aeiou";
        while(i < j)
        {
            if(vowels.find(std::tolower(s[i])) == std::string::npos)
            {
                i++;
            }
            else if(vowels.find(std::tolower(s[j])) == std::string::npos)
            {
                j--;
            }
            else
            {
                std::swap(s[i++], s[j--]);
            }

        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.reverseVowels("hello") == "holle");
        assert(sol.reverseVowels("leetcode") == "leotcede");
    }
    return 0;
}