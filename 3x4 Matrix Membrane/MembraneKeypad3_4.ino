/**
 * Keypads
 *
 * This code demonstrates how to interface with a 4-row, 3-column 12 button keypad
 * 
 * e.g.
 * https://www.ebay.co.uk/itm/2PCS-Matrix-Array-12-Key-Membrane-Switch-Keypad-Keyboard-For-Arduino-AVR-4-x-3/191765733230 
 */

// Download the library through the Arduino IDE by going Sketch -> Include Library -> Manage Libraries
// and search for and download the latest version of "Keypad" (currently 3.1)
#include <Keypad.h>

// Define the characters in the matrix
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; // Row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5}; // Column pinouts of the keypad

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
