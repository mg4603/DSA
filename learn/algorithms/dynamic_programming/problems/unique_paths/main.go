package uniquepaths

/*
Problem:
	How many unique ways exist to get to (m, n) from
	(0, 0) in a grid if at each cell you can either move
	one cell to the right or to the bottom.

1) Objective function
	F(i, j) gives the number of ways to get to cell (i, j)
2) Base Case:
	F(0, 0) => the number of ways to get to cell (0, 0):
		F(0, 0) = 1
3) Transition function:
	F(i, j) = F(i - 1, j) + F(i, j - 1)
*/

func uniquePaths(m int, n int) int {
	if m == 0 || n == 0 {
		return 0
	}
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
		dp[i][0] = 0
	}

	dp[0][0] = 1

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i-1 >= 0 {
				dp[i][j] += dp[i-1][j]
			}

			if j-1 >= 0 {
				dp[i][j] += dp[i][j-1]
			}
		}
	}
	return dp[m-1][n-1]
}

type Pair struct {
	i, j int
}
