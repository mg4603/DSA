package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func createBill() bill {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Create a new bill name: ")

	// returns input and error on reading from specified input
	//  stdin in this case

	// reads everything the user has typed in up until they
	// 	entered a specific character

	// reader reads after user has entered a new line (hit enter)
	name, _ := reader.ReadString('\n')
	name = strings.TrimSpace(name)

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
