# 🤖 Line Following Robot using Arduino
This project is on a 2-wheeled line following robot following a black line on a white background using an Arduino Uno as the Micro controller and IR Sensors as mediums for checking the status of the robot
## 📸 Project Preview
[![Robot Image](https://github.com/shubhambaxi1-code/line-follower-robot/blob/main/Robot%20Closeup)](https://www.youtube.com/watch?v=MyOQUESpWe8)


You can watch the demo and explanation on [my channel](https://www.youtube.com/@SBBuildsStuff). For the video, click [here](https://www.youtube.com/watch?v=MyOQUESpWe8)
## 🧰 Components Used
These are the [List of Materials](https://github.com/shubhambaxi1-code/line-follower-robot/blob/main/List%20of%20materials%20used.xlsx) used to build this robot:
|Product|Quantity|
|---|---|
|Male to Male Jumper Wires|N/A|
|Male to Female Jumper Wires|N/A|
|Female to Female Jumper Wires|N/A|
|Arduino Uno R3|1|
|Dual Battery Holder (Li-on)|1|
|Rechargable Lithium-Ion Batteries|2|
|L298N 2 Wheel Motor Driver|1|
|2-Wheel Drive Kit|1|
|Black Tape|1|

All of these materials are available on [Robocraze](https://robocraze.com/) and [Amazon](https://www.amazon.in/)

## 🔌 Circuit / Wiring
### Circuit Diagram
![Circuit Diagram](https://github.com/shubhambaxi1-code/line-follower-robot/blob/main/diagram.png)
### Pin Connections
|Component|Connection|
|---|---|
|Left IR VCC/IN|5V|
|Left IR GND|GND|
|Left IR OUT|D12|
|Right IR VCC/IN|5V|
|Right IR GND|GND|
|Right IR OUT|D11|
|L298N ENA|D6|
|L298N IN1|D7|
|L298N IN2|D8|
|L298N IN3|D9|
|L298N IN4|D10|
|L298N ENB|D5|
|Battey Holder +ve|L298N +12V|
|Battey Holder -ve|L298N GND|
|L298N 5V|Uno 5V|
|Uno GND|L298N GND|
|L298N OUT1|Right Motor Terminal|
|L298N OUT2|Right Motor Terminal|
|L298N OUT3|Left Motor Terminal|
|L298N OUT4|Left Motor Terminal|


## 🧠 How It Works

The Arduino Uno keeps checking the IR sensors. Based on these inputs, it drives the robot
|Left IR|Right IR|Movement|
|---|---|---|
|White|White|Forward|
|Black|Black|Stop|
|Black|White|Turn LEFT|
|white|Black|Turn RIGHT

## 🐛 Problems Faced & Solutions
Below are the problems faced by me and the solution to them
|Problem|Solution|
|---|---|
|Robot ignoring IR input|Make sure wires are connected properly|
|Code not compiling|Make sure the Uno is connected|
|IR sensors not responding on black lines|Increase or decrease sensitivity of IR sensors|
|Both wheels moving at different pace|Manually adjust the code to make the robot move straight|
|Batteries not delivering power|Make sure that it is manufactured properly|
|Castor wheel not moving freely|Keep IR senors away from Castor wheel to avoid collision|
|Wheels keep falling off|Do not fiddle with wheels and make sure they are firmly held in place with gentle force|
|Robot keeps running off track|Lower speed of robot and check IR sensors|
|Robot not moving fast enough despite code putting 180+ speed|Recharge the Batteries|
|Robot stops in the middle of track|Make sure both IR sensors work and IR sensors are not directed directly on the line in a 90 degree angle|
|Robot's wheel moving in opposite direction|Make sure that the polarity of the motors is correct by switching the wires from e.g OUT1 to OUT2 and OUT2 to OUT1|


## 📚 What I Learned

I learned to

- Use L289N Motor Driver Sheild
- Use Motors
- Build a Chassis
- Solder

## 🔮 Future Improvements

Later on in the future, I can:
- Add PID control
- Make the robot 4 wheeled
- Combine line following abilities with object avoidance
- Use an array of IR sensors
- Try colour sensors
- Add 3D printed mounts
- Source Better Materials

## 🙏 Credits / Inspiration
I'd like to thank [hash include electronics](https://www.youtube.com/@hashincludeelectronics) for his video [Line Follower Robot using Arduino🔥](https://www.youtube.com/watch?v=5jh-5HGvC-I&t=197s), from which this project was inspired and built upon
