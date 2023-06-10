#include <assert.h>
#include <iostream>

#include <cmath>

unsigned int howManyMeasurements(unsigned int n){
  return ceil(log(n) / log(3));
}

int main()
{
    assert(howManyMeasurements(1)== 0);
    assert(howManyMeasurements(2)== 1);
    assert(howManyMeasurements(3)== 1);
    assert(howManyMeasurements(8)== 2);
    assert(howManyMeasurements(100)== 5);
    return 0;
};