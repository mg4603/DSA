#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool equalFrequency(std::string word) 
    {
        std::vector<int> freq(26, 0);
        int n = word.length();
        for(int i = 0; i < n; i++)
        {
            freq[word[i] - 'a']++;
        }

        for(int i = 0; i < n; i++)
        {
            freq[word[i] - 'a']--;
            int prev = 0;
            int cnt_non_zero = 0;
            int cnt_freq_prev = 0;
            for(int j = 0; j < 26; j++)
            {
                if(freq[j] == 0)continue;
                cnt_non_zero++;
                if(prev == 0)
                {
                    prev = freq[j];
                    cnt_freq_prev++;
                    continue;
                }
                else if(prev == freq[j])
                {
                    cnt_freq_prev++;
                }
            }

            if(cnt_non_zero == cnt_freq_prev)
            {
                return true;
            }

            freq[word[i] - 'a']++;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::string word = "abcc";
        bool res = true;
        assert(sol.equalFrequency(word) == res);
    }
    {
        std::string word = "aazz";
        bool res = false;
        assert(sol.equalFrequency(word) == res);
    }
    return 0;
}