#include <assert.h>
#include <iostream>

#include <algorithm>
#include <vector>

void getCombinations(
                std::vector<int> &vec, int n, std::vector<std::vector<int>> &res, 
                std::vector<int> &r, int i)
{
    if(n == 0 && r.size() <= vec.size())
    {
        res.push_back(r);
        return;
    }
    while(i < static_cast<int>(vec.size()) && n - vec[i] >= 0)
    {
        r.push_back(vec[i]);
        getCombinations(vec, n - vec[i], res, r, i);
        i++;
        if(r.size() > 0)
        {
            r.pop_back();
        }
    }
}

int find(std::vector<int> vec, int n)
{
    std::sort(vec.begin(), vec.end());

    std::vector<int> r;
    std::vector<std::vector<int>> res;

    getCombinations(vec, n, res, r, 0);
    return res.size();
}

int main()
{
    assert(find({1,2,3}, 1) == 1);
    assert(find({1,2,3}, 10) == 0);
    assert(find({1,2,3}, 7) == 2);
    assert(find({1,2,3}, 5) == 3);
    assert(find({1,1,1}, 1) == 3);
    assert(find({1,1,1}, 2) == 6);
    assert(find({1,1,1}, 3) == 10);
    assert(find({1,1,1}, 4) == 0);
    assert(find({3,6,9,12}, 12) == 5);
    assert(find({1,4,5,8}, 8) == 3);
    assert(find({3,6,9,12}, 15) == 5);
    assert(find({3,6,9,12,14,18}, 30) == 21);
}