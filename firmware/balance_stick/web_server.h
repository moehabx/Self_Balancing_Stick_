#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <WebServer.h>

extern WebServer server;
extern float Kp, Ki, Kd, keepAngle;

const char HTML_PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Balance Stick PID Tuning</title>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; margin-top: 30px; background: #121212; color: #fff; }
    .card { background: #1e1e1e; padding: 20px; display: inline-block; border-radius: 10px; width: 300px; }
    input { width: 80%; padding: 8px; margin: 8px 0; border-radius: 5px; border: none; }
    button { padding: 10px 20px; background: #007bff; color: white; border: none; border-radius: 5px; cursor: pointer; }
    button:hover { background: #0056b3; }
  </style>
</head>
<body>
  <div class="card">
    <h2>PID Tuning Panel</h2>
    <form action="/set" method="GET">
      <label>Kp:</label><br><input type="text" name="kp" value="15.0"><br>
      <label>Ki:</label><br><input type="text" name="ki" value="0.05"><br>
      <label>Kd:</label><br><input type="text" name="kd" value="15.20"><br>
      <button type="submit">Update Parameters</button>
    </form>
  </div>
</body>
</html>
)rawliteral";

void setupWebServer() {
  server.on("/", []() {
    server.send(200, "text/html", HTML_PAGE);
  });

  server.on("/set", []() {
    if (server.hasArg("kp")) Kp = server.arg("kp").toFloat();
    if (server.hasArg("ki")) Ki = server.arg("ki").toFloat();
    if (server.hasArg("kd")) Kd = server.arg("kd").toFloat();
    server.send(200, "text/html", "<h3>Parameters Updated! <a href='/'>Back</a></h3>");
  });

  server.begin();
}

#endif