//Blink LED at a rate specified by the value of the analog input
const int LED = 13;                           // Pin for the LED

int val = 0;                                  // variable used to store the value comming from the sensor

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);                       // Telling ARDUINO LED is an OUTPUT

  //Note: Analog pins are automatically set as inputs
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(0);                      // Read the value from the sensor

  digitalWrite(LED, HIGH);                  // Turn the LED on 

  delay(val);                               // Stop the program for some time

  digitalWrite(LED, LOW);                   // Turn the LED off

  delay(val);                               // Stop the program for some time
}

//ARDUINO
//LED: Cathode(Short): GND 
//     Anode(Long): 13

//Breadboard
//Light-dependent resistor(LDR) in solderless BREADBOARD, Pins: f11 f9
//Cable 1 in pin g11 connected to 5v in Arduino
//Cable 2 in pin h9 connected to A0 in Arduino
//Cable 3 in pin h4 connected to GND (Ground) *IMPORTANT*
//10K Ohm Resistor in pins g9 and g4
