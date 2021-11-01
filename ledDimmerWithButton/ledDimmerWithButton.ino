const int LED = 9;                //The pin for the LED
const int BUTTON = 7;             //Input pin for the pushBUTTON

int val = 0;                      //stores the state of the input pin

int old_val = 0;                  //stores the previous value of "val"
int state = 0;                    //0 = LED OFF while 1 = LED ON

int brightness = 128;             //stores the brightness value
unsigned long startTime = 0;      //when did we began pressing?

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);           //Telling ARDUINO the LED is an output
  pinMode(BUTTON, INPUT);         //Telling ARDUINO the button is an input
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON);      //Read input value and store it

  //Check if there was a transition
  if((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;            //Change the state from ON to OFF or vice-versa

    startTime = millis();          //millis() is the ARDUINO CLOCK
                                  //It returns how many milliseconds have passed since board reset

    //This line remembers when the button was last pressed
    delay(10);
  }

  //Check whether the button is being held down or not
  if ((val == HIGH) && (old_val == HIGH)){

    //If the button is held for more than 500ms
    if (state == 1 && (millis() - startTime) > 500) {
      brightness++;               //Increment brightness by 1
      delay(10);                  //Delay to avoid brightness going up to fast

      if(brightness > 255) {      //255 is the max brightness
        brightness = 0;            //if we go over 255 let's go back to 0
      }
    }
  }

  old_val = val;                  //val is now old, let's store it

  if(state == 1) {
    analogWrite(LED, brightness); //turn LED ON at the current brightness level
  }else{
    analogWrite(LED, 0);          //turn LED OFF
  }
}

//Breadboard LED
//LED: h20 h19
//220R Ohm Resistor: i20 i26
//Cable 1: i19 to 9 on ARDUINO
//Cable 2: j26 to GND (Ground) in ARDUINO

//Breadboard BUTTON
//Momentary Tactile pushBUTTON Switch in solderless BREADBOARD, Pins: e12 e10 f12 f10
//Cable 1 in pin g12 connected to 5v in Arduino
//Cable 2 in pin h10 connected to 7 in Arduino
//Cable 3 in pin h4 connected to GND (Ground) *IMPORTANT*
//10K Ohm Resistor in pins g10 and g4
