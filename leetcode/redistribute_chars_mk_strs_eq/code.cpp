#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool makeEqual(std::vector<std::string>& words) {
        std::ios_base::sync_with_stdio(0);
        int n = words.size();
        std::vector<int> letters(26, 0);

        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                letters[words[i][j] - 'a']++;
            }
        }
        for(int i = 0; i < 26; i++)
        {
            if(letters[i] && letters[i] % n != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"abc","aabc","bc"};
        bool res = true;
        assert(sol.makeEqual(words) ==res );
    }
    {
        std::vector<std::string> words = {"ab","a"};
        bool res = false;
        assert(sol.makeEqual(words) == res);
    }
    return 0;
}