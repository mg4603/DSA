#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string temp;
        for(char c: s)
        {
            if(isalnum(c))
            {
                if(isupper(c))
                {
                    temp += tolower(c);
                }
                else
                {
                    temp += c;
                }
            }
        }
        for(int i(0); i < temp.size() / 2; i++)
        {
            if(temp[i] != temp[temp.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.isPalindrome("A man, a plan, a canal: Panama") == true);
    }
    {
        assert(sol.isPalindrome("race a car") == false);
    }
    {
        assert(sol.isPalindrome(" ") == true);
    }
    return 0;
}