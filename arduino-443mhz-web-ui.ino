#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <RCSwitch.h>

const char* ssid = "433";
const char* password = "";
const int receiverPin = D2; // D2 pin on NodeMCU

ESP8266WebServer server(80);
RCSwitch mySwitch = RCSwitch();

String messageLog;

void handleRoot() {
  String html = "<html><head><title>433MHz Receiver Log</title>";
  html += "<style>body{font-family: Arial, sans-serif;} pre {white-space: pre-wrap;}</style><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head><body>";
  html += "<h1>433MHz Receiver Log</h1><hr>";
  html += "<pre>" + messageLog + "</pre>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  // Configure 433MHz receiver
  mySwitch.enableReceive(receiverPin);

  // Connect to Wi-Fi
  WiFi.softAP(ssid, password);
  IPAddress ip = WiFi.softAPIP();
  Serial.print("Access Point IP address: ");
  Serial.println(ip);

  // Initialize web server routes
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();

  if (mySwitch.available()) {
    unsigned int value = mySwitch.getReceivedValue();
    int bitLength = mySwitch.getReceivedBitlength();
    int delay = mySwitch.getReceivedDelay();
    unsigned long rawdata = (unsigned long)mySwitch.getReceivedRawdata();
    int protocol = mySwitch.getReceivedProtocol();

    if (value != 0) {
      String binaryValue = String(value, BIN);
      String receivedMessage = "Received: " + String(value) + " (" + binaryValue + ")" +
                               " | Bit Length: " + String(bitLength) +
                               " | Delay: " + String(delay) + " | Raw Data: " + String(rawdata) +
                               " | Protocol: " + String(protocol);
      Serial.println(receivedMessage);
      messageLog += receivedMessage + "\n";
    }
    mySwitch.resetAvailable();
  }
}
