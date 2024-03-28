#include <iostream>
#include <assert.h>

class Solution {
public:
    int longestBeautifulSubstring(std::string word) {
        int res = 0;
        int cnt = 1;
        int curr_len = 1;

        for(int i = 1; i < word.size(); i++)
        {
            if(word[i] == word[i - 1])curr_len++;
            else if(word[i-1] < word[i])
            {
                curr_len++;
                cnt++;
            }
            else
            {
                cnt = 1;
                curr_len = 1;
            }
            
            if(cnt == 5)res = std::max(res, curr_len);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string word = "aeiaaioaaaaeiiiiouuuooaauuaeiu";
        int res = 13;
        assert(sol.longestBeautifulSubstring(word) == res);
    }
    return 0;
}