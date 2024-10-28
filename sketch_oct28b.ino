const int switchPin = 2;  // Pin connected to one metal plate (touch-sensitive "switch")
const int ledPin = 13;    // Pin connected to the LED

void setup() {
  // Configure switchPin as input with internal pull-up resistor enabled
  // This keeps the switch pin HIGH by default and will register LOW when touched
  pinMode(switchPin, INPUT_PULLUP);  
  
  // Set the LED pin as an output to control the LED state (on/off)
  pinMode(ledPin, OUTPUT);           
}

void loop() {
  // Read the current state of the switchPin
  // LOW means the metal plates are in contact (touch detected)
  int switchState = digitalRead(switchPin);  
  
  // Output the switch state to the Serial Monitor for troubleshooting
  // Prints '0' when plates touch and '1' when they are apart
  Serial.println(switchState);  
  
  // Check if the switch state is LOW (indicating touch/contact)
  if (switchState == LOW) {     
    digitalWrite(ledPin, HIGH); // Turn on the LED when plates touch
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED when plates are apart
  }
}
