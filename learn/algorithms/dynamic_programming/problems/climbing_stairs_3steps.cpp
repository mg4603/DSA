#include <iostream>
#include <vector>
#include <assert.h>

/*
    Problem:
        Find the distinct number of ways to get to a step n,
        if on each step you can climb 1, 2 or 3 steps.
    
    Objective function:
        f(i) gives the number of distinct ways to get to
        the ith step

    Base cases:
        f(0) = 0;
        f(1) = 1;
        f(2) = 2;
          
    Recurrence Relation:
        f(n) = f(n - 1) + f(n - 2) + f(n - 3)
    
    Order of computation:
        bottom-up
    
    Location of answer:
        nth element of 0-indexed cache
*/

int main() {
    return 0;
}