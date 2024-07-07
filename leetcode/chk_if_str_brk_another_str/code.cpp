#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool checkIfCanBreak(std::string s1, std::string s2) {
        std::ios::sync_with_stdio(0);
        
        int n = s1.length();
        std::vector<int> freq1(26, 0);
        std::vector<int> freq2(26, 0);
        for(int i = 0; i < n; i++)freq1[s1[i] - 'a']++;
        for(int i = 0; i < n; i++)freq2[s2[i] - 'a']++;
        s1 = "";
        s2 = "";
        for(int i = 0; i < 26; i++) {
            s1 += std::string(freq1[i], 'a' + i);
            s2 += std::string(freq2[i], 'a' + i);
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < n; i++) {
            cnt1 += (s1[i] >= s2[i]);
            cnt2 += (s2[i] >= s1[i]);
        }
        return cnt1 == n || cnt2 == n;
    }
};

int main()
{
    Solution sol;
    {
        std::string s1 = "abc";
        std::string s2 = "xya";
        bool res = true;
        assert(sol.checkIfCanBreak(s1, s2) == res);
    }
    return 0;
}