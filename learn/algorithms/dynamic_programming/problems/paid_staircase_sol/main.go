package paidstaircasesol

/*
Problem:

	Find cheapest path to the top of staircase if
	each step has a cost and you can climb 1...k
	stairs at any step
*/

func reverseSlice(s []int) []int {
	if len(s) == 0 {
		return s
	}
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return s
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
