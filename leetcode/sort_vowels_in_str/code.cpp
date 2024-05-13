#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string sortVowels(std::string s) {
        std::ios::sync_with_stdio(0);
        std::unordered_map<char, int> mp = {{'A', 0}, {'E', 1}, 
                                    {'I', 2}, {'O', 3}, {'U', 4}, 
                                    {'a', 5}, {'e', 6}, {'i', 7}, 
                                    {'o', 8}, {'u', 9}};
        std::vector<int> freq(10, 0);

        for(char &c: s) {
            if(!mp.count(c))continue;
            freq[mp[c]]++;
            c = '-';
        }

        int idx = 0;
        for(char &c: s) {
            if(c != '-')continue;
            while(freq[idx] == 0)idx++;
            freq[idx]--;
            c = "AEIOUaeiou"[idx];
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "lEetcOde";
        std::string res = "lEOtcede";
        assert(sol.sortVowels(s) == res);
    }
    return 0;
}