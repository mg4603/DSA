#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) 
    {
        int s1_len = s1.length();
        int s2_len = s2.length();

        if(s1_len > s2_len)
        {
            return false;
        }

        std::vector<int> freq1(26, 0);
        std::vector<int> freq2(26, 0);

        for(int i = 0; i < s1_len; i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if(freq1 == freq2)
        {
            return true;
        }

        for(int i = s1_len; i < s2_len; i++)
        {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - s1_len] - 'a']--;
            if(freq2 == freq1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    {
        std::string s1 = "ab";
        std::string s2 = "eidbaooo";
        bool res = true;
        assert(sol.checkInclusion(s1, s2) == res);
    }
    {
        std::string s1 = "ab";
        std::string s2 = "eidboaoo";
        bool res = false;
        assert(sol.checkInclusion(s1, s2) == res);
    }
    return 0;
}