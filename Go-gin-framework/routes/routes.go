package routes	

import (
	"github.com/gin-gonic/gin"
)
func RegisterRoutes(server *gin.Engine) {
	server.GET("/events", getEvents ) // get request
	server.GET("/events/:id", getEvent )
	server.POST("/events", createEvent) // post request
	server.PUT("/events/:id", updateEvent) // put request
	server.DELETE("/events/:id", )
}