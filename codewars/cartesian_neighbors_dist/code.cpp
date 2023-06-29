#include <iostream>
#include <assert.h>
#include <iomanip>

#include <cmath>
#include <vector>
#include <algorithm>
#define tenPow11 10000000000.0

std::vector<double> cartesianNeighborsDistance(int x, int y, int range){
    std::vector<double> res;
    for(int i(1); i <= range; i++)
    {
        res.push_back(i);
        for(int j(i); j <= range; j++)
        {
            res.push_back(round(tenPow11 *sqrt(i*i + j * j))/ tenPow11);
        }
    }
    std::sort(res.begin(), res.end());
    res.erase(std::unique(res.begin(), res.end()), res.end());
    return res;
}


template <typename T>
std::vector<T> sortedList(std::vector<T> list)
{
    std::sort(list.begin(), list.end());
    return list;
}

template <typename T>
bool almostEquals(std::vector<T> list1, std::vector<T> list2)
{
    if(list1.size() != list2.size())
        return false;
    
    for(int i(0); i < static_cast<int>(list1.size()); i++)
    {
        if(round(tenPow11 * list1[i]) / tenPow11 != round(list2[i] * tenPow11) / tenPow11)
        {
            return false;
        }
    }
    return true;
}

void dotest(int x, int y, int range, std::vector<double> expr) {
    std::vector<double> distances = sortedList<double>(cartesianNeighborsDistance(x, y, range));       
    assert(almostEquals<double>(distances, expr) == true);
}

int main()
{
    dotest(3, 2, 1, {1.0, 1.4142135624});
    return 0;
}