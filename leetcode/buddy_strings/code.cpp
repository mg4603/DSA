#include <iostream>
#include <assert.h>

#include <set>
#include <vector>

class Solution {
public:
    bool buddyStrings(std::string s, std::string t) {
        if(s.size() != t.size() || s.size() < 1)
        {
            return false;
        }

        if(s == t)
        {
            std::set<char> distinctChars;
            for(char ch: s)
            {
                distinctChars.insert(ch);
            }
            return distinctChars.size() < s.size();
        }

        std::vector<int> diff;
        for(int i(0); i < s.size(); i++)
        {
            if(s[i] != t[i])
            {
                diff.push_back(i);
            }
        }
        if(diff.size() != 2)
        {
            return false;
        }
        std::swap(s[diff[0]], s[diff[1]]);
        return s == t;
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.buddyStrings("ab", "ba") == true);
        assert(sol.buddyStrings("ab", "ab") == false);
        assert(sol.buddyStrings("aa", "aa") == true);
    }
    return 0;
}