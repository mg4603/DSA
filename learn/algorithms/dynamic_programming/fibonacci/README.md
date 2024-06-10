# Fibonacci

## Recursive
```
    fib(n): int
        if n <= 2:return 1
        return fib(n - 1) + fib(n - 2)
```
- Time Complexity  
    $O(2^{n+1} - 1) = 2^n$
- Space Complexity  
    $O(n)$

## Memoization
Store the results of computed sub-problems

```
    fib(n, memo): int
        if n im memo: return memo[n]
        if n <= 2: return 1

        memo[n] = fib(n - 1) + fib(n - 2)
        return memo[n]
```
- Time Complexity:  
    $O(2n - 3) = O(n)$

- Space Complexity:  
    $O(n) = O(n)$