package main

// formating string, printing
// messages to console
import "fmt"

func main() {
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
