#include <assert.h>
#include <iostream>

int sequence(int n)
{
  int first(0);
  if(n == 1)
    return first;
  
  int second(1);
  for(int i(2); i < n; i++)
  {
    int temp(first + second);
    temp %= 3;
    first = second;
    second = temp;
  }
  return second;
}

int main()
{
    assert( sequence(1) == 0);
    assert( sequence(2) == 1);
    assert( sequence(3) == 1);
    assert( sequence(4) == 2);
    assert( sequence(5) == 0);
    return 0;
}