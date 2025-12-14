package main

import "fmt"

func main() {
	fmt.Print("Hello, World!")
}

/*

fmt is package that provides I/O functions like Print, Println, Printf, etc.
main is the entry point of the program.
The main function in Go is similar to the main function in C and C++.
package main is a special package in Go. It is used to create an executable file.

one go project can have multiple packages, but only one package can have main function.
one package can have multiple files, but only one file can have main function.


go run app.go           

is one way to run the program.

but 

go build         

is another way to run the program.
but it will require main module


go mod init is used to convert the project into module


*/