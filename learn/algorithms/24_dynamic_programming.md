# Dynamic Programming

Find best solution from all possible solutions exhaustively. Greedy algorithms  
on the other hand pick the best possible outcome in each iteration.

## Principle of Optimality
If the optimal solution to a problem is know, you can use that solution to build 
optimal solutions for larger problems.

## Tabulation
* Systematically filling up a matrix in a bottom up approach. 
* It prevent's recomputation of overlapping sub-problems by starting with base  
cases and progressively building up to the solution of the original problem.
* Iterative in nature.

## Memoization
* Store the results of expensive function calls and look it up when the same  
input is encountered again.
* It is top down in nature

### Process
    1. when a function is called with certain inputs check if the results for  
        those inputs are already stored in the cache
    2. If the result is available, return the cached result without recomputing 
        the function
    3. If the results aren't available, compute the results using the function's 
        logic, and store the results in the cache.