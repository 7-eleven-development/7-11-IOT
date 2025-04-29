const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 3001;

let latestTemperature = null; // store the latest temperature

// Middleware to parse JSON data
app.use(bodyParser.json());

// POST /temperature – receive data from Arduino


// GET / – show latest temperature in a basic HTML page
app.get('/', (req, res) => {
  if (latestTemperature !== null) {
    res.send(`
      <html>
        <head>
          <title>Temperature Dashboard</title>
          <meta http-equiv="refresh" content="5">
        </head>
        <body style="font-family: sans-serif; text-align: center; margin-top: 40px;">
          <h1>🌡️ Latest Temperature</h1>
          <p style="font-size: 2em;">${latestTemperature}°C</p>
          <p>(This page refreshes every 5 seconds)</p>
        </body>
      </html>
    `);
  } else {
    res.send(`
      <html>
        <head>
          <title>Temperature Dashboard</title>
        </head>
        <body style="font-family: sans-serif; text-align: center; margin-top: 40px;">
          <h1>No temperature data received yet.</h1>
        </body>
      </html>
    `);
  }
});

app.listen(port, () => {
  console.log(`✅ Backend listening at http://localhost:${port}`);
});