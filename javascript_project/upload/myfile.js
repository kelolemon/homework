const express = require('express');
const app = express();
const fs = require('fs');
const path = require('path');
const ecstatic = require('ecstatic');

const bodyParser = require('body-parser');
const upload = require('multer')({
        dest: __dirname + '/myfile'
    }
);

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));


app.use(ecstatic({
    root: `${__dirname}/myfile`,
    showdir: true,
}));


app.get('/download', (req, res) => {
    res.sendFile(__dirname + "/" + "download.html");
});

app.get('/upload', (req, res) => {
    res.sendFile(__dirname + "/" + "upload.html");
});

app.post('/upload', upload.any(), (req, res) => {
    const pin = req.body.password;
    let pass = fs.readFileSync(__dirname + "/" + "pin.psw", 'utf-8');
    pass = pass.replace(/[\n]/g,"");
    if (pin === pass) {
        let myDate = new Date();
        myDate.toLocaleString();
        console.log(req.files[0]);
        const old_path = path.normalize(req.files[0].path);
        const new_path = __dirname + '/myfile/' + myDate + "---" + req.files[0].originalname;
        console.log(old_path);
        console.log(new_path);
        fs.rename(old_path, new_path, err => {
            if (err) {
                console.log(err);
            }
        });
        res.redirect('/');
    } else {
        console.log(req.files[0]);
        fs.unlink(path.normalize(req.files[0].path), err => {
            if (err) {
                console.log(err);
            }
        });
        res.send('permission denied');
    }
});

const regular = /[.]+[.]+/;

app.get('/delete', (req, res) => {
    res.sendFile(__dirname + "/" + "delete.html");
});

app.post('/delete', (req, res) => {
    const path = req.body.file;
    const pin = req.body.password;
    let pass = fs.readFileSync(__dirname + "/" + "pin.psw", 'utf-8');
    pass = pass.replace(/[\n]/g,"");
    if (pin === pass) {
        if (regular.test(path) === true) {
            res.send('path error');
        } else {
            const real_path = __dirname + '/myfile/' + path;
            fs.exists(real_path, exists => {
                exists ? fs.unlink(real_path, err => {
                    if (err) {
                        console.log(err);
                        res.redirect('/delete');
                        return;
                    }
                    res.redirect('/');
                }) : res.send('file not exist');
            });
        }
    } else {
        res.send('permission denied!');
    }
});

app.post('/download', (req, res) => {
    const {exec} = require('child_process');
    const name = req.body.name;
    const path = req.body.file;
    const pin = req.body.password;
    let pass = fs.readFileSync(__dirname + "/" + "pin.psw", 'utf-8');
    pass = pass.replace(/[\n]/g,"");
    console.log(pin);
    console.log(pass);
    if (pin === pass) {
        const command_download = 'wget ' + path + ' -O ' + __dirname + "/myfile/" + name;
        exec(command_download, (err, stdout, stderr) => {
            if (err) {
                console.log(err);
                res.redirect('/download');
                return;
            }
            console.log(stdout);
            console.log(stderr);
            res.redirect('/');
        });
    } else {
        res.send('permission denied!');
    }
});

const server = app.listen(15421, () => {
    const host = server.address().address;
    const port = server.address().port;
    console.log("http://%s:%s", host, port);
});