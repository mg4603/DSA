#include <iostream>
#include <assert.h>

#include <vector>
#include <utility>
#include <map>

std::pair<int, std::vector<int>> findDupsMiss(const std::vector<int>& arr) {

    std::map<int, size_t> num_mp;
    for(int num: arr)
    {
        if(num_mp.count(num) == 0)
        {
            num_mp[num] = 0;
        }
        num_mp[num]++;
    }

    int curr(num_mp.begin()->first - 1);

    int missing;
    std::vector<int> dups;
    for(auto pair: num_mp)
    {
        curr++;
        if(pair.first != curr)
        {
            missing = curr;
            curr = pair.first;
        }
        if(pair.second > 1)
        {
            dups.push_back(pair.first);
        }

    }

    return std::make_pair(missing, dups);
}

int main()
{
    std::vector<int> sequence = {10,9,8,9,6,1,2,4,3,2,5,5,3};
    std::pair<int, std::vector<int>> ans;
    ans.first = 7, ans.second = {2,3,5,9};
    assert(findDupsMiss(sequence) == ans);
    sequence  = {20,19,6,9,7,17,16,17,12,5,6,8,9,10,14,13,11,14,15,19};
    ans.first = 18, ans.second = {6,9,14,17,19};
    assert(findDupsMiss(sequence) == ans);
    sequence  = {24,25,34,40,38,26,33,29,50,31,33,56,35,36,53,49,57,27,37,40,48,44,32,35,45,52,43,47,26,51,55,28,41,42,46,51,25,30,44,54};
    ans.first = 39, ans.second = {25,26,33,35,40,44,51};
    assert(findDupsMiss(sequence) == ans);
}