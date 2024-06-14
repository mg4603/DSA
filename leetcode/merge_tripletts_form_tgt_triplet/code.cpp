#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets,  
                    std::vector<int>& target) {
        std::ios::sync_with_stdio(0);
        std::vector<int> res{0, 0, 0};
        for(int i = 0; i < triplets.size(); i++) {
            if(triplets[i][0] <= target[0] &&  
               triplets[i][1] <= target[1] &&  
               triplets[i][2] <= target[2]) {

                res[0] = std::max(triplets[i][0], res[0]);
                res[1] = std::max(triplets[i][1], res[1]);
                res[2] = std::max(triplets[i][2], res[2]);
            }
        }
        return res == target;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> triplets = {{2,5,3},{1,8,4},
                                                    {1,7,5}};
        std::vector<int> target = {2,7,5};
        bool res = true;
        assert(sol.mergeTriplets(triplets, target) == res);
    }
    return 0;
}