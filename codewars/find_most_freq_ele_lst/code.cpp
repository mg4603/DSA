#include <iostream>
#include <assert.h>

#include <vector>

#include <forward_list>
#include <utility>
#include <map>
#include <algorithm>

bool custom_order(std::pair<int, int> a, std::pair<int, int> b)
{
    return a.second > b.second;
}

std::pair<int,int> findMostFrequent(std::forward_list<int> l)
{
    std::map<int, int> freq_mp;
    for(int num: l)
    {
        if(freq_mp.count(num) == 0)
        {
            freq_mp[num] = 0;
        }
        freq_mp[num]++;
    }

    std::vector<std::pair<int, int>> temp(freq_mp.begin(), freq_mp.end());
    sort(temp.begin(), temp.end(), custom_order);
    
    std::map<int, int> temp1;
    for(auto ele: temp)
    {
        if(ele.second == temp[0].second)
        {
            temp1[ele.first] = ele.second;
        }
    }

    for(int n: l)
    {
        if(temp1.count(n) != 0){
            std::pair<int,int> output = std::make_pair(n, temp1[n]);
            return output;
        }
    }
    return {0, 0};
}


void example01()
{
    std::forward_list<int> l = {1,2,3,4,2,3,2};
    std::pair<int,int> expected = {2,3};
    std::pair<int,int> actual = findMostFrequent(l);
    assert(actual == expected);
}

void example02()
{
    std::forward_list<int> l = {4,3,5,3,4,5};
    std::pair<int,int> expected = {4,2};
    std::pair<int,int> actual = findMostFrequent(l);
    assert(actual == expected);
}

void example03()
{
    std::forward_list<int> l = {1,2,3,4,3,5,5,3};
    std::pair<int,int> expected = {3,3};
    std::pair<int,int> actual = findMostFrequent(l);
    assert(actual == expected);
}

int main()
{
    example01();
    example02();
    example03();
}
