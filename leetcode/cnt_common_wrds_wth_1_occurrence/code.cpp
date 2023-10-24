#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    int countWords(std::vector<std::string>& words1, 
                    std::vector<std::string>& words2) 
    {
        std::unordered_map<std::string, int> w1_mp;
        std::unordered_map<std::string, int> w2_mp;
        for(int i = 0; i < words1.size(); i++)
        {
            w1_mp[words1[i]]++;
        }

        int res = 0;
        for(int i = 0; i < words2.size(); i++)
        {
            std::string word = words2[i];
            if(w1_mp.count(word) == 0 || w1_mp[word] > 1)continue;
            res++;
            int temp = ++w2_mp[word];
            if(temp == 2)
            {
                res -= 2;
            }
            else if(temp > 2)
            {
                res -= 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words1 = {"leetcode","is",
                                           "amazing","as","is"};
        std::vector<std::string> words2 = {"amazing","leetcode","is"};
        int res = 2;
        assert(sol.countWords(words1, words2) == res);
    }
    {
        std::vector<std::string> words1 = {"b","bb","bbb"};
        std::vector<std::string> words2 = {"a","aa","aaa"};
        int res = 0;
        assert(sol.countWords(words1, words2) == res);
    }
    {
        std::vector<std::string> words1 = {"a","ab"};
        std::vector<std::string> words2 = {"a","a","a","ab"};
        int res = 1;
        assert(sol.countWords(words1, words2) == res);
    }
    return 0;
}