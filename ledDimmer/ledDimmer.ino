const int LED = 9;                //The pin for the LED
int i = 0;                        // This will count up and down
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);           //Telling ARDUINO the LED is an output
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < 255; i++) {    //loops from 0 to 254 (fade in)
    analogWrite(LED, i);         //set the led brightness
    delay(10);                   //Wait 10ms because analogWrite is instantaneous
                                 //and we wouldn't see any change
  }

  for (i = 255; i > 0; i--) {    //loop from 255 to 1 (fade out)
    analogWrite(LED, i);         //sets the led brightness
    delay(10);                   //Wait 10ms
  }
}

//Breadboard
//LED: h20 h19
//220R Ohm Resistor: i20 i26
//Cable 1: i19 to 9 on ARDUINO
//Cable 2: j26 to GND (Ground) in ARDUINO
