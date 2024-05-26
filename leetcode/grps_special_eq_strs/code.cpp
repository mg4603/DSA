#include <iostream>
#include <assert.h>

#include <unordered_set>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numSpecialEquivGroups(std::vector<std::string>& words) {
        std::ios::sync_with_stdio(0);
        std::unordered_set<std::string> st;
        for(std::string &word: words) {
            std::string odd, even;
            for(int i = 0; i < word.length(); i++) {
                if(i % 2) {
                    odd += word[i];
                }else {
                    even += word[i];
                }
            }
            std::sort(odd.begin(), odd.end());
            std::sort(even.begin(), even.end());
            word = odd + even;
            st.insert(word);
        }
        return st.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"abcd","cdab","cbad",
                                          "xyzz","zzxy","zzyx"};
        int res = 3;
        assert(sol.numSpecialEquivGroups(words) == res);
    }
    return 0;
}