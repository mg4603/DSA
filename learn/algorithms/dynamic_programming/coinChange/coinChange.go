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

/*
Problem:

	Find the total number of ways to make change n
	by using exactly c coins.

1.	Objective Function:
		F(i, c) is the total number of ways to make
		change i with exactly c coins.

2.	Base Case:
		F(i, 0) = 0
		F(0, 0) = 1

		if i in denominations:
			F(i, 1) = 1
		else:
			F(i, 1) = 0

3. 	Transition function:

		for j in denominations:
			if i >= j:
				F(i, c) += F(i - j, c - 1)

*/

func exactlyCCoins(n int, c int, denominations []int) int {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, c+1)
	}

	dp[0][0] = 1

	for _, denomination := range denominations {
		for i := 1; i <= n; i++ {
			for j := 1; j <= c; j++ {
				if i >= denomination {
					dp[i][j] += dp[i-denomination][j-1]
				}
			}
		}
	}
	return dp[n][c]
}
