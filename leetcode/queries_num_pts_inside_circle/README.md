# Queries on Number of Points Inside a Circle

You are given an array points where $points[i] = [xi, yi]$ is the coordinates  
of the $i^{th}$ point on a 2D plane. Multiple points can have the same  
coordinates.

You are also given an array queries where $queries[j] = [x_j, y_j, r_j]$  
describes a circle centered at $(xj, yj)$ with a radius of $rj$.

For each query $queries[j]$, compute the number of points inside the  
$j^{th}$ circle. Points on the border of the circle are considered inside.

Return an array answer, where $answer[j]$ is the answer to the $j^{th}$ query.

 

## Example 1:

    Input: 
        points = [[1,3],[3,3],[5,3],[2,2]]
        queries = [[2,3,1],[4,3,1],[1,1,2]]

    Output: [3,2,2]

## Example 2:

    Input: 
        points = [[1,1],[2,2],[3,3],[4,4],[5,5]]
        queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]

    Output: [2,3,2,4]

 

## Constraints:

* $1 \le points.length \le 500$
* $points[i].length = 2$
* $0 \le x​​​​​_​i, y​​​​​_​i \le 500$
* $1 \le queries.length \le 500$
* $queries[j].length = 3$
* $0 \le x_j, y_j \le 500$
* $1 \le r_j \le 500$
* All coordinates are integers.
