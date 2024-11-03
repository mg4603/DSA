package main

import (
	"bufio"
	"fmt"
	"os"
)

func createBill() bill {
	reader := bufio.NewReader(os.Stdin)

	name, _ := getInput(reader, "Create a new bill name: ")

	bill := newBill(name)
	fmt.Println("Created the bill - ", bill.name)
	return bill
}

func main() {
	myBill := createBill()
	// a copy of mybill is passed into
	// 	receiver function format
	fmt.Println(myBill.format())

}
