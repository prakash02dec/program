package main

import (
	"fmt"
	"example.com/structs/user"
)



func main() {


	// fmt.Println(user)
	firstName := getUserData("Please enter your first name: ")
	lastName := getUserData("Please enter your last name: ")
	birthdate := getUserData("Please enter your birthdate (MM/DD/YYYY): ")

	// ... do something awesome with that gathered data!
	// appUser := User{}
	var appuser *user.User
	appuser, err := user.New(firstName, lastName, birthdate)
	if err != nil {
		fmt.Println("Error creating user: ", err)
		return
	}
	appuser.OutputUserDetails()
	appuser.ClearUserName()
	appuser.OutputUserDetails()

	admin, err := user.NewAdmin("test@gmail.com", "password")
	admin.User.OutputUserDetails()
}



func getUserData(promptText string) string {
	fmt.Print(promptText)
	var value string
	fmt.Scan(&value)
	return value
}


/*
Scan doesnt work with spaces
scanln works with spaces 
*/


// custome data type
// alias
// in custom data type we can add methods
// we can add methods to any type except built in types


// type customString string


// func (c customString) log() {
// 	fmt.Println(c)
// }

// to force a type to be used as a type
// we have to define a variable of that type first then we can use it as a type