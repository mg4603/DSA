#include <assert.h>
#include <iostream>

int solve(long n){
  if(!n)return 0;
  int d1(n > 9? 9: n);
  int d2((n - d1) % 10);
  return d1 + d2 + solve((n - d1 - d2) / 10);
}

int main()
{
    assert(solve(0) == 0);
    assert(solve(1) == 1);
    assert(solve(18) == 18);
    assert(solve(29) == 11);
    assert(solve(45) == 18);
    assert(solve(1140) == 33);  
    assert(solve(7019) == 35);
    assert(solve(50000000) == 68); 
    return 0;
}
