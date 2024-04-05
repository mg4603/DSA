# Increment Sub-matrices by One

You are given a positive integer n, indicating that we initially have an  
$n \times n$ 0-indexed integer matrix mat filled with zeroes.

You are also given a 2D integer array query. For each  
$query[i] = [row1_i, col1_i, row2_i, col2_i]$, you should do the following  
operation:

* Add 1 to every element in the sub-matrix with the top left corner  
$(row1_i, col1_i)$ and the bottom right corner $(row2_i, col2_i)$. That  
is, add 1 to $mat[x][y]$ for all $row1_i \le x \le row2_i$ and  
$col1_i \le y \le col2_i$.

Return the matrix mat after performing every query.

 

## Example 1:

    Input: n = 3, queries = [[1,1,2,2],[0,0,1,1]]
    Output: [[1,1,0],[1,2,1],[0,1,1]]
    Explanation: 
        The diagram above shows the initial matrix, the  
            matrix after the first query, and the matrix 
            after the second query.

        - In the first query, we add 1 to every element 
            in the submatrix with the top left corner 
            (1, 1) and bottom right corner (2, 2).

        - In the second query, we add 1 to every element 
            in the submatrix with the top left corner 
            (0, 0) and bottom right corner (1, 1).
        
## Example 2:

    Input: n = 2, queries = [[0,0,1,1]]
    Output: [[1,1],[1,1]]
    Explanation: 
        The diagram above shows the initial matrix and  
            the matrix after the first query.

        - In the first query we add 1 to every element in 
            the matrix.
        
        
        
## Constraints:

* $1 \le n \le 500$
* $1 \le queries.length \le 10^4$
* $0 \le row1_i \le row2_i < n$
* $0 \le col1_i \le col2_i < n$

