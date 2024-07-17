#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
    int f(std::string &s) {
        int val = 26;
        std::vector<int> letterFreq(26, 0);
        for(char &ch: s) {
            ++letterFreq[ch - 'a'];
            val = std::min(val, ch - 'a');
        }
        return letterFreq[val];
    }
public:
    std::vector<int> numSmallerByFrequency(
                        std::vector<std::string>& queries, 
                        std::vector<std::string>& words) {
        std::ios::sync_with_stdio(0);
        std::vector<int> sCharFreq;
        for(std::string &word: words) {
            sCharFreq.push_back(f(word));
        }
        std::sort(sCharFreq.begin(), sCharFreq.end());

        std::vector<int> res;
        for(std::string query: queries) {
            int temp = std::upper_bound(sCharFreq.begin(), 
                                sCharFreq.end(), f(query)) - 
                                sCharFreq.begin();
            res.push_back(sCharFreq.size() - temp);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> queries = {"cbd"};
        std::vector<std::string> words = {"zaaaz"};
        std::vector<int> res = {1};
        assert(sol.numSmallerByFrequency(queries, words) == res);
    }
    return 0;
}