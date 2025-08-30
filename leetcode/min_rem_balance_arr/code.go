package minrembalancearr

import "sort"

func quickSort(nums []int) []int {
	n := len(nums)
	if n <= 1 {
		return nums
	}

	pivot := nums[n/2]
	left := make([]int, 0)
	middle := make([]int, 0)
	right := make([]int, 0)

	for _, x := range nums {
		if x < pivot {
			left = append(left, x)
		} else if x == pivot {
			middle = append(middle, x)
		} else {
			right = append(right, x)
		}
	}
	return append(append(quickSort(left), middle...), quickSort(right)...)
}

func minRemoval(nums []int, k int) int {
	n := len(nums)
	if n <= 1 {
		return 0
	}
	sort.Ints(nums)

	l := 0
	best := 1
	for r := 0; r < n; r++ {
		for l <= r && nums[r] > nums[l]*k {
			l++
		}
		best = max(best, (r - l + 1))
	}
	return n - best
}
