#include <assert.h>
#include <iostream>

#include <vector>
#include <set>

bool contains_all(const std::vector<int>& arr, const std::vector<int>& target) {
  std::set<int> st(arr.begin(), arr.end());
  for(auto num: target)
  {
    if(st.find(num) == st.end())
    {
      return false;
    }
  }
  return true;
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(contains_all(nums, std::vector<int>{1, 2, 6}) == true);
    assert(contains_all(nums, std::vector<int>{1}) == true);
    assert(contains_all(nums, std::vector<int>{9}) == true);
    assert(contains_all(nums, std::vector<int>{2, 4, 6, 8}) == true);
    assert(contains_all(nums, std::vector<int>{1, 15, 6}) == false);
    assert(contains_all(nums, std::vector<int>{0}) == false);
    assert(contains_all(nums, std::vector<int>{10}) == false);
    return 0;
}