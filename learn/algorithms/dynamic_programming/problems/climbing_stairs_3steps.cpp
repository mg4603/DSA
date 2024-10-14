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

int f(int n);

void test(std::string testCase, int n, int res) {
    std::cout << testCase << ": " << std::endl;;
    assert(f(n) == res /*Failed*/);
    std::cout << "Passed" << std::endl;;
}

int main() {
    test("Base case #1", 0, 1);
    test("Base case #2", 1, 1);
    test("Base case #3", 2, 2);

    test("Simple test case #1", 3, 4);
    return 0;
}