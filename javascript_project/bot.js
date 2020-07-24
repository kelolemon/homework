const Promise = require('bluebird');
Promise.config({
    cancellation: true
});

const send_mail = () => {
    const users = ['una', 'kelo'];
    const to_mail = ['std.kelo.deng@gmail.com', 'std.una.shi@gmail.com', 'kelo@cetacis.dev', 'una@cetacis.dev'];
    const task_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'task.json'));
    for (let i = 0; i < 2; i++) {
        const user = users[i];
        let html_text = "";
        html_text += "<strong>This is your task list</strong><br>";
        html_text += '<table border="1" cellpadding="3" cellspacing="0" style="width: 60%;margin:auto"> <tr> <th> TaskId </th> <th> TaskContent </th> <th> IsComplete </th> </tr>';
        const tot = task_json[user]['tot'];
        let complete = 0;
        for (let id = 0; id < tot; id++) {
            html_text += '<tr> <td align="center"> ' + (id + 1) + '</td> <td align="center"> ' + task_json[user]['list']['content'][id] + '</td> <td align="center"> ' + task_json[user]['list']['complete'][id] + '</td> </tr>'; 
            if (task_json[user]['list']['complete'][id] === 1) {
                complete += 1;
            }
        }
        html_text += "</table>";
        html_text += "<br> Today you have " + (tot) + " tasks. and you have finished " + (complete) + " tasks. Which is";
        html_text += "<strong> " + complete + "/" + tot + " " + ((complete / tot) * 100) + "% </strong> <br>";
        fs.writeFileSync(__dirname + '/' + 'html.text' + user, html_text, (err => {
            if (err) {
                return console.log(err);
            }
            console.log('success!');
        }));
        exec('go run main.go ' + user, (err, stdout, stderr) => {
            if(err) {
                console.log(err);
                return;
            }
            console.log(`stdout: ${stdout}`);
            console.log(`stderr: ${stderr}`);
        })
    }
};

// define 
const {exec} = require('child_process');
const crypto = require('crypto');
const fs = require('fs');
const TelegramBot = require('node-telegram-bot-api');
const Agent = require('socks5-https-client/lib/Agent');
const url = "https://bot.cetacis.dev";
const port = 9000;
const data_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'config.json', 'utf-8'));
const token = data_json['token'];
const bodyParser = require('body-parser');
const bot = new TelegramBot(token);
const get_time = require('silly-datetime');
// control time sleep 
function sleep(delay) {
    return new Promise(reslove => {
      setTimeout(reslove, delay)
    })
}

// set web hook and define express
bot.setWebHook(`${url}/bot${token}`);
const express = require('express');
const { stderr } = require('process');
const app = express();
app.use(bodyParser.json());

// express router
app.get('/', (req, res) => res.send('Hello World!'));

app.post(`/bot${token}`, (req, res) => {
    bot.processUpdate(req.body);
    res.sendStatus(200);
});

app.listen(port, () => {
    console.log(`Express server is listening on ${port}`);
});

// bot command
bot.onText(/\/start/, (msg) => {
    bot.sendMessage(msg.chat.id, "Welcome...");
});

bot.onText(/\/prpr/, (msg) => {
    bot.sendMessage(msg.chat.id, "🐳pupupu");
});

bot.onText(/\/time/, (msg) => {
    myDate = new Date()
    bot.sendMessage(msg.chat.id, myDate.toLocaleString());
});

bot.onText(/\/encode64 (.+)/, (msg, match) => {
    let data = match[1];
    let buff = new Buffer.from(data)
    bot.sendMessage(msg.chat.id, buff.toString("base64"));
});

bot.onText(/\/decode64 (.+)/, (msg, match) => {
    let data = match[1];
    let buff = new Buffer.from(data, 'base64');
    bot.sendMessage(msg.chat.id, buff.toString());
});

bot.onText(/\/md5 (.+)/, (msg, match) => {
    let data = match[1];
    let md5encode = crypto.createHash('md5');
    bot.sendMessage(msg.chat.id, md5encode.update(data).digest("hex").toString());
});

bot.onText(/[.]*\u9093\u840c\u8fbe[.]*/, (msg, mathch) => {
    bot.sendMessage(msg.chat.id, "\u9093\u840c\u8fbe\u559c\u6b22\u53f2\u745e\u742a\u545c\u545c\u545c")
    bot.sendPhoto(msg.chat.id, photo = 'https://img.cetacis.dev/uploads/big/7e4db5e616c46b25826ead01f2963797.jpg')
});

