byte byte1 = B00010100;
byte byte2 = B00100001;

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("byte1: ");
  printInBinary(byte1);
  Serial.print("byte2: ");
  printInBinary(byte2);
  Serial.println();

  byte1 = byte1 >> 1;
  byte2 = byte2 << 1;

  delay(1000);
}

void printInBinary(byte byteToPrint) {
  for (int i = 0; i < 8; i++) {
    Serial.print(bitRead(byteToPrint, i));
  }
  Serial.println();
}
