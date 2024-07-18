#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<bool> camelMatch(std::vector<std::string>& queries, 
                            std::string pattern) {
        std::ios::sync_with_stdio(0);
        std::vector<bool> res;
        for(std::string &query: queries) {
            int i = 0, j = 0;
            std::string temp;
            while(i < query.size() && j < pattern.size()) {
                if(query[i] == pattern[j]) {
                    temp += query[i];
                    j++;
                }else if(isupper(query[i])) temp += query[i];
                i++;
            }
            while(i < query.size()) {
                if(isupper(query[i]))temp += query[i];
                i++;
            }

            res.push_back(temp == pattern && j == pattern.size());
        }
        return res;        
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> queries = {"FooBar","FooBarTest",
                            "FootBall","FrameBuffer",
                            "ForceFeedBack"};

        std::string pattern = "FB";
        std::vector<bool> res = {true,false,true,true,false};
        assert(sol.camelMatch(queries, pattern) == res);
    }
    return 0;
}