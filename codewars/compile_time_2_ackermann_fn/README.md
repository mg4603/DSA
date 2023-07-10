## Compile time #2 Ackermann function  

Write a class template that when instantiated with parameters m and n, will  
contain the static value equals to Ackermann function value A(m, n). All  
calculations should be finished at compile time.  

### Sample Test Cases:

    static_assert(ackermann<2, 2>::value == 7, "");
    // and
    Assert::That(ackermann<2, 2>::value, Equals(7));

Ackermann function is defined recursively for non-negative integers m and n as:
    
    A(0, n) = n + 1         if m == 0
    A(m, 0) = A(m - 1, 1)   if m > 0 and n == 0
    A(m, n) = A(m - 1, A(m, n - 1)) if m > 0 and n > 0
    A(0, 0) = 1             if m == 0 and n == 0