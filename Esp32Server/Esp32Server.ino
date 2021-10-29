/*
  TWITCH CHAT CONNECTION USING tmi.JS API
   
   Author: Eng. Renato Augusto

  LIBRARIES 
      - WiFi.h 

   License - CC BY-NC

   **  VERSION CONTROLER **
   INICIAL VERSION
   Data: 28/10/2021
   Belo Horizonte - MG / Brasil 

   Feel free to change the code or make a Pull Request.
   
*/

#include <WiFi.h> //Include Wifi Lib
#include "secrets.h" // Include my secret user and wifi password

/* IO DEFINE */
#define R_LED 12 // Define pins on ESP32 to use 
#define Y_LED 13 // Define pins on ESP32 to use 
#define B_LED 2 // Define pins on ESP32 to use 

// UNCOMMENT CODE BELOW IF YOU WANT PUT YOUR USER AND KEY HERE
//const char* ssid     = "SSID"; //  Put here your SSID WiFi network
//const char* password = "WIFI PASSWORD"; // Put here your password WiFi network

//IF YOU ARE USING SECRETS.H KEEP THE CODE BELOW, IF NOT, COMMENT NEXT 2 LINES BELOW
char ssid[] = SECRET_SSID;   // Your network SSID (name) only if you are using secret.h
char password[] = SECRET_PASS;   // Your network password only if you are using secret.h

/* NET WORK CONFIGURATION*/
WiFiServer server(80); // Port used
IPAddress local_IP(192, 168, 0, 108);// Set your Static IP address
IPAddress gateway(192, 168, 0, 1); // Set your Gateway IP address
IPAddress subnet(255, 255, 0, 0); // Network Mask


void setup()
{
    // Start configuration 
    Serial.begin(115200);
    pinMode(Y_LED, OUTPUT);      // set the LED pin mode
    pinMode(R_LED, OUTPUT);      // set the LED pin mode
    pinMode(B_LED, OUTPUT);      // set the LED pin mode

    delay(10);

    // We start by connecting to a WiFi network
    // Configures static IP address
    if (!WiFi.config(local_IP, gateway, subnet)) { //Try to connect
    Serial.println("STA Failed to configure"); // If conncetion fail, print on Screen this message
    }

    // Print on Screen the informations about Network name
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password); //Inicialize the conection using user and pass
 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print("."); //Print dots on screen while wait the connection
    }

    Serial.println("");
    Serial.println("WiFi connected.");// Print on screen if the connection has been successful
    Serial.println("IP address: "); 
    Serial.println(WiFi.localIP()); // Print the IP used on screen
    server.begin(); // Inicialize the server

}

int value = 0;

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c); 
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }// print it out the serial monitor
        
        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /Y")) {
          digitalWrite(Y_LED, HIGH);               // GET /Y turns the LED on
        }
        if (currentLine.endsWith("GET /y")) {
          digitalWrite(Y_LED, LOW);                // GET /y turns the LED off
        }
        if (currentLine.endsWith("GET /R")) {
          digitalWrite(R_LED, HIGH);               // GET /R turns the LED on
        }
        if (currentLine.endsWith("GET /r")) {
          digitalWrite(R_LED, LOW);                // GET /r turns the LED off
        }
        if (currentLine.endsWith("GET /B")) {
          digitalWrite(B_LED, HIGH);               // GET /B turns the LED on
        }
        if (currentLine.endsWith("GET /b")) {
          digitalWrite(B_LED, LOW);                // GET /b turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}