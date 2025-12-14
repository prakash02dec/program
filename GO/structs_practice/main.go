package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"

	"example.com/note/note"
)

func main() {
	title, content := getNoteData()

	note, err := note.New(title, content)
	if err != nil {
		panic(err)
	}
	fmt.Println("Title: ", note.GetTitle())
	fmt.Println("Content: ", note.GetContent())
	note.Save()
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
