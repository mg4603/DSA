#include <iostream>
#include <assert.h>

#include <vector>
#include <sstream>

class Solution {
public:
    std::vector<std::string> splitWordsBySeparator(
                                std::vector<std::string>& words, 
                                char separator) 
    {
        std::vector<std::string> res;
        for(int i = 0; i < words.size(); i++)
        {
            std::stringstream ss(words[i]);
            std::string temp;
            while(getline(ss, temp, separator))
            {
                if(temp == "")continue;
                res.push_back(temp);
            }
        }    
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"one.two.three",
                                          "four.five","six"};
        char separator = '.';
        std::vector<std::string> res = {"one","two","three",
                                        "four","five","six"};
        assert(sol.splitWordsBySeparator(words, separator) == res);
    }
    {
        std::vector<std::string> words = {"$easy$","$problem$"};
        char separator = '$';
        std::vector<std::string> res = {"easy","problem"};
        assert(sol.splitWordsBySeparator(words, separator) == res);
    }
    {
        std::vector<std::string> words = {"|||"};
        char separator = '|';
        std::vector<std::string> res = {};
        assert(sol.splitWordsBySeparator(words, separator) == res);
    }
    return 0;
}