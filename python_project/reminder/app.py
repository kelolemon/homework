import requests


def send_simple_message():
    return requests.post(
        "https://api.mailgun.net/v3/mail.cetacis.codes/messages",
        auth=("api", "xx"),
        data={"from": "Study Bot <notification@cetacis.codes>",
              "to": ["una@cetacis.dev"],
              "subject": "Work review",
              "text": "Today you have done a lot of work!(Z E R O!)"}
    )


if __name__ == '__main__':
    send_simple_message()
