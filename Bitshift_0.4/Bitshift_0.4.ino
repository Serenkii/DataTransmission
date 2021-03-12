byte savedBits = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  printInBinary(savedBits);
  Serial.println();
  for (int i = 0; i < 8; i++) {
    savedBits = savedBits << 1;       //bitshift to the left
    printInBinary(savedBits);
    savedBits = savedBits + 1;       
    printInBinary(savedBits);
    Serial.println();
    delay(2000);
  }

  delay(1000);
}

void printInBinary(byte byteToPrint) {
  for (int i = 7; i >= 0; i--) {
    Serial.print(bitRead(byteToPrint, i));
  }
  Serial.println();
}
