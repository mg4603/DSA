#include <iostream>
#include <assert.h>

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) 
    {
        int n = s.length();
        if(n < 10)
        {
            return {};
        }
        std::unordered_map<std::string, int> sequences;

        std::string seq = s.substr(0, 10);
        sequences[seq] = 1;

        std::vector<std::string> res;
        for(int i = 0; i < n - 10; i++)
        {
            seq = seq.substr(1);
            seq += s[i + 10];
            int temp = ++sequences[seq];
            
            if(temp == 2)
            {
                res.push_back(seq);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
        std::vector<std::string> res = {"AAAAACCCCC","CCCCCAAAAA"};
        assert(sol.findRepeatedDnaSequences(s) == res);
    }
    {
        std::string s = "AAAAAAAAAAAAA";
        std::vector<std::string> res = {"AAAAAAAAAA"};
        assert(sol.findRepeatedDnaSequences(s) == res);
    }
    return 0;
}