package coinchange

/*
Problem:

	Given an unlimited supply of coins of given
	denominations, find the total number of
	ways to make change n

1. 	Objective function:
		F(i) is the total number of ways to make
		change i

2.	Base Change:
		F(0) = 1

3.	Transition Function:

		F(n) = F(n - denominations[j]),

		if n - denominations[j] >= 0
		where,
		 j := 0 to m
		 m is the number of denominations

4.	Position of solution in cache:

		nth index

*/

func coinChange(denominations []int, n int) int {
	dp := make([]int, n+1)
	dp[0] = 1

	for _, denomination := range denominations {
		for i := 1; i <= n; i++ {
			if i >= denomination {
				dp[i] += dp[i-denomination]
			}
		}
	}
	return dp[n]
}
