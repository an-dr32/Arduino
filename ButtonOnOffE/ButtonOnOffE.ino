const int LED = 13;           //Pin for LED
const int BUTTON = 7;         //Input pin where BUTTON is connected
int val = 0;                  // val is used to save the input pin state

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);       //Tells Arduino LED in an output
  pinMode(BUTTON, INPUT);     //Tells Arduino BUTTON is an input
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON); //Reads the input value and saves it on val

  //Check if input is HIGH(Button pressed)
  if (val == HIGH) {
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
