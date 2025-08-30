package main

import (
	"fmt"
	"math"
)

func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
	ans := math.MaxInt
	for i := range landStartTime {
		for j := range waterStartTime {
			finishLand := landStartTime[i] + landDuration[i]
			finishWater := max(finishLand, waterStartTime[j]) + waterDuration[j]
			ans = min(finishWater, ans)

			finishWater = waterStartTime[j] + waterDuration[j]
			finishLand = max(finishWater, landStartTime[i]) + landDuration[i]
			ans = min(finishLand, ans)
		}
	}
	return ans
}

func main() {
	landStartTime := []int{2, 8}
	landDuration := []int{4, 1}
	waterStartTime := []int{6}
	waterDuration := []int{3}
	fmt.Println(earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration))
}
