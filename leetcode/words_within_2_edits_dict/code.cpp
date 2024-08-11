#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<std::string> twoEditWords(
                        std::vector<std::string>& queries, 
                        std::vector<std::string>& dictionary) {
        std::ios::sync_with_stdio(0);
        std::vector<std::string> res;
        for(std::string &query: queries) {
            for(int i = 0; i < dictionary.size(); i++) {
                int temp = 0;
                for(int j = 0; j < query.size(); j++) {
                    if(query[j] != dictionary[i][j])temp++;
                }
                if(temp <= 2){
                    res.push_back(query);
                    break;
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
        std::vector<std::string> queries = {"word","note","ants","wood"};
        std::vector<std::string> dictionary = {"wood","joke","moat"};
        std::vector<std::string> res = {"word", "note", "wood"};
        assert(sol.twoEditWords(queries, dictionary) == res);
    }
    return 0;
}