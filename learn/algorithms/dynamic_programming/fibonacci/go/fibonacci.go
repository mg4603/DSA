package fibonacci

// recursive solution
func fib(n int) int {
	if n == 0 {
		return 0
	}
	if n <= 2 {
		return 1
	}
	return fib(n-1) + fib(n-2)
}

// Top-down solution: (memoization + recursion)
func fibTopDown(n int) int {
	memo := make(map[int]int)
	return fibTopDownHelper(n, memo)
}

func fibTopDownHelper(n int, memo map[int]int) int {
	if n == 0 {
		return 0
	}
	if n <= 2 {
		return 1
	}
	if res, ok := memo[n]; ok {
		return res
	}

	memo[n] = fibTopDownHelper(n-1, memo) + fibTopDownHelper(n-2, memo)
	return memo[n]
}
