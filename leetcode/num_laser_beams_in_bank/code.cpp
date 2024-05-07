#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numberOfBeams(std::vector<std::string>& bank) {
        std::ios::sync_with_stdio(0);
        int prev = 0;
        int curr = 0;
        int res = 0;
        int n = bank.size();
        for(int i = 0; i < n; i++)
        {
            curr = 0;
            for(char c: bank[i])
            {
                curr += c - '0';
            }
            if(curr != 0)
            {
                res += curr * prev;
                prev = curr;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> bank = {"011001","000000",
                                         "010100","001000"};
        int res = 8;
        assert(sol.numberOfBeams(bank) == res);
    }
    return 0;
}