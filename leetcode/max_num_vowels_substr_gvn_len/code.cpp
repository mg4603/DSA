#include <iostream>
#include <assert.h>

class Solution {
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || 
                ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int maxVowels(std::string s, int k) {
        int res = 0;
        int cnt = 0;
        for(int i = 0; i < k; i++)
        {
            if(isVowel(s[i]))cnt++;
        }
        res = std::max(res, cnt);

        for(int i = k; i < s.length(); i++)
        {
            if(isVowel(s[i]))cnt++;
            if(isVowel(s[i - k]))cnt--;
            res = std::max(res, cnt);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "abciiidef";
        int k = 3;
        int res = 3;
        assert(sol.maxVowels(s, k) == res);
    }
    return 0;
}