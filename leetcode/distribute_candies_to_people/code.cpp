#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> distributeCandies(int candies, int num_people) 
    {
        std::vector<int> res(num_people, 0);
        int i = 0;
        int next = 1;
        while(candies > 0)
        {
            res[i] += std::min(next, candies);
            i++;
            candies -= next;
            next++;

            if(i == num_people)
            {
               i = 0; 
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int candies = 7;
        int num_people = 4;
        std::vector<int> res = {1,2,3,1};   
        assert(sol.distributeCandies(candies, num_people) == res);
    }
    {
        int candies = 10;
        int num_people = 3;
        std::vector<int> res = {5,2,3};   
        assert(sol.distributeCandies(candies, num_people) == res);
    }
    return 0;
}