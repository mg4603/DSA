#include <iostream>
#include <assert.h>

#include <unordered_set>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> stringMatching(std::vector<std::string>& words) {
        std::ios_base::sync_with_stdio(0);
        std::unordered_set<std::string> res;

        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words.size(); j++)
            {
                if(i != j && words[j].find(words[i]) != std::string::npos)
                {
                    res.insert(words[i]);
                    break;
                }
            }
        }
        return std::vector<std::string>(res.begin(), res.end());
    }
};

void assert_equal(std::vector<std::string> arr1, std::vector<std::string> arr2)
{
    assert(arr1.size() == arr2.size());
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());
    for(int i = 0; i < arr1.size(); i++)
    {
        assert(arr1[i] == arr2[i]);
    }
}

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"mass","as","hero","superhero"};
        std::vector<std::string> res = {"as","hero"};
        assert_equal(sol.stringMatching(words), res);
    }
    {
        std::vector<std::string> words = {"leetcode","et","code"};
        std::vector<std::string> res = {"et","code"};
        assert_equal(sol.stringMatching(words), res);
    }
    {
        std::vector<std::string> words = {"blue","green","bu"};
        std::vector<std::string> res = {};
        assert_equal(sol.stringMatching(words), res);
    }
    return 0;
}