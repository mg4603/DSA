#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    std::string oddString(std::vector<std::string>& words) 
    {
        std::map<std::vector<int>, std::pair<int, int>> mp;
        for(int i = 0; i < words.size(); i++)
        {
            int n = words[i].size();
            std::vector<int> temp(n - 1, 0);
            for(int j = 1; j < n; j++)
            {
                temp[j - 1] = words[i][j] - words[i][j - 1];
            }
            mp[temp].first = i;
            mp[temp].second++;
        }

        for(auto it: mp)
        {
            if(it.second.second == 1)
            {
                return words[it.second.first];
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"adc","wzy","abc"};
        std::string res = "abc";
        assert(sol.oddString(words) == res);
    }
    {
        std::vector<std::string> words = {"aaa","bob","ccc","ddd"};
        std::string res = "bob";
        assert(sol.oddString(words) == res);
    }
    return 0;
}