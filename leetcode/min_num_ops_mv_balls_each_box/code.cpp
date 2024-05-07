#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        std::ios::sync_with_stdio(0);
        int n = boxes.length();

        std::vector<int> res(n);

        int ops = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            res[i] += ops;
            cnt += (boxes[i] == '1' ? 1 : 0);
            ops += cnt;
        }
        
        ops = 0;
        cnt = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            res[i] += ops;
            cnt += (boxes[i] == '1' ? 1 : 0);
            ops += cnt;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::string boxes = "110";
        std::vector<int> res = {1,1,3};
        assert(sol.minOperations(boxes) == res);
    }
    return 0;
}