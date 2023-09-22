#include <iostream>
#include <assert.h>

#include <vector>
#include <set>

class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        std::set<std::string> transformations;
        std::vector<std::string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(std::string word: words)
        {
            std::string transformation;
            for(char ch: word)
            {
                transformation += codes[ch - 'a'];
            }
            transformations.insert(transformation);

        }
        return transformations.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> words = {"gin","zen","gig","msg"};
        int output = 2;
        assert(sol.uniqueMorseRepresentations(words) == output);
    }
    {
        std::vector<std::string> words = {"a"};
        int output = 1;
        assert(sol.uniqueMorseRepresentations(words) == output);
    }
    return 0;
}