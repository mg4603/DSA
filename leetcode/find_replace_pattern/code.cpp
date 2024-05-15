#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
    std::string normalize(std::string word) {
        std::unordered_map<char, int> mp;
        for(char &c: word) {
            if(!mp.count(c)) {
                mp[c] = mp.size();
            }
        }
        for(char &c: word) {
            c = 'a' + mp[c];
        }
        return word;
    }
public:
    std::vector<std::string> findAndReplacePattern(
                        std::vector<std::string>& words, 
                        std::string pattern) {
        std::ios::sync_with_stdio(0);
        std::vector<std::string> res;
        pattern = normalize(pattern);

        for(int i = 0; i < words.size(); i++) {
            if(pattern == normalize(words[i])) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"abc","deq","mee",
                                          "aqq","dkd","ccc"};
        std::string pattern = "abb";
        std::vector<std::string> res{"mee","aqq"};
        assert(sol.findAndReplacePattern(words, pattern) == res);
    }
    return 0;
}