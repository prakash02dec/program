package note

import (
	"encoding/json"
	"errors"
	"os"
	"strings"
	"time"
)

type Note struct {
	Title   string	 `json:"title"`
	Content string `json:"content"`
	Created time.Time `json:"created"`
}

func New(title, content string) (*Note , error) {
	if title == "" || content == "" {
		return nil, errors.New("no input provided for")
	}
	return &Note{
		title,
		content,
		time.Now(),
	}, nil
}

func (n *Note) Display()  {
	println("Title: ", n.Title)
	println("Content: ", n.Content)
}	

func (n *Note) Save() error {
	fileName := strings.ReplaceAll(n.Title, " ", "_") + ".json"
	fileName = strings.ToLower(fileName)
	r ,_:= json.Marshal(n)
	os.WriteFile(fileName, r, 0644)
	return nil
}

func (n *Note) GetTitle() string {
	return n.Title
}

func (n *Note) GetContent() string {
	return n.Content
}
