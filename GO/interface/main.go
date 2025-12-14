package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"

	"example.com/note/note"
	"example.com/note/todo"
)

type saver interface {
	Save() error
}

type Displayer interface {
	Display() 
}

type outputable interface {
	saver
	Displayer
}

func main() {
	title, content := getNoteData()
	todoText := getUserInput("Enter your todo: ")
	todo , err := todo.New(todoText)
	if err != nil {
		panic(err)
	}
	note, err := note.New(title, content)
	if err != nil {
		panic(err)
	}
	OutputData(todo)
	OutputData(note)


}

func OutputData(data outputable) {
	data.Display()
	saveDate(data)
}

func saveDate(save saver) error {
	err := save.Save()
	return err
}


func getNoteData() (string, string) {
	title := getUserInput("Enter your title: ")
	content := getUserInput("Enter your content: ")

	return title, content
}

func getUserInput(prompt string) string {
	fmt.Print(prompt)
	var input string
	reader := bufio.NewReader(os.Stdin)

	input, _ = reader.ReadString('\n')

	input = strings.TrimSuffix(input, "\n")
	input = strings.TrimSuffix(input, "\r")

	return input
}
