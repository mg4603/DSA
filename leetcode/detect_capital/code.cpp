#include <iostream>
#include <assert.h>

class Solution {
public:
    bool detectCapitalUse(std::string word) {
        int capNums(0);
        for(char ch: word)
        {
            if(isupper(ch))
            {
                capNums++;
            }
        }
        if(capNums == word.size())
        {
            return true;
        }
        if((isupper(word[0]) && capNums == 1) || capNums == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.detectCapitalUse("USA") == true);
        assert(sol.detectCapitalUse("FlaG") == false);
    }
    return 0;
}