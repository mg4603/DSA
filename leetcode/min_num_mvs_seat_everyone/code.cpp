#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>


class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) 
    {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        int res = 0;
        for(int i = 0; i < seats.size(); i++)
        {
            res += std::abs(seats[i] - students[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> seats = {3,1,5};
        std::vector<int> students = {2,7,4};
        int res = 4;
        assert(sol.minMovesToSeat(seats, students) == res);
    }
    {
        std::vector<int> seats = {4,1,5,9};
        std::vector<int> students = {1,3,2,6};
        int res = 7;
        assert(sol.minMovesToSeat(seats, students) == res);
    }
    {
        std::vector<int> seats = {2,2,6,6};
        std::vector<int> students = {1,3,2,6};
        int res = 4;
        assert(sol.minMovesToSeat(seats, students) == res);
    }
    return 0;
}