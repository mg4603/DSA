#include <iostream>
#include <assert.h>

#include <algorithm>
#include <vector>

std::vector<unsigned int> missNumsFinder(const std::vector<unsigned int>& arr) {
  unsigned int maxEle(*std::max_element(arr.begin(), arr.end()));
  std::vector<bool> temp(maxEle + 1, 0);
  for(const unsigned int num: arr)
  {
    temp[num] = 1;
  }
  std::vector<unsigned int> res;
  for(unsigned int i(1); i <= maxEle; i++)
  {
    if(temp[i] == 0)
    {
      res.push_back(i);
    }
  }
  return res;
}

int main()
{
    std::vector<unsigned int> arr = {2, 3, 1, 9, 4, 5, 6, 10, 7};
    std::vector<unsigned int> ans = {8};
    assert(missNumsFinder(arr) == ans);
    arr = {7, 6, 1, 4, 9, 2, 10, 3, 8};
    ans = {5};
    assert(missNumsFinder(arr) == ans);
    arr = {5, 4, 2, 9, 3, 8, 10, 6, 7};
    ans = {1};
    assert(missNumsFinder(arr) == ans);
    arr = {7, 1, 12, 9, 11, 14, 13, 6, 10, 5};
    ans = {2, 3, 4, 8};
    assert(missNumsFinder(arr) == ans);
    arr = {8, 10, 11, 7, 3, 15, 6, 1, 14, 5, 12};
    ans = {2, 4, 9, 13};
    assert(missNumsFinder(arr) == ans);
    arr = {9, 10, 7, 2, 11, 8, 1, 17, 6, 16, 18, 19, 15, 3, 13};
    ans = {4, 5, 12, 14};
    assert(missNumsFinder(arr) == ans);
}