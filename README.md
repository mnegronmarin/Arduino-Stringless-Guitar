# 🎸 Arduino Stringless Guitar
Welcome to the Arduino Stringless Guitar, a fun little project which can turn anyone into a musical genius. By strumming your finger to the 6th string of the guitar (E chord), any note from F to E can be played.

# Pictures
![IMG_5189](https://github.com/user-attachments/assets/93107da9-ad19-4963-b47c-17b8ddd1c6f5)
![IMG_5181](https://github.com/user-attachments/assets/7567666e-c596-44ae-9d4f-326f34ecc97b)

# Video
##With finger apparatus


https://github.com/user-attachments/assets/700227fa-5c4d-43d1-82ca-908047517a3f


The reason behing using the finger apparatus is to increase the surface area of the object that the distance sensor must read. This decreases the small errors from the distance sensor. 

##Without finger apparatus


https://github.com/user-attachments/assets/22cb3e33-60cb-4d9a-9313-d9d945a59214



# How it Works
The distance sensor reads the distance to the user's finger, and depending on that distance, the arduino calculates which note should be played (it follows the same structure as the guitar's 6th string E). It showcases the note being played on the OLED screen and plays the note to the passive buzzer, combining technology and music in a fun and interactive way!

# What I used
* ELEGOO Uno R3 (Arduino Uno R3 clone)
* VL53L0X Distance Sensor (To measure your finger's position)
* OLED I2C 128x64 Screen (To display the note and distance)
* Passive Buzzer (To play the notes 🎵)
* Breadboard and a lot of wires
* And many household items to put it all together such as cardboard, tape, and even a sock.

# Issues I ran Into

## RAM Memory
Initially, when I connected both the OLED screen and the distance sensor to the same breadboard, the program failed to run. However, testing each component individually revealed no issues. After some troubleshooting and researching, I discovered through a post on Arduino's help forum that the problem stemmed from the Arduino's limited RAM, which was being almost entirely consumed by the OLED screen.

To resolve this, I focused on optimizing the code. I implemented a solution to load only 32 vertical pixels of the screen instead of the standard 64. This adjustment significantly reduced memory usage and allowed the program to run smoothly.

<img width="189" alt="image" src="https://github.com/user-attachments/assets/42fc94f3-ad04-415e-aab3-0ef5aaca936a" />

## Compacting the Device
Since I wanted the device to be comfortable enough to fit on top of one's hand and play the arm as the instrument, I had to find a way to compact it. This was the most challenging part of the proyect. 

I originally thought it would be a good idea to craft a cardboard box and place the device inside it, but this resulted in many problems. The wires were frequently being pulled out while placing the lid and it was difficult to position the distance sensor and the OLED screen in a practical spot. Even worse, it the device was too big to fit on top of one's hand.

I eventually decided to embrace an open-circuit design, leaving the components exposed. While this left the wires and components unprotected, it made the circuitry much easier to work with and gave the device a unique look. To secure the instrument, I added a glove made from a sock which worked perfectly.

# Construction
<img width="571" alt="Screenshot 2024-12-24 160629" src="https://github.com/user-attachments/assets/46c3d35f-ed0a-4050-b371-51b8217652b3" />

While this image does not contain the exact OLED screen (OLED I2C 128x64) and distance sensor (VL53L0X) I used in the device, it showcases a similar circuit to the one built. The connections and layout are representative of the actual setup so you may use this as reference. Note that depending onn the specific components you use, pin configurations and wiring may vary. 

For example, my VL53L0X distance sensor had SCL and SDA pins which had to be connected to A5 and A4, respectively. Hence, in my breadboard I made a joined connection for those pins for both the OLED screen and the distance sensor. 

# Credits
* https://forum.arduino.cc/t/arduino-uno-ssd1306-allocation-failed-need-help-downsizing/1131175/6
