#include <assert.h>
#include <iostream>

#include <vector>
#include <string>
#include <set>

int solve(const std::vector<std::vector<int>> &data)
{
    int cnt(1);
    for(auto v1: data)
    {
      cnt *= std::set(v1.begin(), v1.end()).size();
    }
    return cnt;
}

static void do_test(const std::vector<std::vector<int>> &data, int expected)
{
    int actual = solve(data);
    if ( actual != expected )
    {
        std::string str;
        for (auto set : data)
        {
            str += "[";
            for (auto x : set) str += std::to_string(x) + ", ";
            str.insert(str.size()-2, "]");
        }
        str.erase(str.size()-2);
        std::cout << "data = [" << str << "]" << '\n';
    }
    assert(actual == expected);
}

int main()
{
    do_test({{1,2},{4},{5,6}}, 4);
    do_test({{1,2},{4,4},{5,6,6}}, 4);
    do_test({{1,2},{3,4},{5,6}}, 8);
    do_test({{1,2,3},{3,4,6,6,7},{8,9,10,12,5,6}}, 72);
    return 0;
}