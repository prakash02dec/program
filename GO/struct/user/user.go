package user

import (
	"errors"
	"fmt"
	"time"
)

type User struct {
	firstname  string
	lastname   string
	birthdate  string
	created_at time.Time
}

func (user *User) ClearUserName() {
	user.firstname = ""
	user.lastname = ""
}

type Admin struct {
	User
	email string
	password string
}


func (user User) OutputUserDetails() {
	fmt.Println("First Name: ", user.firstname)
	fmt.Println("Last Name: ", user.lastname)
	fmt.Println("Birthdate: ", user.birthdate)
	fmt.Println("Created At: ", user.created_at)
}

func New(firstName, lastName, birthdate string) (*User, error) {
	if firstName == "" || lastName == "" || birthdate == "" {
		return nil, errors.New("all fields are required")
	}
	return &User{
		firstname: firstName,
		lastname:  lastName,
		birthdate: birthdate,
		created_at: time.Now(),
	} , nil

}

func NewAdmin(email, password string) (*Admin, error) {
	if email == "" || password == "" {
		return nil, errors.New("all fields are required")
	}
	return &Admin{
		User: User{
			firstname: "ADMIN",
			lastname:  "ADMIN",
			birthdate: "__/__/____",
			created_at: time.Now(),
		},
		email: email,
		password: password,
	} , nil

}

/*
if use anynomous embedding then you can access the fields of the embedded struct directly
if you use named embedding then you have to access the fields using the name of the embedded struct
*/