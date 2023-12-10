#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) 
    {
        std::vector<int> res;
        int s_len = s.length();
        int p_len = p.length();

        if(p_len > s_len)
        {
            return {};
        }
        
        std::vector<int> p_freq(26, 0);
        std::vector<int> s_freq(26, 0);


        for(int i = 0; i < p_len; i++)
        {
            p_freq[p[i] - 'a']++;
            s_freq[s[i] - 'a']++;
        }

        int flag = 1;
        for(int j = 0; j < 26; j++)
        {
            if(s_freq[j] != p_freq[j])
            {
                flag = 0;
            }
        }
        if(flag)
        {
            res.push_back(0);
        }

        for(int i = 1; i < s_len - p_len + 1; i++)
        {
            s_freq[s[i-1] - 'a']--;
            s_freq[s[i + p_len - 1] - 'a']++;

            flag = 1;
            for(int j = 0; j < 26; j++)
            {
                if(s_freq[j] != p_freq[j])
                {
                    flag = 0;
                }
            }
            if(flag)res.push_back(i);

        }
        return res;    
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "cbaebabacd";
        std::string p = "abc";
        std::vector<int> res = {0,6};
        assert(sol.findAnagrams(s, p) == res);
    }
    {
        std::string s = "abab";
        std::string p = "ab";
        std::vector<int> res = {0,1,2};
        assert(sol.findAnagrams(s, p) == res);
    }
    return 0;
}