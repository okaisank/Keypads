/**
 * Keypads
 *
 * This code demonstrates how to interface with a 4-row, 4-column 16 button keypad
 * 
 * e.g.
 * https://www.ebay.co.uk/p/4-X-4-Matrix-Array-16-Keys-4-4-Switch-Keypad-Keyboard-Module-for-Arduino/941832464
 */
 
// Download the library through the Arduino IDE by going Sketch -> Include Library -> Manage Libraries
// and search for and download the latest version of "Keypad" (currently 3.1)
#include <Keypad.h>

// Define the characters in the matrix
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; // Row pinouts of the keypad
byte colPins[COLS] = {11, 10, 9, 8}; // Column pinouts of the keypad

// Create a new keypad based on the paremeters defined above
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  if (key){
    Serial.println(key);
  }
}
