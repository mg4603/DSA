package earliestfintmlandwaterrides2

import (
	"math"
)

func earliestFinishTime(landStart []int, landDuration []int, waterStart []int, waterDuration []int) int {
	ans := math.MaxInt32

	n := len(waterStart)
	bestWater := math.MaxInt32
	for i := 0; i < n; i++ {
		waterFinish := waterStart[i] + waterDuration[i]
		bestWater = min(bestWater, waterFinish)
	}

	m := len(landStart)
	bestLand := math.MaxInt32
	for i := 0; i < m; i++ {
		landFinish := landStart[i] + landDuration[i]
		bestLand = min(bestLand, landFinish)

		ans = min(ans, max(bestWater, landStart[i])+landDuration[i])
	}

	for i := 0; i < n; i++ {
		ans = min(ans, max(bestLand, waterStart[i])+waterDuration[i])
	}
	return ans
}
