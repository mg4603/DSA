#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || 
            ch == 'i' || ch == 'o' || 
            ch == 'u';
    }
public:
    std::vector<int> vowelStrings(std::vector<std::string>& words, 
                            std::vector<std::vector<int>>& queries) {
        int n = words.size();
        std::vector<int> cumulative_vow(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            if(isVowel(words[i].front()) && isVowel(words[i].back()))
            {
                cumulative_vow[i + 1]++;
            }
            cumulative_vow[i + 1] += cumulative_vow[i];
        }

        int m = queries.size();
        std::vector<int> res(m);
        for(int i = 0; i < m; i++)
        {
            res[i] = cumulative_vow[queries[i][1] + 1] - 
                        cumulative_vow[queries[i][0]];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"aba","bcb","ece","aa","e"};
        std::vector<std::vector<int>> queries = {{0,2},{1,4},{1,1}};
        std::vector<int> res = {2,3,0};
        assert(sol.vowelStrings(words, queries) == res);
    }
    return 0;
}