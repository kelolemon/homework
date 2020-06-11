import smtplib
from email.mime.text import MIMEText

MAIL_HOSTS = "smtp.zoho.com"
mail_user = "bot@cetacis.dev"
mail_pass = "Cutesinapis6235283333!"
mail_postfix = "cetacis.dev"


def send_mail(to_list, sub, content):
    msg = MIMEText(content, _subtype='plain', _charset='utf-8')
    msg['Subject'] = sub
    msg['From'] = mail_user
    msg['To'] = ";".join(to_list)
    server = smtplib.SMTP()
    server.connect(MAIL_HOSTS, 587)
    server.ehlo()
    server.set_debuglevel(1)
    server.starttls()
    server.login(mail_user, mail_pass)
    server.sendmail(mail_user, to_list, msg.as_string())
    server.close()


def main():
    send_mail(['cutesinapis@gmail.com'], "测试", "这是一个python脚本测试，请勿回复")


if __name__ == '__main__':
    main()
