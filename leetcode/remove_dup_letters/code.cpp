#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) 
    {
        std::vector<int> freq(26, 0);
        std::vector<int> visited(26, 0);

        int n = s.length();

        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        std::string res;

        for(int i = 0; i < n; i++)
        {
            if(res.size() == 0)
            {
                res += s[i];
                visited[s[i] - 'a'] = 1;
                freq[s[i] - 'a']--;
                continue;
            }

            if(res.back() == s[i])
            {
                freq[s[i] - 'a']--;
                continue;
            }

            char temp = res.back();
            while(visited[s[i] - 'a'] == 0 && freq[temp - 'a'] != 0 && s[i] < temp)
            {
                visited[temp - 'a'] = 0;
                res.pop_back();
                if(res.size() == 0)
                {
                    break;
                }
                temp = res.back();
            }

            if(visited[s[i] - 'a'] == 0)
            {
                res += s[i];
                visited[s[i] - 'a'] = 1;
                freq[s[i] - 'a']--;
            }
            else
            {
                freq[s[i] - 'a']--;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "bcabc";
        std::string res = "abc";
        assert(sol.removeDuplicateLetters(s) == res);
    }
    {
        std::string s = "cbacdcbc";
        std::string res = "acdb";
        assert(sol.removeDuplicateLetters(s) == res);
    }
    return 0;
}