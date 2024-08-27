#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int res = 0;
        while(left <= right) {
            int sum = people[left] + people[right];
            if(sum <= limit) {
                res++;
                left++;
                right--;
            }else {
                res ++;
                right--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> people = {1, 2};
        int limit = 3, res = 1;
        assert(sol.numRescueBoats(people, limit) == res);
    }
    return 0;
}