#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::string mostCommonWord(std::string paragraph, 
                            std::vector<std::string>& banned) 
    {
        std::unordered_map<std::string, int> word_freq;

        int i(0);
        std::string separators = ",.!?;' ";

        int max_cnt(0);
        std::string res;

        while(i != std::string::npos) 
        {
            int start = i;
            i = paragraph.find_first_of(separators, i);

            std::string temp = paragraph.substr(start, i - start);
            std::transform(temp.begin(), temp.end(), temp.begin(), 
                            [](char ch){return std::tolower(ch);});

            word_freq[temp]++;

            if(word_freq[temp] > max_cnt && 
                std::find(banned.begin(), banned.end(), temp) == banned.end())
            {
                max_cnt = word_freq[temp];
                res = temp;
            }

            i = paragraph.find_first_not_of(separators, i);
        }
        return res;
    }
};
int main()
{
    Solution sol;
    {
        std::string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
        std::vector<std::string> banned = {"hit"};
        std::string res = "ball";
        assert(sol.mostCommonWord(paragraph, banned) == res);
    }
    {
        std::string paragraph = "a.";
        std::vector<std::string> banned = {};
        std::string res = "a";
        assert(sol.mostCommonWord(paragraph, banned) == res);
    }
    return 0;
}