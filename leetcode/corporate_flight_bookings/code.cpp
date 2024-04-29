#include <iostream>
#include <assert.h>

#include <vector>

class Solution {
public:
    std::vector<int> corpFlightBookings(
            std::vector<std::vector<int>>& bookings, int n) {
        std::ios::sync_with_stdio(0);
        std::vector<int> res(n);
        for(int i = 0; i < bookings.size(); i++)
        {
            int l = bookings[i][0] - 1;
            int seats = bookings[i][2];
            int r = bookings[i][1];
            res[l] += seats;
            if(r < n)
                res[r] -= seats;;
        }

        for(int i = 1; i < n; i++)
        {
            res[i] += res[i - 1];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::vector<int>> bookings = {{1,2,10},
                                                  {2,3,20},
                                                  {2,5,25}};
        int n = 5;
        std::vector<int> res = {10,55,45,25,25};
        assert(sol.corpFlightBookings(bookings, n) == res);
    }
    return 0;
}