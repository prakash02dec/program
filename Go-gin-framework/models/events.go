package models

import (
	"fmt"
	"time"
	"example.com/rest-api/db"
)

type Event struct {
	ID int64 `json:"id"`
	Name string `json:"name"`
	Description string `json:"description"`
	Location string `json:"location"`
	DateTime time.Time `json:"datetime"`
	UserID int `json:"userid"`
}


func (event *Event) Save() error{
	// later : add it to a database
	query := `
	INSERT INTO events 
	(name, description, location, datetime, user_id) 
	VALUES (?, ?, ?, ?, ?)`
	stmt, err := db.DB.Prepare(query)
	if err != nil {
		return err 
	}
	defer stmt.Close()
	result ,e := stmt.Exec(event.Name, event.Description, event.Location, event.DateTime, event.UserID)
	if e != nil {
		return e
	}
	id, err := result.LastInsertId()
	event.ID = id


	return err
}

func GetAllEvents() ([]Event, error) {
	query := `
		SELECT * from events
	`
	rows, err := db.DB.Query(query)
	if err != nil {
		return nil , err
	}
	defer rows.Close()
	events := []Event{}
	for rows.Next() {
		var event Event
		rows.Scan(&event.ID, &event.Name, &event.Description, &event.Location, &event.DateTime, &event.UserID)
		fmt.Println("1")
		events = append(events, event)
	}
	return events , nil
}

func GetEventByID(id int64) (*Event, error){
	query := `
		SELECT * from events where id = ?
	`
	row := db.DB.QueryRow(query, id)
	var event Event
	err := row.Scan(&event.ID, &event.Name, &event.Description, &event.Location, &event.DateTime, &event.UserID)
	if err != nil {
		return nil, err
	}
	return &event, nil
}

func (event Event) Update() error {
	query := `
		UPDATE events 
		SET name = ?, description = ?, location = ?, datetime = ?
		WHERE id = ?	
	`
	stmt, err := db.DB.Prepare(query)
	if err != nil {
		return err
	}
	defer stmt.Close()
	_, e := stmt.Exec(event.Name, event.Description, event.Location, event.DateTime, event.ID)
	return e
}