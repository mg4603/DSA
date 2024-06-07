#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        std::vector<int> s = {a, b, c};
        std::sort(s.begin(), s.end());
        if(s[0] + s[1] <= s[2]){
            return s[0] + s[1];
        }
        return s[2] + (s[0] + s[1] - s[2]) / 2;
    }
};

int main()
{
    Solution sol;
    {
        int a = 2, b = 4, c = 6;
        int res = 6;
        assert(sol.maximumScore(a, b, c) == res);
    }
    return 0;
}