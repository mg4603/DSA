#include <iostream>
#include <assert.h>

#include <vector>
#include <set>

class Solution {
public:
    int distributeCandies(std::vector<int>& candies) {
        std::set<int> candy_types;
        for(int candy_type: candies)
        {
            candy_types.insert(candy_type);
        }
        if(candy_types.size() > candies.size() / 2)
        {
            return candies.size() / 2;
        }
        return candy_types.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> candies = {1,1,2,2,3,3};
        assert(sol.distributeCandies(candies) == 3);
    }
    {
        std::vector<int> candies = {1,1,2,3};
        assert(sol.distributeCandies(candies) == 2);
    }
    {
        std::vector<int> candies = {6,6,6,6};
        assert(sol.distributeCandies(candies) == 1);
    }
    return 0;
}