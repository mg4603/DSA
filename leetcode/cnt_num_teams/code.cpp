#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    int numTeams(std::vector<int>& r) {
        int res = 0;
        int n = r.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if((r[i] < r[j] && r[j] < r[k]) || 
                     (r[i] > r[j] && r[j] > r[k])) res++;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> rating = {2,5,3,4,1};
        int res = 3;
        assert(sol.numTeams(rating) == res);
    }
    return 0;
}