bot.onText(/\/add_task[ ](una|kelo)[ ](.+)/, (msg, match) => {
    const new_task = match[2];
    const task_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'task.json'));
    if (match[1] === 'una') {
        var current_task = task_json['una']['tot'];
        current_task = current_task + 1;
        task_json['una']['tot'] = current_task;
        task_json['una']['list']['content'].push(new_task);
        task_json['una']['list']['complete'].push(0);
    } else {
        var current_task = task_json['kelo']['tot'];
        current_task = current_task + 1;
        task_json['kelo']['tot'] = current_task;
        task_json['kelo']['list']['content'].push(new_task);
        task_json['kelo']['list']['complete'].push(0);
    }
    str_task = JSON.stringify(task_json);
    fs.writeFile(__dirname + '/' + 'task.json', str_task, (err => {
        if (err) {
            return console.log(err);
        }
        console.log('success!');
    }));
    bot.sendMessage(msg.chat.id, "new task:" + new_task + " has been added");
});

bot.onText(/\/check/, (msg, match) => {
    let send_msg = "";
    send_msg += '*kelo Task*\n';
    const task_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'task.json'));
    let tot = task_json['kelo']['tot'];
    let task_list = task_json['kelo']['list']['content'];
    send_msg += "----------------\n";
    for (let i = 0; i < tot; i++) {
        if (task_json['kelo']['list']['complete'][i] === 0) {
            send_msg += '`' +(i + 1) + ' | ' + task_list[i] + '`\n';
        } else {
            send_msg += '`' +(i + 1) + ' | ' + task_list[i] + ' (completed)`\n';
        }
    }
    send_msg += '*una Task*\n';
    tot = task_json['una']['tot'];
    task_list = task_json['una']['list']['content'];
    send_msg += "----------------\n";
    for (let i = 0; i < tot; i++) {
        if (task_json['una']['list']['complete'][i] === 0) {
            send_msg += '`' +(i + 1) + ' | ' + task_list[i] + '`\n';
        } else {
            send_msg += '`' +(i + 1) + ' | ' + task_list[i] + ' (completed)`\n';
        }
    }
    bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'markdown'});
});

bot.onText(/\/complete[ ](una|kelo)[ ]([0-9]*)/, (msg, mathch) => {
    const task_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'task.json'));
    let send_msg = "";
    const user = mathch[1];
    const id = mathch[2];
    if (user === "kelo") {
        if (parseInt(id) > parseInt(task_json['kelo']['tot'])) {
            send_msg = 'wrong id. plz check.';
            bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'Markdown'});
        } else {
            task_json['kelo']['list']['complete'][id - 1] = 1;
            str_task = JSON.stringify(task_json);
            fs.writeFile(__dirname + '/' + 'task.json', str_task, (err => {
                if (err) {
                    return console.log(err);
                }
                console.log('success!');
            }));
            send_msg += '*kelo Task*\n';
            const tot = task_json['kelo']['tot'];
            const task_list = task_json['kelo']['list']['content'];
            send_msg += "----------------\n";
            for (let i = 0; i < tot; i++) {
                if (task_json['kelo']['list']['complete'][i] === 0) {
                    send_msg += '`' +(i + 1) + ' | ' + task_list[i] + '`\n';
                } else {
                    send_msg += '`' +(i + 1) + ' | ' + task_list[i] + ' (completed)`\n';
                }
            }
            bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'Markdown'});
        }
    } else {
        if (parseInt(id) > parseInt(task_json['una']['tot'])) {
            send_msg = 'wrong id. plz check.';
            bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'Markdown'});
        } else {
            task_json['una']['list']['complete'][id - 1] = 1;
            str_task = JSON.stringify(task_json);
            fs.writeFile(__dirname + '/' + 'task.json', str_task, (err => {
                if (err) {
                    return console.log(err);
                }
                console.log('success!');
            }));
            send_msg += '*una Task*\n';
            const tot = task_json['una']['tot'];
            const task_list = task_json['una']['list']['content'];
            send_msg += "----------------\n";
            for (let i = 0; i < tot; i++) {
                if (task_json['una']['list']['complete'][i] === 0) {
                    send_msg += '`' +(i + 1) + ' | ' + task_list[i] + '`\n';
                } else {
                    send_msg += '`' +(i + 1) + ' | ' + task_list[i] + ' (completed)`\n';
                }
            }
            bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'Markdown'});
        }
    }
});

