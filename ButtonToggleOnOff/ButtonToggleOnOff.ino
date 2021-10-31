const int LED = 13;           //Pin for LED
const int BUTTON = 7;         //Input pin where BUTTON is connected
int val = 0;                  // "val" is used to save the input pin state
int old_val = 0;               //Stores the previous value of "val"
int state = 0;                //0 = LED is off while 1 = LED is on

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);       //Tells Arduino LED in an output
  pinMode(BUTTON, INPUT);     //Tells Arduino BUTTON is an input
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON); //Reads the input value and saves it on "val"

  //Check if the input is HIGH (Button pressed) and change the state
  //Also if there was a transition
  if ((val == HIGH) && (old_val == LOW)){
    state = 1 - state;       // (1 - 1 = 0) OFF | (1 - 0 = 1) ON
    delay(10);               //To prevent BOUNCING from the pushbutton
  }

  old_val = val;             //"val" is now the old value, store it.
  
  //Check the state of the state and adjust led accordingly
  if (state == 1) {
    digitalWrite(LED, HIGH); //Turns on LED
  }else{
    digitalWrite(LED, LOW);  //Turns off LED
  }
}

//Momentary Tactile pushBUTTON Switch in solderless BREADBOARD, Pins: e22 e20 f22 f20
//Cable 1 in pin f22 connected to 5v in Arduino
//Cable 2 in pin f20 connected to 7 in Arduino
//Cable 3 in pin h14 connected to GND (Ground) *IMPORTANT*
//10K Ohm Resistor in pins g20 and g14
