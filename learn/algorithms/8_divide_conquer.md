# Divide and Conquer

* Dividing a large problem into smaller sub-problems of the same kind, that are  
    easily solvable, before combining the solutions of the sub-problems to find  
    the solution to the large problem.
* Recursive in nature.
* The solutions of the sub-problems must be combinable to reach the solution to  
    the large problem.
* Can only be applied to problems:
    * that remain the same when divided into smaller sub-problems.
    * where there is a way to combine the solutions to the sub-problems to get  
        the solution to the main problem.


## General form:

    DAC(P)
    {
        if(small(P))
        {
            solve(P);
        }
        else
        {
            divide P into p1, p2, ... pk
            Apply DAC(p1), DAC(p2)...DAC(pk)
            Combine solutions to DAC(p1), DAC(p2)..DAC(pk)
        }
    }

## Examples
1. Binary SEarch
2. Finding Maximum and Minimum
3. Merge sort
4. Quick sort
5. Strassen's Matrix Multiplication