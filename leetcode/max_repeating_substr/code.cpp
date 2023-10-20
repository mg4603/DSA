#include <iostream>
#include <assert.h>

class Solution {
public:
    int maxRepeating(std::string sequence, std::string word) {
        std::string temp = word;
        int k = 0;
        while(sequence.find(temp) != std::string::npos)
        {
            temp += word;
            k++;
        }
        return k;
    }
};

int main()
{
    Solution sol;
    {
        std::string sequence = "ababc";
        std::string word = "ab";
        int res = 2;
        assert(sol.maxRepeating(sequence, word) == res);
    }
    {
        std::string sequence = "ababc";
        std::string word = "ba";
        int res = 1;
        assert(sol.maxRepeating(sequence, word) == res);
    }
    {
        std::string sequence = "ababc";
        std::string word = "ac";
        int res = 0;
        assert(sol.maxRepeating(sequence, word) == res);
    }
    return 0;
}