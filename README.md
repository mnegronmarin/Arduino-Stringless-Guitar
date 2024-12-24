#🎸 Arduino Guitar String Simulator
Welcome to the Arduino Guitar String Simulator, a fun little project which can turn anyone into a musical genius! By strumming your finger to the 6th string og the guitar (E chord), any note from F to E can be played.

# Pictures
![IMG_5189](https://github.com/user-attachments/assets/93107da9-ad19-4963-b47c-17b8ddd1c6f5)
![IMG_5181](https://github.com/user-attachments/assets/7567666e-c596-44ae-9d4f-326f34ecc97b)

# Video


# What I used
* ELEGOO Uno R3 (Arduino Uno R3 clone) (The brains 🧠)
* VL53L0X Distance Sensor (To measure your finger's position 🎯)
* OLED I2C 128x64 Screen (To display the note and distance 📟)
* Passive Buzzer (To play the notes 🎵)
* Breadboard and a lot of wires
* And many household items to put it all together such as cardboard, tape, and even a sock.

# Issues and Workarounds

## RAM Memory
Initially, including the OLED screen and the distance sensor into the same breadboard, the program would not run. However, when I tested them individually, the components would work without any problem. After a while of searching for possible solutions, I found out through a post in Arduino's help website that the disfunctionality was due to the Arduino's small RAM memory being taken up mostly by the OLED screen. 
To fix it I had to find a way to make the code more efficient, and came up with the idea to load in 32 vertical pixels of the screen instead of the traditional 64, which worked perfectly. 
<img width="189" alt="image" src="https://github.com/user-attachments/assets/42fc94f3-ad04-415e-aab3-0ef5aaca936a" />

## Compacting the Device
Since I wanted the device to be comfortable enough to fit on top of one's hand and play the arm as the instrument, I had to find a way to compact it. This was the most challenging part. 
I originally thought it would be a good idea to craft a cardboard box and place the device inside it, but this resulted in many wires being pulled out while placing the lid and difficulty in placing the distance sensor and the screen in a reasonable spot. Even worse, it the device was too big to fit on top of one's hand.
Then I decided to make the device's circuitry exposed. Even though it may not protect the wires and components, this exposure would make it easier for me to work with the circuitry and it would also result in a much cooler looking device instrument. 
I also added a glove made from a sock to hold the instument in place.

# Construction
<img width="571" alt="Screenshot 2024-12-24 160629" src="https://github.com/user-attachments/assets/46c3d35f-ed0a-4050-b371-51b8217652b3" />
While this image does not contain the exact OLED screen and distance sensor I used in the device, it showcases a similar circuit to the one built.

# Credits
* https://forum.arduino.cc/t/arduino-uno-ssd1306-allocation-failed-need-help-downsizing/1131175/6
