#include <assert.h>
#include <iostream>

#include <vector>
#include <numeric>
#include <cmath>

bool isPrime(int num)
{
    for(int i(2); i < sqrt(num); i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int minimumNumber (std::vector <int> numbers )
{
    int sum(std::accumulate(numbers.begin(), numbers.end(), 0, [](int a, int b){
        return a + b;
    }));
    int num(sum);
    while(true)
    {
        if(isPrime(num))
        {
            return num - sum;
        }
        num++;
    }
    return num;
}


int main()
{
    assert(minimumNumber({3,1,2}) == 1);
    assert(minimumNumber({5,2}) == 0);
    assert(minimumNumber({1,1,1}) == 0);
    assert(minimumNumber({2,12,8,4,6}) == 5);
    assert(minimumNumber({50,39,49,6,17,28}) == 2);
    return 0;
}