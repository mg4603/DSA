#include <iostream>
#include <assert.h>

class Solution {
public:
    bool canBeEqual(std::string s1, std::string s2) {
        if(s1 == s2)
        {
            return true;
        }
        int i(0);
        int j(2);
        while(i < 4 && j < 4)
        {
            if(s1[i] == s2[i])
            {
                i++;
                j++;
            }
            else
            {
                if(s2[i] != s1[j])
                {
                    return false;
                }
                else
                {
                    std::swap(s1[i++], s1[j++]);
                }
            }
        }
        return s1 == s2;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.canBeEqual("abcd", "cdab") == true);
        assert(sol.canBeEqual("abcd", "dacb") == false);
    }
    return 0;
}