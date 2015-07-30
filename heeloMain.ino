
//INCLUDES
#include <SPI.h>
#include <Pixy.h>
#include <Servo.h>
//#include "pitches.h"

//DEFINES
#define PAN_SERVO 9
#define TILT_SERVO 10
#define BUZZER 3
#define LEFT_BUTTON 2
#define RIGHT_BUTTON 4
#define LEFT_LED 5
#define RIGHT_LED 6

//DEFINE NOTES
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//INTEGERS
int panServoSpeed = 90;
int tiltServoPos = 90;
int leftButton = LEFT_BUTTON;
int rightButton = RIGHT_BUTTON;
int leftLed = LEFT_LED;
int rightLed = RIGHT_LED;

int helody[] = {
  NOTE_C5, NOTE_B5, NOTE_B6};
int helodyNoteDurations[] = {
  16, 16, 16 };
int helodyPlayed = 0;

int byeFelicia[] = {
  NOTE_D2, NOTE_E1};
int byeFeliciaNoteDurations[] = {
  16, 16 };
int byeFeliciaPlayed = 0;

//BOOLEAN
boolean leftCurrentState = LOW;
boolean leftLastState = LOW;
boolean rightCurrentState = LOW;
boolean rightLastState = LOW;

//OBJECTS
Pixy pixy;
Servo panServo;
Servo tiltServo;

//SETUP
void setup()
{
  pixy.init();
  panServo.attach(PAN_SERVO);
  tiltServo.attach(TILT_SERVO);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(leftLed, OUTPUT);
  pinMode(rightLed, OUTPUT);
}

//LOOP
void loop()
{
  //READ LEFT BUTTON
  leftCurrentState = digitalRead(leftButton);
  if (leftCurrentState == HIGH && leftLastState == LOW)
  {
    
    while (leftCurrentState == HIGH)
    {
      track();
    }
  }
  delay(2);
  leftLastState = leftCurrentState;
  
    //READ RIGHT BUTTON
  rightCurrentState = digitalRead(rightButton);
  if (rightCurrentState == HIGH && rightLastState == LOW)
  {
    
    while (rightCurrentState == HIGH)
    {
      otherthing();
    }
  }
  delay(2);
  rightLastState = rightCurrentState;
}

//TRACK
void track()
{ 
  uint16_t blocks;
  blocks = pixy.getBlocks();
  if (blocks)
  {
    //TILT TOWARD FIRST COLOR
    if ((pixy.blocks[0].y < 80) && (tiltServoPos > 25))
    {
      tiltServoPos = (tiltServoPos - 1);
    }
    else if ((pixy.blocks[0].y > 120) && (tiltServoPos < 110))
    {
      tiltServoPos = (tiltServoPos + 1);
    }  
    
    //PAN TOWARD FIRST COLOR
    if (pixy.blocks[0].x < 130)
    {
      panServoSpeed = 99;
      digitalWrite(rightLed, HIGH);
      digitalWrite(leftLed, LOW);
    }
    else if (pixy.blocks[0].x > 190)
    {
      panServoSpeed = 82;
      digitalWrite(leftLed, HIGH);
      digitalWrite(rightLed, LOW);
    }  
    else
    {
      panServoSpeed = 90;
      digitalWrite(rightLed, LOW);
      digitalWrite(leftLed, LOW);
    }
    
    //PESTERCHUM ON CENTERED FIRST COLOR
    if ((pixy.blocks[0].y > 90) && (pixy.blocks[0].y < 110) && (pixy.blocks[0].x > 145) && (pixy.blocks[0].x < 175) && (helodyPlayed < 1))
    {
      for (int thisNote = 0; thisNote < 3; thisNote++)
      {
      // to calculate the note duration, take one second 
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000/helodyNoteDurations[thisNote];
      tone(8, helody[thisNote],noteDuration);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = 50;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
      helodyPlayed = (helodyPlayed + 1);
      }
    }
    else
    {
    helodyPlayed = 0;
    }
  }  

  
  panServo.write(panServoSpeed);
  tiltServo.write(tiltServoPos);
  delay(2);
}

//OTHERTHING
void otherthing()
{ 
  
}
