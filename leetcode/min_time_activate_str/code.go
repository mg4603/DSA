package mintimeactivatestr

// naive(finding number of valid strings) + binary search

func minTime(s string, order []int, k int) int {
	n := len(s)
	totalStrings := n * (n + 1) / 2

	valid := func(t int) int {
		isStarred := make([]bool, n)

		for i := 0; i <= t; i++ {
			isStarred[order[i]] = true
		}

		invalidStrings := 0
		sLen := 0
		for i := 0; i < n; i++ {
			if isStarred[i] {
				invalidStrings += sLen * (sLen + 1) / 2
				sLen = 0
			} else {
				sLen++
			}
		}

		return totalStrings - (invalidStrings + (sLen * (sLen + 1) / 2))
	}

	ans := -1
	l := 0
	r := n - 1
	for l <= r {
		mid := (l + r) / 2
		validStrings := valid(mid)
		if validStrings >= k {
			ans = mid
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return ans
}
