#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int maxProduct(std::vector<std::string>& words) 
    {
        int n = words.size();
        int res = 0;
        std::vector<int> mask(n, 0);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                mask[i] |= 1 << (words[i][j] - 'a');
            }

            for(int j = 0; j < i; j++)
            {
                if((mask[i] & mask[j]) == 0)
                {
                    int temp = words[i].size() * words[j].size();
                    if(temp > res)
                    {
                        res = temp;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"abcw","baz","foo",
                                          "bar","xtfn","abcdef"};
        int res = 16;
        assert(sol.maxProduct(words) == res);
    }
    {
        std::vector<std::string> words = {"a","ab","abc","d",
                                          "cd","bcd","abcd"};
        int res = 4;
        assert(sol.maxProduct(words) == res);
    }
    {
        std::vector<std::string> words = {"a","aa","aaa","aaaa"};
        int res = 0;
        assert(sol.maxProduct(words) == res);
    }
    return 0;
}