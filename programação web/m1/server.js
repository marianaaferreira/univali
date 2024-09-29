const express = require('express');
const bodyParser = require('body-parser'); //for post submits
const urlencodedParser = bodyParser.urlencoded({ extended: false }) // POST: create application/x-www-form-urlencoded parser
const app = express();
app.listen();

app.get("/", function(request, response){
response.send("Your node.js backend is working!!");
});

app.post("/restrito.html",urlencodedParser, function (request, response) {
let nome = request.body.nome;
response.send({method:"POST",nome});
});
