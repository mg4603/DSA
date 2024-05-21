# Count Sub-matrices with Top-Left Element and Sum Less Than K

You are given a 0-indexed integer matrix grid and an integer k.

Return the number of submatrices that contain the top-left element of the  
grid, and have a sum less than or equal to k.

 

## Example 1:

    Input: grid = [[7,6,3],[6,6,1]], k = 18
    Output: 4
    Explanation: 
        There are only 4 submatrices, shown in the image 
            above, that contain the top-left element of 
            grid, and have a sum less than or equal to 18.

## Example 2:

    Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
    Output: 6
    Explanation: 
        There are only 6 submatrices, shown in the image 
            above, that contain the top-left element of 
            grid, and have a sum less than or equal to 20.

 

## Constraints:

* $m == grid.length $
* $n == grid[i].length$
* $1 \le n, m \le 1000 $
* $0 \le grid[i][j] \le 1000$
* $1 \le k \le 10^9$

