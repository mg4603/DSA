#include <iostream>
#include <assert.h>

#include <vector>
#include <map>

class Solution {
public:
    std::string arrangeWords(std::string text) {
        std::ios::sync_with_stdio(0);
        std::map<int, std::vector<std::string>> words;
        std::string temp = "";

        for(int i = 0; i < text.size(); i++) {
            if(text[i] == ' ') {
                words[temp.size()].push_back(temp);
                temp = "";
                continue;
            }
            temp += tolower(text[i]);
        }
        words[temp.size()].push_back(temp);
        text = "";

        for(auto &it: words) {
            for(int i = 0; i < it.second.size(); i++) { 
                text += it.second[i] + ' ';
            }
        }

        text.pop_back();
        text[0] = toupper(text[0]);
        return text;
    }
};

int main()
{
    Solution sol;
    {
        std::string text = "Leetcode is cool";
        std::string res = "Is cool leetcode";
        assert(sol.arrangeWords(text) == res);
    }
    return 0;
}