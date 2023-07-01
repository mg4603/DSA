#include <assert.h>
#include <iostream>

#include <vector>
#include <queue>

int addAll (const std::vector<int>& numbers) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> q(numbers.begin(), numbers.end());
  int res(0);
  while(q.size() > 1)
  {
    int first = q.top();
    q.pop();
    int second = q.top();
    q.pop();
    res += first + second;
    q.push(first + second);
  }
  return res;
}

int main()
{
    assert(addAll({1,2,3}) == 9);
    assert(addAll({1,2,3,4}) == 19);
    assert(addAll({1,2,3,4,5}) == 33);
}