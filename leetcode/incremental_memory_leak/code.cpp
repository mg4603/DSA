#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> memLeak(int memory1, int memory2) {
        int crash = 0;
        int req = 1;
        while(req <= std::max(memory1, memory2)) {
            if(memory1 >= memory2) {
                memory1 -= req;
            }else {
                memory2 -= req;
            }
            req++;
            crash++;
        }
        return {crash + 1, memory1, memory2};
    }
};

int main()
{
    Solution sol;
    {
        int memory1 = 2;
        int memory2 = 2;
        std::vector<int> res = {3, 1, 0};
        assert(sol.memLeak(memory1, memory2) == res);
    }
    return 0;
}