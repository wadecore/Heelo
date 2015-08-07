# Heelo
Heelo is an Arduino-based pan/tilt robot that uses a Pixy for color object tracking. Heelo is different from similar Pixy-based Pan/Tilt robots because he uses a continuous rotation servo for panning, and an onboard LiPo allowing him to endlessly turn in any direction, untethered by data and power cords. Eventually Heelo will also play games. 
This is my first real project, please be gentle.
![Heelo](http://wade.datablue.net/images/projects/robotics/heelo/Heelo.jpg)

# Parts
| Count | Component                                                   | 
| ----- | ----------------------------------------------------------- | 
|    1x | RobotGeek Geekduino                                         | 
|    1x | RobotGeek Sensor Shield                                     |
|    1x | PIXY CMU5 Cam                                               |
|    1x | RobotGeek RGS-13 180 Degree Servo (Tilt)                    | 
|    1x | RobotGeek RGS-4C Continuous Rotation Servo (Pan)            | 
|    1x | RobotGeek Buzzer (currently augmented with a small speaker) |
|    2x | RobotGeek Push Button                                       |
|    2x | RobotGeek LED Driver                                        |
|    1x | RobotGeek LiPo Harness                                      |
|    1x | 1300mah 7.4V LiPo Battery                                   |
|    1x | Adafruit NeoPixel                                           |
|    ?x | brackets, standoffs, and acrylic plates                     |

# Goals
I'd like to make Heelo interactive. This means making up games that take advantage of the PIXY's ability to track color, and using that data to give Heelo a set of actions that come across as personality. I want Heelo to play games with people, and people to play games with Heelo.

| Game | %Implemented | Description |
| ----- | ---------- | ------------------------- |
| Flash Cards | 0% | Heelo Changes mode upon seeing a flash card with the color code that corresponds to a game. |
| Yell at Blue | 100% | Heelo finds the first color you taught him and yells at it. |
| Simon Says | 0% | Heelo Blinks a color, You must find that color before the time runs out! |
| Red Light Green Light | 0% | You Hold a specific sized marker, letting Heelo know how far away you are. Heelo looks around while you try to get closer. If Heelo catches you moving, it's game over! If you get close enough to Heelo, you win! |
| Music | 0% | Show Heelo a list of colors. Heelo Translates the colors into a melody! |
| Guess the Color | 0% | Heelo thinks of a color. You get three guesses to show Heelo the correct color, or he'll be sad. |
| Hide and Seek | 0% | Heelo looks around the room to try to find your color tag. |
| Find Colors Demonstration | 0% | Show Heelo 3 colors. He will try to find them in the room! |
