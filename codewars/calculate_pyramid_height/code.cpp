#include <assert.h>
#include <iostream>

unsigned int pyramidHeight(unsigned int n) {
  unsigned int cnt(0);
  unsigned int sum(0);
  while(true)
  {
    sum += cnt * cnt;
    if( sum > n)
    {
      return cnt - 1;
    }
    else if( sum == n)
    {
      return cnt;
    }
    cnt++;
  }
  return 0;
}

int main()
{
    assert(pyramidHeight(1) == 1);
    assert(pyramidHeight(4) == 1);
    assert(pyramidHeight(5) == 2);
    assert(pyramidHeight(29) == 3);
    assert(pyramidHeight(30) == 4);
    assert(pyramidHeight(31) == 4);
    assert(pyramidHeight(1240) == 15);
    return 0;
}