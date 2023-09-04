#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::string>& words) {
        std::vector<std::string> res;
        std::map<int, std::string> rows = 
        {
            {1, "qwertyuiop"},
            {2, "asdfghjkl"},
            {3, "zxcvbnm"}
        };

        int key_row(-1);
        for(std::string word: words)
        {
            for(auto row: rows)
            {
                if(row.second.find(tolower(word[0])) != std::string::npos)
                {
                    key_row = row.first;
                }
            }
            int in_row(1);
            for(char ch: word)
            {
                if(rows[key_row].find(tolower(ch)) == std::string::npos)
                {
                    in_row = 0;
                    break;
                }
            }
            if(in_row)
            {
                res.push_back(word);
            }
            
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"Hello","Alaska","Dad","Peace"};
        std::vector<std::string> res = {"Alaska","Dad"};
        assert(sol.findWords(words) == res);
    }
    {
        std::vector<std::string> words = {"omk"};
        std::vector<std::string> res = {};
        assert(sol.findWords(words) == res);
    }
    {
        std::vector<std::string> words = {"adsdf","sfd"};
        std::vector<std::string> res = {"adsdf","sfd"};
        assert(sol.findWords(words) == res);
    }
    return 0;
}