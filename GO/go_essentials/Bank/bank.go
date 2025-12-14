package main

import (
	"fmt"
	"os"
	"strconv"
	"errors"
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

func readBalanceFromFile() (float64, error) {
	// read the balance from a file
	data, err := os.ReadFile(filename)
	if err != nil {
		return 1000, errors.New("file not found")
	}

	balancetxt := string(data)
	var balance float64
	balance, err = strconv.ParseFloat(balancetxt, 64)
	if err != nil {
		return 1000 , errors.New("invalid data in file")
	}
	return balance, nil
}

func writeBalanceToFile(balance float64) {
	// write the balance to a file
	balancetxt := fmt.Sprint(balance)
	os.WriteFile(filename, []byte(balancetxt), 0644)

}


func main() {
	var accountBalance float64 
	accountBalance, err := readBalanceFromFile()

	if err != nil {
		fmt.Println(err)
		panic("could not read balance") // a way of exiting the program with an error message 
		// stops the execution of the program
		// panic is used to stop the execution of the program
	}

	fmt.Println("welcome to the bank")
	fmt.Println("What do you want to do?")
	fmt.Println("1. Deposit")
	fmt.Println("2. Withdraw")
	fmt.Println("3. Check Balance")
	fmt.Println("4. Exit")

	var choice int

	for choice != 4 {
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
		} else if choice == 2 {
			var withdrawAmount float64
			fmt.Print("Enter the amount to withdraw : ")
			fmt.Scan(&withdrawAmount)
			if withdrawAmount < 0 || withdrawAmount > accountBalance {
				fmt.Println("Invalid amount")
				continue
			}
			accountBalance -= withdrawAmount
		} else if choice == 3 {
			fmt.Println("Your balance is $", accountBalance)
		} else {
			fmt.Println("Thank you for using the bank")
			writeBalanceToFile(accountBalance)
			break
		}
	}



	for choice != 4 {
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

		case 2:
			fmt.Println("Withdraw")
		case 3:
			fmt.Println("Check Balance")
		case 4:
			fmt.Println("Exit")
			return 
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