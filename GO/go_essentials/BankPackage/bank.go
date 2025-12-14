package main

import (
	"fmt"
	"example.com/bankPackage/fileOps"
	"github.com/Pallinder/go-randomdata"
)

const filename = "balance.txt"

/*
byte -> string
string -> byte

other types -> string
string -> other types

other cant be converted to byte
byte cant be converted to other types
*/

func main() {
	var accountBalance float64
	accountBalance, err := fileOps.ReadFloatFromFile(filename)

	if err != nil {
		fmt.Println(err)
		// panic("could not read balance") // a way of exiting the program with an error message
		// stops the execution of the program
		// panic is used to stop the execution of the program
	}

	fmt.Println("welcome to the bank")
	fmt.Println("What do you want to do?")
	fmt.Println(randomdata.PhoneNumber())

	var choice int

	for choice != 4 {
		Menu()
		fmt.Print("Enter your choice: ")
		fmt.Scan(&choice)
		if choice == 1 {
			var depositAmount float64
			fmt.Print("Enter the amount to deposit: ")
			fmt.Scan(&depositAmount)

			if depositAmount < 0 {
				fmt.Println("Invalid amount")
				continue
			}

			accountBalance += depositAmount
			fileOps.WriteFloatToFile(accountBalance, filename)
		} else if choice == 2 {
			var withdrawAmount float64
			fmt.Print("Enter the amount to withdraw : ")
			fmt.Scan(&withdrawAmount)
			if withdrawAmount < 0 || withdrawAmount > accountBalance {
				fmt.Println("Invalid amount")
				continue
			}
			accountBalance -= withdrawAmount
			fileOps.WriteFloatToFile(accountBalance, filename)
		} else if choice == 3 {
			fmt.Println("Your balance is $", accountBalance)
		} else {
			fmt.Println("Thank you for using the bank")
			fileOps.WriteFloatToFile(accountBalance, filename)
			break
		}
	}

	choice = 0
	for choice != 4 {
		Menu()
		fmt.Print("Enter your choice: ")
		fmt.Scan(&choice)
		switch choice {
		case 1:
			fmt.Println("Deposit")
			var depositAmount float64
			fmt.Print("Enter the amount to deposit: ")
			fmt.Scan(&depositAmount)
			if depositAmount < 0 {
				fmt.Println("Invalid amount")
				continue
			}
			accountBalance += depositAmount
			fileOps.WriteFloatToFile(accountBalance, filename)
		case 2:
			var withdrawAmount float64
			fmt.Print("Enter the amount to withdraw : ")
			fmt.Scan(&withdrawAmount)
			if withdrawAmount < 0 || withdrawAmount > accountBalance {
				fmt.Println("Invalid amount")
				continue
			}
			accountBalance -= withdrawAmount
			fileOps.WriteFloatToFile(accountBalance, filename)
		case 3:
			fmt.Println("Your balance is $", accountBalance)
		case 4:
			fmt.Println("Exiting")
			fileOps.WriteFloatToFile(accountBalance, filename)
		default:
			fmt.Println("Invalid choice")
		}
	}

}

/*

	normal for loop

	for i := 0; i < 4; i++ {
	}


	while loop

	for i != 1 {
	}


	infinite loop

	for {
	}

*/
/*


break keyword in switch statement
	- break keyword is used to exit the switch statement
	- but in Go, break keyword is not required
	- Go automatically exits the switch statement when a case is matched




	panic("could not read balance") // a way of exiting the program with an error message
		// stops the execution of the program
		// panic is used to stop the execution of the program


*/


/*

go get path to download the package

go mod tidy to download the dependencies and update the go.mod file

go mod init is used to convert the project into module

*/