int ledBuzz = 5;
int dotLen = 200;
int dashLen = dotLen * 3;

// different letters

int letA[] = {0, 1};
int letA[] = {0, 1, 1, 1};
int letA[] = {0, 1, 0, 1};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("This is the almighty morse code generator");
  pinMode(ledBuzz, OUTPUT);
  
}

void loop() {
  if (Serial.available() > 0) {
    
    // Read the incoming byte
    char inputIn = Serial.read();
    inputIn = toupper(inputIn);
    
    // Echo the character back to the monitor
    if (inputIn == 'A'){
      Cycle();
    }
  }
  
}

void Cycle(){
  
  int numElements = sizeof(letA) / sizeof(letA[0]);
for (int i = 0; i < numElements; i++){
  if (letA[i] == 0) {
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
