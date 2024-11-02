package main

import "fmt"

type bill struct {
	name  string
	items map[string]float64
	tip   float64
}

func newBill(name string) bill {
	b := bill{
		name:  name,
		items: map[string]float64{},
		tip:   0,
	}
	return b
}

// receiver functions => functions associated
//  with object of a particular data stucture

// an object b of type bill is rececived into
//	the format function

func (b bill) format() string {
	fs := "Bill Breakdown: \n"
	var total float64 = 0

	for k, v := range b.items {
		total += v
		fs += fmt.Sprintf("%-25v ...$%v \n", k+":", v)
	}
	// -25 to right align padded and pad it 25 spaces
	// 25 to left align variable and pad it 25 spaces
	fs += fmt.Sprintf("%-25v ...$%0.2f \n", "total:", total)
	return fs
}

func (b *bill) updateTip(tip float64) {
	b.tip = tip
}
