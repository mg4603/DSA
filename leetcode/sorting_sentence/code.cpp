#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <sstream>

class Solution {
public:
    std::string sortSentence(std::string s) {
        std::ios_base::sync_with_stdio(0);
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string temp;
        while(ss >> temp)
        {
            words.push_back(temp);
        }
        std::sort(words.begin(), words.end(), 
                        [](std::string a, std::string b){
                                return a.back() < b.back();
                        });

        std::string res;
        for(int i = 0; i < words.size(); i++)
        {
            res += words[i];
            res.pop_back();
            if(i != words.size() - 1)
            {
                res += ' ';
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "is2 sentence4 This1 a3";
        std::string res = "This is a sentence";
        assert(sol.sortSentence(s) == res);
    }
    {
        std::string s = "Myself2 Me1 I4 and3";
        std::string res = "Me Myself and I";
        assert(sol.sortSentence(s) == res);
    }
    return 0;
}