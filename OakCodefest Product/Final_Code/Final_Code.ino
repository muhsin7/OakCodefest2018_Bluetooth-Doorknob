#include <LiquidCrystal.h>

#include <Servo.h>


#include <SoftwareSerial.h>//servo name

int bluetoothTx = 0;  //bluetooth Tx to 10 pin
int bluetoothRx = 1;  //bluetooth Rx to 11 pin
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
const int rs = 11, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int BuzzPin = 7;

/*int servorot = bluetooth.read();  //save the received number to servorot*/

  
void setup() {
pinMode(BuzzPin, OUTPUT);
Servo knob;
knob.attach(9);
knob.writeMicroseconds(1500); //set servo to middle

//servo setup

  // put your setup code here, to run once:

  //setup usb serial connection to computer
  Serial.begin(9600); //9600 baud rate

  //setup usb serial connection to computer
  bluetooth.begin(9600); //9600 baud rate

//lcd setup
  //set the number and rows in the LCD

//buzzer
    
        

        
}




void loop() {
/*  // put your main code here, to run repeatedly: */
int servorot = bluetooth.read();
 if (bluetooth.available() > 0 ) //if bluetooth is available receive number from bluetooth
  {
    
    Serial.println(servorot); //serial print servorot current number received from bluetoot
  }


   Servo knob;
          knob.attach(9);
 if (servorot == 49) { 
      int x = 1;
      for (int x = 1; x <2; x++) { 
        
          knob.writeMicroseconds(1690);
          delay (1000);
          lcd.begin(16, 2);
          digitalWrite(BuzzPin, HIGH);
          delay (2000);
          digitalWrite(BuzzPin, LOW);
          delay (1000);
          lcd.print("COME IN!");//LCD prints COME IN!
          delay(2000); //delay message for 7.5
          lcd.noDisplay();
          
      }
  
}



else {
   digitalWrite(13, HIGH); 
  
}


// if (servorot == 94) {
//  knob.writeMicroseconds(1310);
//}

//else {
 // digitalWrite(13, HIGH);
//}

 }


