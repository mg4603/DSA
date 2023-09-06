# Range Addition II

You are given an $m x n$ matrix M initialized with all 0's and an array of  
operations ops, where $ops[i] = [a_i, b_i]$ means $M[x][y]$ should be  
incremented by one for all $0 \le x < a_i$ and $0 \le y < b_i$.

Count and return the number of maximum integers in the matrix after performing  
all the operations.

 

## Example 1:

    Input: m = 3, n = 3, ops = [[2,2],[3,3]]
    Output: 4
    Explanation: 
        The maximum integer in M is 2, and there are four of it in M. So 
            return 4.

## Example 2:

    Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],
                                [3,3],[2,2],[3,3],[3,3],[3,3]]
    Output: 4
    
## Example 3:

    Input: m = 3, n = 3, ops = []
    Output: 9
    
 

## Constraints:

* $1 \le m, n \le 4 * 10^4$
* $0 \le ops.length \le 10^4$
* $ops[i].length == 2$
* $1 \le a_i \le m$
* $1 \le b_i \le n$

