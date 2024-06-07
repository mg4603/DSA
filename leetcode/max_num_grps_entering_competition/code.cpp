#include <iostream>
#include <assert.h>

#include <vector>
#include <cmath>

class Solution {
    // if sorted, since grades[i + 1] > grades[i]
    // each successives group will definitely be larger

    // so we need to find number of groups 
    // such that the total sum of number of elements
    // is smaller than or equal to n, where n is 
    // the number of students
    
    // The following relationship describes number
    // of groups:
    //      Let k be the number of groups
    //      k(k + 1)/2 <= n
public:
    int maximumGroups(std::vector<int>& grades) {
        std::ios::sync_with_stdio(0);
        int n = grades.size();
        int k = (-1 + sqrt(1 + 8 * n))/2;
        return k;
    }
};

int main()
{
    Solution sol;
    {
        std::vector<int> grades = {10,6,12,7,3,5};
        int res = 3;
        assert(sol.maximumGroups(grades) == res);
    }
    return 0;
}