var express = require('express');
var app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);

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

app.get('/', (req, res) => {
  res.send("Server is running!!");
});

io.on('connection', (socket) => {
  socket.on('add-message', (message) => {
    io.emit('prev-message', message);
  });
});

var server = http.listen(3000, () => {
  console.log("Server listening on port " + server.address().port);
});
