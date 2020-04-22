const express = require('express');
const app = express.Router();
const bodyParser = require('body-parser');

module.exports = app;

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

todoArray = [];

app.post('/todo/add', (req, res) => {
  todoArray.push(req.body);
  res.send(todoArray);
});

app.get('/', (req, res) => {
  res.send(todoArray);
});

app.post('/todo/delete', (req, res) => {
  for (let i = 0; i < todoArray.length; i++) {
    if (req.body['todo'] != null && todoArray.length > 0) {
        if (req.body['todo'] === todoArray[i].todo) {
          todoArray.splice(i, 1);
        }
    }
  }
  res.send(todoArray);
});

