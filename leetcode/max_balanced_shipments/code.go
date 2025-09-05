package maxbalancedshipments

// last item in shipment must be strictly less than max in shipment
// (monotonic stack)
// keep a counter
// if weight[i] < weight[i-1]
//
//	    counter++
//	    i += 2
//	else i++

func maxBalancedShipments(weight []int) int {
	ans := 0
	i := 1
	for i < len(weight) {
		if weight[i] < weight[i-1] {
			ans++
			i += 2
		} else {
			i++
		}
	}
	return ans
}
