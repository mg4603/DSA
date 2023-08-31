#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::vector<int> magazineChars(26, 0);
        for(char ch: magazine)
        {
            magazineChars[ch - 'a']++;
        }
        for(char ch: ransomNote)
        {
            if(magazineChars[ch - 'a'] <= 0)
            {
                return false;
            }
            else
            {
                magazineChars[ch - 'a']--;
            }

        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.canConstruct("a", "b") == false);
        assert(sol.canConstruct("aa", "ab") == false);
        assert(sol.canConstruct("aa", "aab") == true);
    }
    return 0;
}