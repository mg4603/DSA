#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
using VI = std::vector<int>;

int solve(std::vector<int> v){  
    int cnt(0);
    std::sort(v.begin(), v.end());
    int l(0), r(v.size() - 1);
    while(l < r)
    {
        if(v[l] > 0 && v[r] > 0)
        {
            v[l]--;
            v[r]--;
            cnt++;
        }
        if(v[r] < v[r - 1])
        {
            std::sort(v.begin(), v.end());
        }
        if(v[l] == 0)
        {
            l++;
        }
        if(v[r] == 0)
        {
            r--;
        }
    }
    return cnt;
} 

int main()
{
    assert(solve(VI{1,1,1}) == 1);
    assert(solve(VI{1,2,1}) == 2);
    assert(solve(VI{4,1,1}) == 2);
    assert(solve(VI{8,2,8}) == 9);
    assert(solve(VI{8,1,4}) == 5);
    assert(solve(VI{7,4,10}) == 10);
    assert(solve(VI{12,12,12}) == 18);
    assert(solve(VI{1,23,2}) == 3);  
    return 0;
}