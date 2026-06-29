# PetroChat-ESP8266-ESP32

**<u>A PRIVATE CHATTING APP IN YOUR HAND MADE BY YOU</u>**

**Parts List**

1. ESP8266 or ESP32 based development board (like Nodemcu 12-E, ESP32 WROOM, etc.).
2. A mobile phone.

**How to set up your board?**

Download the Arduino ide on your device. Add the esp8266 board into the arduino by pasting this url into the preferences option:- http://arduino.esp8266.com/stable/package_esp8266com_index.json . Add the required libraries of the code and you are good to go!

<img width="722" height="607" alt="image" src="https://github.com/user-attachments/assets/12c9e402-0867-4992-8bd1-f8312049e8a8" />

**What is this code about and how to use it?**

This code turns any esp8266 or esp32 based development board into a global chat app, but with some limitations. The first is that you cant see the whole message list, only one message at a time; Second you have to connect to its AP, because it feels laggy and is unreliable in station mode. But it is okay for a begginer (like me) to give it a try.
If this code has some errors, then please ignore them because it is my first code which i have written by myself without any internet help. By the way, this code is open-source so that you can modify this by yourself(if you want to do so).

To use this:-

1. Upload this code on the board.
  
2. Download the app in you device.
<img width="1770" height="863" alt="Screenshot 2026-06-29 150936" src="https://github.com/user-attachments/assets/67afcc61-6afd-4e03-a4fe-35125f04944c" />

3. Connect to the AP (PetroChat, password = petrog75).

4. Open the app and fill credentials like in this image (name and message can be changed to whatever you like):-
<img width="1766" height="777" alt="Screenshot 2026-06-29 151014" src="https://github.com/user-attachments/assets/4a5d44c3-c9f5-42cf-8e34-65bd91e77439" />

5.You can set the time taken between each receive message request to automatically request the server to send the messages to client by turning on this switch:- 

<img width="195" height="80" alt="Screenshot 2026-06-29 151836" src="https://github.com/user-attachments/assets/5b4d76ce-383f-4a02-82b9-7321c4a78738" />



**Emojis can also be sent.**

**<u>NOTE: The personal message section is in development and have some errors, but you can check out the global message section.</u>**

<u>Thanks for you attention.</u>
