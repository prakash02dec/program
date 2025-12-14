package routes

import (
	"net/http"
	"strconv"

	"example.com/rest-api/models"
	"github.com/gin-gonic/gin"
)

func getEvents(ctx *gin.Context) {
	events, err := models.GetAllEvents()
	if err != nil {
		ctx.JSON(http.StatusInternalServerError, gin.H{"error": "could not fetch events"})
		return
	}
	ctx.JSON(http.StatusOK, events)
}

func getEvent(ctx *gin.Context) {
	id, err := strconv.ParseInt(ctx.Param("id"), 10, 64)
	if err != nil {
		ctx.JSON(http.StatusBadRequest, gin.H{"error": "invalid event ID"})
		return
	}
	event, err := models.GetEventByID(id)
	if err != nil {
		ctx.JSON(http.StatusInternalServerError, gin.H{"error": "could not fetch event"})
		return
	}
	ctx.JSON(http.StatusOK, event)
}

func createEvent(ctx *gin.Context) {
	var event models.Event

	err := ctx.ShouldBindJSON(&event)
	if err != nil {
		ctx.JSON(http.StatusBadRequest, gin.H{"error": "could not parse the request"})
		return
	}

	event.UserID = 1

	event.Save()

	ctx.JSON(http.StatusCreated, gin.H{
		"message": "Event created successfully",
		"event":   event,
	})
}

func updateEvent(ctx *gin.Context) {
	id, err := strconv.ParseInt(ctx.Param("id"), 10, 64)
	if err != nil {
		ctx.JSON(http.StatusBadRequest, gin.H{"error": "invalid event ID"})
		return
	}
	_ , err = models.GetEventByID(id)

	if err != nil {
		ctx.JSON(http.StatusInternalServerError, gin.H{"error": "could not fetch event"})
		return
	}
	
	var updatedEvent models.Event
	err = ctx.ShouldBindJSON(&updatedEvent)
	if err != nil {
		ctx.JSON(http.StatusBadRequest, gin.H{
			"message": "could not parse the request",
			"error": err.Error(),
		})
		return
	}

	updatedEvent.ID = id
	err = updatedEvent.Update()
	if err != nil {
		ctx.JSON(http.StatusInternalServerError, gin.H{"error": "could not update event"})
		return
	}

	ctx.JSON(http.StatusOK, gin.H{"message": "Event updated successfully"})
}