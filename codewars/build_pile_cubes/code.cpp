#include<assert.h>
#include<cmath>
#include<iostream>

class ASum
{
  public:
  static long long findNb(long long m);
};


void testequal(long long ans,  long long sol) {
    assert(ans == (sol));
}

int main()
{
    testequal(ASum::findNb(4183059834009), 2022);
    testequal(ASum::findNb(24723578342962), -1);
    testequal(ASum::findNb(135440716410000), 4824);
    testequal(ASum::findNb(40539911473216), 3568);
    testequal(ASum::findNb(26825883955641), 3218);
    testequal(ASum::findNb(1025292944081385002), -1);
    
}

long long ASum::findNb(long long m){
    // long double n((-1 + pow(1 + 8 * pow(m, 0.5), 0.5))/2);
    // if(n == floor(n)){
        // return n;
    // }
    // return -1;
    long long count(1);
    while(m > 0){
        m -= static_cast<long long>(pow(count, 3));
        count ++;
    }
    if(m == 0){
        return count-1;
    }
    return -1;
}