const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

let latestTemperature = null; // store the latest temperature

// Middleware to parse JSON data
app.use(bodyParser.json());

// POST /temperature – receive data from Arduino
app.post('/temperature', (req, res) => {
  const temperature = req.body.temperature;

  if (temperature !== undefined) {
    latestTemperature = temperature;
    console.log(`Received temperature: ${temperature}°C`);
    res.status(200).send({ message: 'Temperature data received' });
  } else {
    res.status(400).send({ message: 'No temperature data received' });
  }
});

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