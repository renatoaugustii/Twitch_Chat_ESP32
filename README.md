# Twitch_Chat_ESP32
Using twitch chat to Turn ON or OFF LEDs.

Step By Step

## ON SERVER

- ### Installing 

First it's necessay installing Node.js from oficial website: [Node.Js](https://nodejs.org/en/) and then verify the Node and npm version.

```bash
node -v 
```
```bash
npm -v 
```

- ### Create Folder
Select a folder to create a server and ESP32 files.

```bash
mkdir my_twitch_bot
```
Inside bot folder use the code:
```bash
npm init
```
- ### Create JavaScript Server

Create a JavaScript file to server.

Example:   <b>server.js </b>

- ### Installing tmi.js
On website [tmi.js](https://tmijs.com/) look how to install the API. 
```bash
npm i tmi.js
```

- ### Installing Request
Its necessary to request URL and send message to ESP32.
```bash
npm install request
```
- ### Installing dotenv
It's necessary to hide the user and passwords.
```bash
npm install dotenv
```
- ### User and Keyword
Open the <b>example.env</b> and put your credencial to use API authenticator. Remove the example and let only .env if you made all good, you can test on chat now.

---
### Version Tested
The software was tested  using the version below:    
<b>Node:</b> 16.13.0  
<b>npm:</b> 8.1.1  
<b>tmi.js</b> 1.8.5  
<b>dotenv:</b> 10.0.0  
<b>request</b> 2.88.2  

---

## ON ESP32

Installing Wifi.h 
```bash
WiFi.h
```
The example is using three outputs LEDS, change the code to your desire;