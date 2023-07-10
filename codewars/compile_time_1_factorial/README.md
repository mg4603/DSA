## Compile time #1 Factorial

Write a class template that, when instantiated with parameter x, will contain  
the static value equals to factorial of x. All calculation should be finished  
at compile time.

### Sample test cases:
    static_assert(factorial<3>::value ==  6, "");
    static_assert(factorial<4>::value == 24, "");
    // and
    Assert::That(factorial<3>::value, Equals( 6));
    Assert::That(factorial<4>::value, Equals(24));

### Recursive definition of factorial

0! = 1
n! = n * (n - 1)