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

func MostProfit(cost [][]int) int {
	m := len(cost)
	if m == 0 {
		return 0
	}
	n := len(cost[0])

	if n == 0 {
		return 0
	}

	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
	}
	dp[0][0] = cost[0][0]

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i-1 >= 0 && j-1 >= 0 {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + cost[i][j]
			} else if i-1 >= 0 {
				dp[i][j] = dp[i-1][j] + cost[i][j]
			} else if j-1 >= 0 {
				dp[i][j] = dp[i][j-1] + cost[i][j]
			}

		}
	}
	return dp[m-1][n-1]
}

type Pair struct {
	i, j int
}

func reverseSlice[T any](s []T) []T {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}
