#include <iostream>
#include <vector>
#include <assert.h>


/*
    Problem:
        find distinct ways to get to nth step if
        you can take 1...k steps at each step.

    Objective function:
        f(i) is the distinct number  of ways to get
        to ith step
    
    Base case:
        f(0) = 1
        f(1) = 1
    
    Recurrence relation:
        f(n) = f(n - 1) + ... + f(n - k)
    Order of operation:
        botton-up
    
    location of solution:
        nth element of 0 indexed cache
*/

int main() {
    return 0;
}