#include <iostream>
#include <assert.h>

#include <map>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string frequencySort(std::string s) 
    {
        std::map<char, int> mp;
        for(char ch: s)
        {
            mp[ch]++;
        }    

        std::vector<std::string> vec;
        for(auto it: mp)
        {
            vec.push_back(std::string(it.second, it.first));
        }
        
        std::sort(vec.begin(), vec.end(), [](auto a, auto b)
        {
            return a.length() > b.length();
        });
        
        std::string res;
        for(int i = 0; i < vec.size(); i++)
        {
            res += vec[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "tree";
        std::string res = "eert";
        assert(sol.frequencySort(s) == res);
    }
    {
        std::string s = "cccaaa";
        std::string res = "aaaccc";
        assert(sol.frequencySort(s) == res);
    }
    {
        std::string s = "Aabb";
        std::string res = "bbAa";
        assert(sol.frequencySort(s) == res);
    }
    return 0;
}