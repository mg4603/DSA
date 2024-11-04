package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

func getItem(reader *bufio.Reader) (string, float64) {
	item_name, _ := getInput(reader, "Item Name: ")
	price_string, _ := getInput(reader, "Item price: ")

	price, err := strconv.ParseFloat(price_string, 64)

	if err != nil {
		fmt.Println("The price must be a number")
		return getItem(reader)
	}
	return item_name, price
}

func promptOptions(b *bill) {
	reader := bufio.NewReader(os.Stdin)

	option, _ := getInput(
		reader,
		"Choose option (a - add item, s - save bill, t - add tip): ")

	switch option {
	case "a":
		item_name, _ := getInput(reader, "Item Name: ")
		price_string, _ := getInput(reader, "Item price: ")

		price, err := strconv.ParseFloat(price_string, 64)

		if err != nil {
			fmt.Println("The price must be a number")
			promptOptions(b)
			return
		}

		b.addItem(item_name, price)

		fmt.Println("item added - ", item_name, price)
		promptOptions(b)
	case "t":
		tip_string, _ := getInput(reader, "Enter tip amount ($): ")

		tip, err := strconv.ParseFloat(tip_string, 64)

		if err != nil {
			fmt.Println("The tip must be a number")
			promptOptions(b)
			return
		}

		b.updateTip(tip)
		fmt.Println("tip added - ", tip)
		promptOptions(b)
	case "s":
		b.save()
		fmt.Println("You saved the bill - ", b.name)
	default:
		fmt.Println("that was not a valid option...")
		promptOptions(b)
	}
}

func main() {
	myBill := createBill()

	promptOptions(&myBill)

}
