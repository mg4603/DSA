#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        int left = 0;
        std::vector<int> res;
        for(char &c: seq) {
            if(c == '(')left++;
            res.push_back(left % 2);
            if(c == ')')left--;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string seq = "(()())";
        std::vector<int> res = {1,0,0,0,0,1};
        assert(sol.maxDepthAfterSplit(seq) == res);
    }
    return 0;
}