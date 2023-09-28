#include <iostream>
#include <assert.h>

#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
        std::stringstream ss(s1);

        std::map<std::string, int> word_freq;

        std::string temp;
        while(ss >> temp)
        {
            word_freq[temp]++;
        }

        ss.clear();
        ss.str(s2);
        while(ss >> temp)
        {
            word_freq[temp]++;
        }

        std::vector<std::string> res;

        for(auto pair: word_freq)
        {
            if(pair.second == 1)
            {
                res.push_back(pair.first);
            }
        }
        return res;
    }
};

void assert_equal(std::vector<std::string> v1, std::vector<std::string> v2)
{
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    assert(v1 == v2);
}
int main()
{
    Solution sol;
    {
        std::string s1 = "this apple is sweet";
        std::string s2 = "this apple is sour";
        std::vector<std::string> res = {"sweet", "sour"};
        assert_equal(sol.uncommonFromSentences(s1, s2), res);
    }
    {
        std::string s1 = "apple apple";
        std::string s2 = "banana";
        std::vector<std::string> res = {"banana"};
        assert_equal(sol.uncommonFromSentences(s1, s2), res);
    }
    return 0;
}