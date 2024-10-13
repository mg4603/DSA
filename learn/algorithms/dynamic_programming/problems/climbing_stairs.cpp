#include <iostream>
#include <vector>
#include <assert.h>

/*
    Problem:
    Find the distinct number of ways to reach a certain 
    stair, if on any stair, we can climb take either
    one or two steps.

    Objective fn:
    f(i) is the distinct number of ways to get to the ith stair

    Recurrence Relation:
    f(i) = f(i - 1) + f(i - 2)

    Base case:
        f(0) = 1 => do nothing
        f(1) = 1
*/

int f(int n );

void test(std::string testName, int n, int res) {
    std::cout << testName << ": ";
    assert(f(n) == res);
    std::cout << "Passed" << std::endl;;
}


int f(int n ) {
    if(n == 0 || n == 1)return 1;
    return f(n - 1) + f(n - 2);
}

int main() {
    test("Base case #1", 1, 1);
    test("Base case #2", 0, 1);

    test("Simple Test #1", 2, 2);
    
    return 0;
}