#include <iostream>
#include <assert.h>

#include <vector>
#include <queue>
#include <map>

class Solution {
    struct compare
    {
        bool operator()(const std::pair<int, std::string> &a, 
                        const std::pair<int, std::string> & b){
            if(a.first == b.first)
            {
                return a.second > b.second;
            }
            return (a.first < b.first);
        }
    };

public:
    std::vector<std::string> topKFrequent(
                    std::vector<std::string>& words, int k) {
        std::ios::sync_with_stdio(0);
        std::map<std::string, int> mp;
        for(std::string &word: words)
        {
            mp[word]++;
        }

        std::priority_queue<std::pair<int, std::string>, 
                std::vector<std::pair<int, std::string>>, compare> pq;
        for(auto &[word, freq] : mp)
        {
            pq.push({freq, word});
        }

        std::vector<std::string> res(k);
        for(int i = 0; i < k; i++)
        {
            auto &[_, word] = pq.top();
            res[i] = word;
            pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"i","love","leetcode","i",
                                            "love","coding"};
        int k = 2;
        std::vector<std::string> res = {"i","love"};
        assert(sol.topKFrequent(words, k) == res);
    }
    return 0;
}