package main

import (
	"fmt"
	"io/ioutil"
	_ "io/ioutil"
	"log"
	"os"

	"github.com/sendgrid/sendgrid-go"
	"github.com/sendgrid/sendgrid-go/helpers/mail"
)

func main() {
	user := os.Args[1]
	var email1 string
	var email2 string
	if user == "una" {
		email1 = "una@cetacis.dev"
		email2 = "std.una.shi@gmail.com"
	} else {
		email1 = "kelo@cetacis.dev"
		email2 = "std.kelo.deng@gmail.com"
	}
	b, err := ioutil.ReadFile("html.text" + user)
	htmlText := string(b)
	from := mail.NewEmail("Study bot", "notification@cetacis.codes")
	to := mail.NewEmail(user, email1)
	subject := "Task List"
	plainTextContent := "Please to see the html content"
	htmlContent := htmlText
	message := mail.NewSingleEmail(from, subject, to, plainTextContent, htmlContent)
	client := sendgrid.NewSendClient(os.Getenv("SENDGRID_API_KEY"))
	response, err := client.Send(message)
	if err != nil {
		log.Println(err)
	} else {
		fmt.Println(response.StatusCode)
		fmt.Println(response.Body)
		fmt.Println(response.Headers)
	}
	to = mail.NewEmail(user, email2)
	message = mail.NewSingleEmail(from, subject, to, plainTextContent, htmlContent)
	client = sendgrid.NewSendClient(os.Getenv("SENDGRID_API_KEY"))
	response, err = client.Send(message)
	if err != nil {
		log.Println(err)
	} else {
		fmt.Println(response.StatusCode)
		fmt.Println(response.Body)
		fmt.Println(response.Headers)
	}
}