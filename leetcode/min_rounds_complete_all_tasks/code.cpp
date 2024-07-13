#include <iostream>
#include <assert.h>

#include <unordered_map>
#include <vector>

class Solution {
public:
    int minimumRounds(std::vector<int>& tasks) {
        std::ios::sync_with_stdio(0);

        std::unordered_map<int, int> freq;
        for(int &task: tasks) {
            freq[task]++;
        }
        int res = 0;
        for(auto &[_, count] : freq) {
            if(count < 2)return -1;
            else if(count % 3 == 0) {
                res += (count / 3);
            }
            else if((count - 2) % 3 == 0) {
                res += (1 + (count - 2)/ 3);
            }else if((count - 4) % 3 == 0) {
                res += (2 + (count - 4) / 3);
            }else {
                return -1;
            }
        }
        return res;

    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
        int res = 4;
        assert(sol.minimumRounds(tasks) == res);
    }
    return 0;
}