#include <iostream>
#include <assert.h>

class Solution {
public:
    std::string reverseOnlyLetters(std::string s) {
        int i(0);
        int j(s.length() - 1);
        while(i < j)
        {
            if(isalpha(s[i]))
            {
                while(!isalpha(s[j]))
                {
                    j--;
                }
                std::swap(s[i], s[j]);
                j--;
            }
            i++;
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string str = "ab-cd";
        std::string rev_str = "dc-ba";
        assert(sol.reverseOnlyLetters(str) == rev_str);
    }
    {
        std::string str = "a-bC-dEf-ghIj";
        std::string rev_str = "j-Ih-gfE-dCba";
        assert(sol.reverseOnlyLetters(str) == rev_str);
    }
    {
        std::string str = "Test1ng-Leet=code-Q!";
        std::string rev_str = "Qedo1ct-eeLg=ntse-T!";
        assert(sol.reverseOnlyLetters(str) == rev_str);
    }
    return 0;
}