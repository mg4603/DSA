package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func getInput(reader *bufio.Reader, prompt string) (string, error) {
	fmt.Print(prompt)

	// returns input and error on reading from specified source
	//  stdin in this case

	// reads everything the user has typed in up until they
	// 	entered a specific character

	// reader reads after user has entered a new line (hit enter)

	input, err := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	return input, err
}

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
