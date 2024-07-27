#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> filterRestaurants(
                        std::vector<std::vector<int>>& restaurants, 
                        int veganFriendly, int maxPrice, 
                        int maxDistance) {
        std::ios::sync_with_stdio(0);
        std::vector<std::pair<int, int>> res_rate;

        for(int i = 0; i < restaurants.size(); i++) {
            if((restaurants[i][2] == veganFriendly || 
            !veganFriendly) &&
            restaurants[i][3] <= maxPrice &&
            restaurants[i][4] <= maxDistance) {
                res_rate.push_back({restaurants[i][1], restaurants[i][0]});
            }
        }

        std::sort(res_rate.begin(), res_rate.end());
        std::vector<int> res;
        for(int i = res_rate.size() - 1; i >= 0; i--) {
            res.push_back(res_rate[i].second);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> restaurants = 
                                    {{1,4,1,40,10},
                                     {2,8,0,50,5},
                                     {3,8,1,30,4},
                                     {4,10,0,10,3},
                                     {5,1,1,15,1}};
        int veganFriendly = 1, maxPrice = 50, maxDistance = 10;
        std::vector<int> res = {3, 1, 5};
        assert(
            sol.filterRestaurants(restaurants, veganFriendly, 
                                maxPrice, maxDistance) == res);
    }
    return 0;
}