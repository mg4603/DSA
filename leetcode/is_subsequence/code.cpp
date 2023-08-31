#include <iostream>
#include <assert.h>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int i(0);
        int j(0);
        while(i < s.size() && j < t.size())
        {
            if(s[i] == t[j])
            {
                i++;
            }
            j++;
            
        }
        return i == s.size();
    }
};

int main()
{
    Solution sol;
    {
        assert(sol.isSubsequence("abc", "ahbgdc"));
        assert(sol.isSubsequence("axc", "ahbgdc") == false);
    }
    return 0;
}