package todo

import (
	"encoding/json"
	"errors"
	"os"
	"strings"
)

type todo struct {
	Text string `json:"text"`
}

func New(text string) (*todo , error) {
	if text == "" {
		return nil, errors.New("no input provided for")
	}
	return &todo{
		text,
	}, nil
}

func (n *todo) Display()  {
	println("Todo: ", n.Text)
}

func (n *todo) Save() error {
	fileName := "todo" + ".json"
	fileName = strings.ToLower(fileName)
	r ,_:= json.Marshal(n)
	os.WriteFile(fileName, r, 0644)
	return nil
}

func (n *todo) GetText() string {
	return n.Text
}

