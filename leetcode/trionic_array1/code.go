package trionicarray1

import "fmt"

// Greedy solution
// func isTrionic(nums []int) bool {
//     n := len(nums)
//     if n < 4{
//         return false
//     }
//     i := 0

//     for i < n - 1 && nums[i + 1] > nums[i] {
//         i++
//     }

//     if i == 0 {
//         return false
//     }
//     p := i
//     for i < n - 1 && nums[i + 1] < nums[i] {
//         i++
//     }
//     if i == p {
//         return false
//     }
//     q := i
//     for i < n - 1 && nums[i + 1] > nums[i] {
//         i++
//     }
//     if q == i {
//         return false
//     }
//     return i == n - 1
// }

// state machine
const (
	Inc = iota
	Dec
	Inc2
)

func isTrionic(nums []int) bool {
	n := len(nums)
	if n < 4 {
		return false
	}
	state := Inc
	for i := 0; i < n-1; i++ {
		switch state {
		case Inc:
			if nums[i+1] > nums[i] {
				continue
			} else if nums[i+1] == nums[i] {
				return false
			} else {
				if i == 0 {
					return false
				}
				state = Dec
			}
		case Dec:
			if nums[i+1] < nums[i] {
				continue
			} else if nums[i+1] == nums[i] {
				return false
			} else {
				state = Inc2
			}
		case Inc2:
			if nums[i+1] > nums[i] {
				continue
			} else {
				return false
			}
		}
	}
	fmt.Println(state)
	return state == Inc2
}
