byte savedBits = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  printInBinary(savedBits);
  for (int i = 0; i < 8; i++) {
    savedBits = (0x80 >> i) + savedBits;        //0x80 is the first bit (most significant), aka 128. 0x80 is in HEX
    printInBinary(savedBits);
    //Serial.println(savedBits, BIN);
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
