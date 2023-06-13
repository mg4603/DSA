#include <assert.h>
#include <iostream>

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> tourney(const std::vector<int>& input) {
  std::vector<std::vector<int>> res;
  res.push_back(input);
  while(res.back().size() > 1)
  {
    std::vector<int> temp;
    int diff(0);
    if(res.back().size() % 2 == 1)
    {
      temp.push_back(res.back().back());
      diff = 1;
    }
    
    for(int i(0); i < res.back().size() - diff; i+= 2)
    {
      temp.push_back(std::max(res.back()[i], res.back()[i+1]));
    }
    res.push_back(temp);
  }
  return res;
}

int main()
{
    assert(tourney(std::vector<int>{9, 5, 4, 7, 6, 3, 8, 2}) ==  
                 (std::vector<std::vector<int>>{
                   std::vector<int>{9, 5, 4, 7, 6, 3, 8, 2},
                   std::vector<int>{9, 7, 6, 8},
                   std::vector<int>{9, 8},
                   std::vector<int>{9}
                 }));
    assert(tourney(std::vector<int>{9, 5, 4, 7, 6, 3, 8}) ==  
                 (std::vector<std::vector<int>>{
                   std::vector<int>{9, 5, 4, 7, 6, 3, 8},
                   std::vector<int>{8, 9, 7, 6},
                   std::vector<int>{9, 7},
                   std::vector<int>{9}
                 }));
    return 0;
};