package main

// formating string, printing
// messages to console
import (
	"fmt"
	"math"
	"sort"
	"strings"
)

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

func arraySlices() {
	// arrays
	// 	> size is pre-defined and cannot change
	// explicit array declaration
	var numsArrOne [4]int = [4]int{1, 2, 3, 4}
	// inferred array declaration
	var numsArrTwo = [4]int{5, 6, 7, 8}

	// shorthand declaration
	stringsArrOne := [4]string{
		"StringOne",
		"StringTwo",
		"StringThree",
		"StringFour"}

	fmt.Println(numsArrOne, len(numsArrOne))
	fmt.Println(numsArrTwo, len(numsArrTwo))
	fmt.Println(stringsArrOne, len(stringsArrOne))

	// slices
	// 	> dynamic arrays
	// 	> use arrays in the background
	// 	> if length is not defined go creates a
	// 		slice rather than an array

	var slices = []int{9, 10, 11, 12}
	fmt.Println(slices, len(slices))

	// append doesn't change the slice
	// it returns a new slice with the element
	// 	being added appended to the end
	// 	so it needs to be reinitialized
	slices = append(slices, 13)
	fmt.Println(slices, len(slices))

	// ranges are slices
	// 	> you can get a range of a slice or array
	// 	> all operations that apply to slices
	// 		also apply to ranges

	// elements from 1 to 3 excluding 3
	rangeOne := stringsArrOne[1:3]
	fmt.Println(rangeOne)

	// elements from index 2 to end
	rangeTwo := stringsArrOne[2:]
	fmt.Println(rangeTwo)

	// elements from index 0 to 3 excluding 3
	rangeThree := stringsArrOne[:3]
	fmt.Println(rangeThree)

}

func stringPackage() {

	stringOne := "Hello World!"

	// strings.Contains(stringToBeChecked, stringToCheck)
	fmt.Println("\""+stringOne+"\"", "contains", "\"Hello\"?",
		strings.Contains(stringOne, "Hello"))

	fmt.Println("\""+stringOne+"\"", "contains",
		"\"Hello!\"?", strings.Contains(stringOne, "Hello!"))

	// ReplaceAll
	// 	Doesn't alter original string, returns a new one
	fmt.Println("Replace all occurrences of Hello with Goodbye:\n",
		strings.ReplaceAll(stringOne, "Hello", "Goodbye,"))

	// convert string to uppercase
	// 	Doesn't alter original string, returns a new one
	fmt.Println(strings.ToUpper(stringOne))

	// Index
	// 	find index of first occurence in string
	fmt.Println(strings.Index(stringOne, "World"))

	// split
	// 	returns a slice of strings
	// 	split at each point where string to
	// 	split by orrured
	fmt.Println(strings.Split(stringOne, " W"))

}

func sortPackage() {
	intsOne := []int{45, 63, 721, 81, 9, 13}

	// Ints
	// 	> sorts the elements of an integer array
	// 	> the original array is changed
	fmt.Println((intsOne))
	sort.Ints(intsOne)
	fmt.Println((intsOne))

	// SearchInts
	//	> returns the index of element being searched
	// 	  for in sorted integer array
	//  > if element searched for doesn't exists
	// 	  function returns length of array + 1
	fmt.Println("Position of 63: ",
		sort.SearchInts(intsOne, 63))

	stringOne := []string{"StringOne", "StringTwo",
		"StringThree", "StringFour"}
	fmt.Println(stringOne)
	sort.Strings(stringOne)
	fmt.Println(stringOne)

	// SearchStrings
	// 	> returns the index of element being searched
	// 	  form in sorted strings array
	fmt.Println(sort.SearchStrings(stringOne, "StringOne"))
}

func loops() {
	// All loops use for keyword

	// while loop
	i := 0
	for i < 5 {
		fmt.Print(i)
		if i != 4 {
			fmt.Print(", ")
		}
		i++
	}
	fmt.Println()

	// for loops
	for i := 5; i < 10; i++ {
		fmt.Print(i)
		if i != 9 {
			fmt.Print(", ")
		}
	}
	fmt.Println()

	numsOne := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}

	// index and value at index

	// value is a local variable,
	//	changing it doesn't change the slice
	for index, value := range numsOne {
		fmt.Printf("the value at index %v is %v\n",
			index, value)
	}

	// if value or index aren't required, use _

	for _, value := range numsOne {
		fmt.Printf("the value at %v\n", value)

	}
}

func booleansConditionals() {
	num := 123

	fmt.Println(num <= 100)
	fmt.Println(num >= 100)
	fmt.Println(num == 123)
	fmt.Println(num != 124)

	if num < 100 {
		fmt.Println("Num is less than 100")
	} else if num < 110 {
		fmt.Println("Num is less than 110")
	} else {
		fmt.Println("Num is not less than than 110")
	}

	nums := []int{1, 2, 3, 4, 5, 6, 7, 8}

	for idx, value := range nums {
		if idx == 1 {
			fmt.Println("Continuing at pos", idx)
			continue
		}

		if idx > 5 {
			fmt.Println("Breaking at pos", idx)
			break
		}
		fmt.Printf("The value at pos %v is %v\n", idx, value)

	}
}

func sayGreeting(name string) {
	fmt.Printf("Good morning %v!\n", name)
}

func sayBye(name string) {
	fmt.Printf("Goodbye %v \n", name)
}

// pass function to function
func cycleNames(names []string, f func(string)) {
	for _, name := range names {
		f(name)
	}
}

func circleArea(r float64) float64 {
	return math.Pi * r * r
}

func main() {
	// numbersStringVariables()
	// printingFormattingString()
	// arraySlices()
	// stringPackage()
	// sortPackage()
	// loops()
	// booleansConditionals()
	// sayGreeting("World")

	// > pass reference to function sayGreeting
	// 		to function cycleNames
	// > don't invoke function
	// names := []string{"name1", "name2", "name3"}
	// cycleNames(names, sayGreeting)
	// cycleNames(names, sayBye)

	a1 := circleArea(10.5)
	a2 := circleArea(15)
	fmt.Printf("Circle1 is %0.3f\n", a1)
	fmt.Printf("Circle2 is %0.3f\n", a2)
}
