package mostprofitablepath

/*
Problem:

    Find the path from the top-left corner (0, 0) to the
    bottom-right corner (m, n) of a grid that maximizes
    profit. You can only move right or down at each step.

1. Objective function:

    F(i, j) is the most profit that you can get at (i,j)

2. Base Case:

    F(0, 0) = cost(0,0)

3. Transition function:

    F(i, j) = max{F(i - 1, j), F(i, j - 1)} + cost(i, j)

4.  Location of result:

    (m-1, n - 1) position of 2-d cache
*/

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
