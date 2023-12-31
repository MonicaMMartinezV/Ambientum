#include <ESP8266WiFi.h>

const char* ssid = "Moni"; 
const char* password = "12345678";

int ledPin = 13; // GPI013 - D7 
WiFiServer server (80);

void setup() {
  Serial.begin(115200);
  delay(10);
  
  pinMode (ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW);
  
  // Wifi connecting
  Serial.println();
  Serial.println();
  Serial.print ("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay (500);
    Serial.print (".");
    }
  
  Serial.println("");
  Serial.println("WiFi connected");
    
//server starting
server.begin();
Serial.println("Server started");

// serial print

Serial.print("Use this URL to connect: ");

Serial.print("http://");

Serial.print (WiFi.localIP());

Serial.println("/");
}

void loop() {

WiFiClient client = server.available();

if (!client) {

return;

}

Serial.println("new client"); 
while (!client.available()) { 
  delay(1);
}
// reading strings 
String request = client.readStringUntil('\r'); 
Serial.println (request); 
client.flush();
int value = LOW;

if (request.indexOf("/LED-ON") != -1) { 
  digitalWrite(ledPin, HIGH); 
  value = HIGH;
}
if (request.indexOf ("/LED-OFF") != -1) {

digitalWrite(ledPin, LOW);
value = LOW;
}
// HTML to Internet

client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("");
client.println("<!DOCTYPE HTML>"); 
client.println("<html><br><br><br><br><br><br><br>");
client.print ("Led pin is now: ");

if (value == HIGH) {
  client.print("on");
} else {

client.print("off");
}

client.println("");
client.println("<a href=\"/LED-ON\"\"><button>led on </button></a>");
client.println("<a href=\"/LED-OFF\"\"><button>led off </button></a>"); 
client.println("</html>");
delay (1);
Serial.println("Client disonnected");
Serial.println("");

}