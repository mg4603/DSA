#include <iostream>
#include <assert.h>

class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' ||
            ch == 'i' || ch == 'o' || 
            ch == 'u';
    }
public:
    bool doesAliceWin(std::string s) {
        std::ios::sync_with_stdio(0);
        int vowels = 0;
        for(int i = 0; i < s.length(); i++) {
            if(isVowel(s[i]))vowels++;
        }
        return (vowels > 0);
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "leetcoder";
        bool res = true;
        assert(sol.doesAliceWin(s) == res);
    }
    return 0;
}