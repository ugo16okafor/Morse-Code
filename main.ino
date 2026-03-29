const int ledBuzz = 5;
const int dotLen = 200;
const int dashLen = dotLen * 3;

// different letters

// A through I
const int letA[] = {0, 1};          // .-
const int letB[] = {1, 0, 0, 0};    // -...
const int letC[] = {1, 0, 1, 0};    // -.-.
const int letD[] = {1, 0, 0};       // -..
const int letE[] = {0};             // .
const int letF[] = {0, 0, 1, 0};    // ..-.
const int letG[] = {1, 1, 0};       // --.
const int letH[] = {0, 0, 0, 0};    // ....
const int letI[] = {0, 0};          // ..

// J through R
const int letJ[] = {0, 1, 1, 1};    // .---
const int letK[] = {1, 0, 1};       // -.-
const int letL[] = {0, 1, 0, 0};    // .-..
const int letM[] = {1, 1};          // --
const int letN[] = {1, 0};          // -.
const int letO[] = {1, 1, 1};       // ---
const int letP[] = {0, 1, 1, 0};    // .--.
const int letQ[] = {1, 1, 0, 1};    // --.-
const int letR[] = {0, 1, 0};       // .-.

// S through Z
const int letS[] = {0, 0, 0};       // ...
const int letT[] = {1};             // -
const int letU[] = {0, 0, 1};       // ..-
const int letV[] = {0, 0, 0, 1};    // ...-
const int letW[] = {0, 1, 1};       // .--
const int letX[] = {1, 0, 0, 1};    // -..-
const int letY[] = {1, 0, 1, 1};    // -.--
const int letZ[] = {1, 1, 0, 0};    // --..

const int lengths[] = {
  2, 4, 4, 3, 1, 4, 3, 4, 2,  // A-I
  4, 3, 4, 2, 2, 3, 4, 4, 3,  // J-R
  3, 1, 3, 4, 3, 4, 4, 4      // S-Z
};

// Map each letter variable to the master alphabet array
const int* alphabet[] = {
  letA, letB, letC, letD, letE, letF, letG, letH, letI,
  letJ, letK, letL, letM, letN, letO, letP, letQ, letR,
  letS, letT, letU, letV, letW, letX, letY, letZ
};



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("This is the almighty morse code generator");
  pinMode(ledBuzz, OUTPUT);
  
}



void loop() {
  if (Serial.available() > 0) {
    char input = toupper(Serial.read());

    // Only process if it's a letter from A to Z
    if (input >= 'A' && input <= 'Z') {
      
      // Math: 'A' (65) - 'A' (65) = 0. 'B' (66) - 'A' (65) = 1.
      int index = input - 'A'; 
      
      Serial.print("Sending: ");
      Serial.print(input);
      Serial.print(" ");

      // Pass the specific letter array and its length to Cycle
      Cycle(alphabet[index], lengths[index]);
      
      Serial.println(); // New line for next character
    } 
    else if (input == ' ') {
      delay(600); // Longer pause for a space between words
    }
  }
}


// Change "void Cycle()" to this:
void Cycle(const int* sequence, int numElements) {
  // Use "numElements" (the variable passed in) instead of manual sizeof
  for (int i = 0; i < numElements; i++) {
    // Use "sequence" (the array passed in) instead of "letA"
    if (sequence[i] == 0) {
      sendDot();
      Serial.print(".");
    } else {
      sendDash();
      Serial.print("-");
    }
  }
}



void sendDot() {
  digitalWrite(ledBuzz, HIGH); delay(dotLen); 
  digitalWrite(ledBuzz, LOW); delay(200);
}

void sendDash() {
  digitalWrite(ledBuzz, HIGH); delay(dashLen); 
  digitalWrite(ledBuzz, LOW); delay(200);
}
