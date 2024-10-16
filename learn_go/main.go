package main

// formating string, printing
// messages to console
import "fmt"

func numbersStringVariables() {
	fmt.Println("Hello World!")

	// explicit declarattion
	var stringOne string = "String One"

	// compiler infers type
	// (type of stringTwo cannot be changed in future)
	var stringTwo = "String Two"

	// declared not initialized
	// (by default is an empty string)
	var stringThree string
	stringThree = "String Three"

	fmt.Println(stringOne, stringTwo, stringThree)

	// can't change type
	stringOne = "New String One"
	fmt.Println(stringOne, stringTwo, stringThree)

	// short hand declaration for
	// var stringFour = "String Four"
	// shorthand declartion can only be used in functions
	stringFour := "String Four"
	fmt.Println(stringOne, stringTwo, stringThree, stringFour)

	fmt.Println()

	// INTS

	// explicit type declartion
	var numOne int = 1

	// type inferred by compiler
	var numTwo = 2

	// shorthand inferred type declartion
	// equivalent to:
	// var numThree = 3;
	numThree := 3
	fmt.Println(numOne, numTwo, numThree)

	// bits & memory
	// types for int:
	// 	int8
	// 	int16
	//  int32
	//  int64

	// 8 bit int - nums in range -2^7 to 2^7-1
	var numFour int8 = -128

	// unsigned int : uint
	// 	whole numbers only

	// uint8: nums in range 0 to 2^8-1
	var numFive uint8 = 255
	fmt.Println(numFour, numFive)

	// FLOAT
	// 	> decimals
	//  > default is float64 on 64 bit machine
	// 	> have to define as float32 or float64
	// 	> float64 has higher precision than float32

	var decimalOne float32 = 32.98
	var decimalTwo float64 = 128.954
	var decimalThree = 25.45
	decimalFour := 2556.237984
	fmt.Println(decimalOne, decimalTwo, decimalThree, decimalFour)
}

func printingFormattingString() {
	// Print
	// prints to console
	fmt.Print("\n\nPrint ")
	fmt.Print("function\n")

	// Println
	// prints to console and adds new line at the end
	fmt.Println("Println function")

	// Printf
	// formatted string
	//  format specifiers: of form %_

	// %v : default for variables
	stringOne := "asdf"
	numOne := 12
	fmt.Printf(
		"This is a number: %v and this is a string: %v\n",
		numOne, stringOne)

	//%q :
	//	1) places double quotes around a string
	//	2) only works with strings
	//	3) replaces number with \f ====> '\f'

	fmt.Printf(
		"This is a number: %q and this is a string: %q\n",
		numOne, stringOne)

	// %T : gets the type of the variable
	fmt.Printf(
		"This is a number: %T and this is a string: %T\n",
		numOne, stringOne)

	// %f : format specifier for float
	// 	> %0._f : _ number of places after decimal point (rounded up)
	fmt.Printf("This is a float %f \n", 256.154)
	fmt.Printf("This is a float %0.1f \n", 256.154)
	fmt.Printf("This is a float %0.3f \n", 256.154)

	// Sprintf
	// 	save formatted strings in variable
	var formattedString = fmt.Sprintf("This is a number: %v and this is a string: %v\n",
		numOne, stringOne)

	fmt.Print("Saved formatted string: \n\t", formattedString)
}

func main() {
	numbersStringVariables()
	printingFormattingString()
}
