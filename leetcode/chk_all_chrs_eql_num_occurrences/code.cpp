#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool areOccurrencesEqual(std::string s) {
        std::ios_base::sync_with_stdio(0);
        std::vector<int> letters(26, 0);
        int occurrences = 0;
        for(int i = 0; i < s.length(); i++)
        {
            occurrences = ++ letters[s[i] - 'a'];
        }
        for(int i = 0; i < 26; i++)
        {
            if(letters[i] == 0)continue;
            if(letters[i] != occurrences)return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abacbc";
        bool res = true;
        assert(sol.areOccurrencesEqual(s) == res);
    }
    {
        std::string s = "aaabb";
        bool res = false;
        assert(sol.areOccurrencesEqual(s) == res);
    }
    return 0;
}