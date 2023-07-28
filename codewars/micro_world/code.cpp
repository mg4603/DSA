#include <iostream>
#include <assert.h>

#include <vector>
#include <map>
#include <algorithm>

int microWorld(std::vector<int> bacteria , int k){
    std::sort(bacteria.begin(), bacteria.end());    

    int swallowed_cnt(0);

    std::map<int, int> bacteria_sz_mp;
    
    for(int size: bacteria)
    {
        if(bacteria_sz_mp.count(size) == 0)
        {
            bacteria_sz_mp[size]  = 0;
        }
        bacteria_sz_mp[size]++;
    }

    for(int i(0); i < static_cast<int>(bacteria.size()) - 1; i++)
    {
        if(bacteria[i] < bacteria[i + 1] && bacteria[i] + k >= bacteria[i + 1])
        {
            swallowed_cnt += bacteria_sz_mp[bacteria[i]];
        }
    }
    return bacteria.size() - swallowed_cnt;
}

int main()
{
    assert(microWorld({101, 53, 42, 102, 101, 55, 54} , 1) == 3);
    assert(microWorld({20, 15, 10, 15, 20, 25} , 5) == 1);
    return 0;
}