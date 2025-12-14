package main

import "fmt"

func main() {
	age := 32 // age is a variable of type int\

	var agePointer *int // agePointer is a variable of type pointer to int
	agePointer = &age
	fmt.Println("age pointer", agePointer)
	fmt.Println("age value", *agePointer)
	fmt.Println("Age is: ", age)
	getAdultyear(&age)
	fmt.Println("Adult years: ", age)
	return 
}

func getAdultyear(age *int) {
	*age = *age -18
}
/*
we can not perform arithmetic operations on pointers
we can not add or subtract pointers

*/