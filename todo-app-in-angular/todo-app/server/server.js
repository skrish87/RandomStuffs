const express = require('express');
const routes = require('./routes');
const app = express();
const http = require('http').Server(app);

app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', '*');
  res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
  res.header('Access-Control-Allow-Methods', 'OPTIONS, GET, POST, PUT, DELETE');
  if ('OPTIONS' == req.method) {
    res.sendStatus(200);
  } else {
    console.log(`${req.ip}, ${req.method}, ${req.url}`);
    next();
  }
});

app.use(express.static(__dirname));
app.use(express.json());
app.use('/', routes);

var server = http.listen(3000, () => {
  console.log("Server listening on port " + server.address().port);
});
