#include <Servo.h>

#define numofvalsRec 5
#define digitspervalRec 1

Servo servoThumb;
Servo servoIndex;
Servo servoMiddle;
Servo servoRing;
Servo servoPinky;

int valsRes[numofvalsRec];
int stringlength = numofvalsRec + digitspervalRec + 1; //$00000
int counter = 0;
bool counterstart = false ;
String receivedstring ;



void setup() {
  Serial.begin(9600);
  servoThumb.attach(7);
  servoIndex.attach(9);
  servoMiddle.attach(11);
  servoRing.attach(8);
  servoPinky.attach(10);

}

void receieveData() {
  while (Serial.available())
  {
    char c = Serial.read();
    if (c == '$') {
      counterstart = true;
    }
    if (counterstart) {
      if (counter < stringlength) {
        receivedstring = String (receivedstring + c);
        counter++;
      }
      if (counter >= stringlength ) {
        for (int i = 0; i < numofvalsRec; i++)
        {
          int num = (i * digitspervalRec) + 1;
          valsRes[i] = receivedstring.substring(num, num + digitspervalRec).toInt();
        }
        receivedstring = "";
        counter = 0;
        counterstart = false;
      }
    }

  }

}


void loop() {
  receieveData();
  if (valsRes[0] == 1) {
    servoThumb.write(180);
  } else {
    servoThumb.write(0);
  }
  if (valsRes[1] == 1) {
    servoIndex.write(180);
  } else {
    servoIndex.write(0);
  }
  if (valsRes[2] == 1) {
    servoMiddle.write(180);
  } else {
    servoMiddle.write(0);
  }
  if (valsRes[3] == 1) {
    servoRing.write(180);
  } else {
    servoRing.write(0);
  }
  if (valsRes[4] == 1) {
    servoPinky.write( 180);
  } else {
    servoPinky.write(0);
  }

}