bot.onText(/\/delete[ ](una|kelo)[ ]([0-9]*)/, (msg, mathch) => {
    const task_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'task.json'));
    let send_msg = "";
    const user = mathch[1];
    const id = mathch[2];
    if (user === "kelo") {
        if (parseInt(id) > parseInt(task_json['kelo']['tot'])) {
            send_msg = 'wrong id. plz check.';
            bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'Markdown'});
        } else {
            task_json['kelo']['list']['content'].splice(parseInt(id - 1), 1);
            task_json['kelo']['list']['complete'].splice(parseInt(id - 1), 1);
            task_json['kelo']['tot'] -= 1;
            str_task = JSON.stringify(task_json);
            fs.writeFile(__dirname + '/' + 'task.json', str_task, (err => {
                if (err) {
                    return console.log(err);
                }
                console.log('success!');
            }));
            send_msg += '*kelo Task*\n';
            const tot = task_json['kelo']['tot'];
            const task_list = task_json['kelo']['list']['content'];
            send_msg += "----------------\n";
            for (let i = 0; i < tot; i++) {
                if (task_json['kelo']['list']['complete'][i] === 0) {
                    send_msg += '`' +(i + 1) + ' | ' + task_list[i] + '`\n';
                } else {
                    send_msg += '`' +(i + 1) + ' | ' + task_list[i] + ' (completed)`\n';
                }
            }
            bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'Markdown'});
        }
    } else {
        if (parseInt(id) > parseInt(task_json['una']['tot'])) {
            send_msg = 'wrong id. plz check.';
            bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'Markdown'});
        } else {
            task_json['una']['list']['content'].splice(parseInt(id - 1), 1);
            task_json['una']['list']['complete'].splice(parseInt(id - 1), 1);
            task_json['una']['tot'] -= 1;
            str_task = JSON.stringify(task_json);
            fs.writeFile(__dirname + '/' + 'task.json', str_task, (err => {
                if (err) {
                    return console.log(err);
                }
                console.log('success!');
            }));
            send_msg += '*una Task*\n';
            const tot = task_json['una']['tot'];
            const task_list = task_json['una']['list']['content'];
            send_msg += "----------------\n";
            for (let i = 0; i < tot; i++) {
                if (task_json['una']['list']['complete'][i] === 0) {
                    send_msg += '`' +(i + 1) + ' | ' + task_list[i] + '`\n';
                } else {
                    send_msg += '`' +(i + 1) + ' | ' + task_list[i] + ' (completed)`\n';
                }
            }
            bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'Markdown'});
        }
    }
});

bot.onText(/\/gay/, (msg, mathch) => {
    bot.sendMessage(msg.chat.id, "\u9093\u840c\u8fbe\u559c\u6b22\u53f2\u745e\u742a\u545c\u545c\u545c");
    bot.sendPhoto(msg.chat.id, photo = 'https://img.cetacis.dev/uploads/big/7e4db5e616c46b25826ead01f2963797.jpg');
});

bot.onText(/\/clear_list/, (msg, mathch) => {
    send_mail();
    const task_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'task.json'));
    task_json['una']['tot'] = 0;
    task_json['una']['list']['complete'] = [];
    task_json['una']['list']['content'] = [];
    task_json['kelo']['tot'] = 0;
    task_json['kelo']['list']['complete'] = [];
    task_json['kelo']['list']['content'] = [];
    const str_task = JSON.stringify(task_json);
    fs.writeFile(__dirname + '/' + 'task.json', str_task, (err => {
        if (err) {
            return console.log(err);
        }
        console.log('success!');
    }));
    bot.sendMessage(msg.chat.id, "Today's task is been cleared and conclusion is sent by email.");
});

bot.onText(/\/add_conclusion[ ](una|kelo)[ ](.+)/, (msg, mathch) => {
    const conclusion_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'conclusion.json'));
    const time = get_time.format(new Date(), 'YYYY-MM-DD');
    const user = mathch[1];
    const content = mathch[2];
    conclusion_json[user]['date'].push(time);
    conclusion_json[user]['conclusion'].push(content);
    const str_json = JSON.stringify(conclusion_json);
    fs.writeFile(__dirname + '/' + 'conclusion.json', str_json, (err => {
        if (err) {
            return console.log(err);
        }
        console.log('success!');
    }));
    bot.sendMessage(msg.chat.id, "Conclusion add successfully!");
});

bot.onText(/\/conclusion/, (msg, match) => {
    let send_msg = "";
    const task_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'conclusion.json'));
    send_msg += '*kelo Conlusion*\n';
    let tot = task_json['kelo']['date'].length;
    send_msg += "----------------\n";
    for (let i = 0; i < tot; i++) {
        send_msg += "*" + task_json['kelo']['date'][i] + "*\n";
        send_msg += "`" + task_json['kelo']['conclusion'][i] + "`\n";
    }
    send_msg += '*una Conlusion*\n';
    tot = task_json['una']['date'].length;
    send_msg += "----------------\n";
    for (let i = 0; i < tot; i++) {
        send_msg += "*" + task_json['una']['date'][i] + "*\n";
        send_msg += "`" + task_json['una']['conclusion'][i] + "`\n";
    }
    bot.sendMessage(msg.chat.id, send_msg, {parse_mode: 'markdown'});
});

bot.onText(/\/send_email/, (msg, mathch) => {
    send_mail();
    bot.sendMessage(msg.chat.id, "check info is sent. Please check your email.");
});

bot.onText(/\/fork/, (msg, mathch) => {
    const task_json = JSON.parse(fs.readFileSync(__dirname + '/' + 'task.json'));
    task_json['kelo']['tot'] = task_json['una']['tot'];
    task_json['kelo']['list'] = task_json['una']['list'];
    str_json = JSON.stringify(task_json);
    fs.writeFile(__dirname + '/' + 'task.json', str_json, (err => {
        if (err) {
            return console.log(err);
        }
        console.log('success!');
    }));
    bot.sendMessage(msg.chat.id, "Lazy kelo forked una's task!");
});

