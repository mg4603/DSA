package main

import "fmt"

// formating string, printing
// messages to console

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

	// a1 := circleArea(10.5)
	// a2 := circleArea(15)
	// fmt.Printf("Circle1 is %0.3f\n", a1)
	// fmt.Printf("Circle2 is %0.3f\n", a2)

	// fn, ln := getInitials("name surname")
	// fmt.Println(fn, ln)
	//
	// fn2, ln2 := getInitials("name2 middlename2 surname2")
	// fmt.Println(fn2, ln2)
	//
	// fn3, ln3 := getInitials("name3")
	// fmt.Println(fn3, ln3)
	// mapsTutorial()

	str := "String"
	fmt.Println(str)
	pointerTutorial(&str)
	fmt.Println(str)

}
