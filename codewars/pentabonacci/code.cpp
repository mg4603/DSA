#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <numeric>

long countOddPentaFib(long n){
  if(n <= 5)
  {
    return 1;
  }
  std::vector<bool> seq{0, 1, 1, 0, 0};
  int cnt(1);
  for(int i(0); i < n - 4; i++)
  {
    int odds(std::accumulate(seq.begin(), seq.end(), 0, [](int a, bool b){ return a + (b?1:0);}));
    std::rotate(seq.begin(), seq.begin() + 1, seq.end());
    if(odds % 2 != 0)
    {
        seq[4] = 1;
        cnt++;
    }
    else 
    {
        seq[4] = 0;
    }
  }
  
  return cnt;
}

int main()
{
    std::cout<< "Fixed Tests: CountOddPentaFib, low values"<< std::endl;
    long lstI[] = {45, 68, 76, 100, 121};
    long resultsI[] = {15, 23, 25, 33, 40};
    for (int i = 0; i <= 4; i++) {
    assert(countOddPentaFib(lstI[i]) == resultsI[i]);
    }
    return 0;
}