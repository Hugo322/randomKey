#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);

  sevseg.setBrightness(90);
  
}

    void loop() {
      static unsigned long timer = millis();
      static int randNumber = 0;
      static int secretKey = 1234;//define a chave secreta
      static bool finish = false;

      if (millis() - timer >= 100 && finish == false) {
        timer += 100;
        randNumber = random(9999);//gera numeros aleatorios ate 9999

        if (randNumber == secretKey) {
          sevseg.setNumber(secretKey, 1);
          finish = true;
        }
        else{
          sevseg.setNumber(randNumber, 1);
        }
      }      
      sevseg.refreshDisplay();
    }

    
    

  
