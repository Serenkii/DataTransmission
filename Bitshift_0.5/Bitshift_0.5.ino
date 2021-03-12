  byte savedBits1 = 0;
  byte savedBits2 = 0;
  byte savedBits3 = 0;

void setup() {
  savedBits1 = 0;
  savedBits2 = 0;
  savedBits3 = 0;
  Serial.begin(9600);
}

void loop() {
  setup();
  method1(savedBits1);
  Serial.println();
  delay(2000);
  
  method2(savedBits2);
  Serial.println();
  delay(2000);
  
  method3(savedBits3);
  Serial.println();
  delay(2000);
}

byte method3(byte bits) {
  Serial.println("method3:");
  for (int i = 7; i >= 0; i--) {
    byte tempRandom = random(0,2);
    Serial.print(tempRandom);
    Serial.print("  ---  ");
    bits = bits + (tempRandom << i);
    printInBinary(bits, true);
    delay(500);
  }
  return bits;
}

byte method2(byte bits) {
  Serial.println("method2:");
  for (int i = 0; i < 8; i++) {
    byte tempRandom = random(0,2);
    Serial.print(tempRandom);
    Serial.print("  ---  ");
    bits = bits + ((0x80 >> i) * tempRandom);
    printInBinary(bits, true);
    delay(500);
  }
  return bits;
}

byte method1(byte bits) {
  Serial.println("method1:");
  for (int i = 0; i < 8; i++) {
    bits = bits << 1;       //bitshift to the left
    printInBinary(bits, false);
    bits = bits + random(0,2);       
    Serial.print("  ---  ");
    printInBinary(bits, true);
    delay(500);
  }
  return bits;
}


void printInBinary(byte byteToPrint, bool line) {
  for (int i = 7; i >= 0; i--) {
    Serial.print(bitRead(byteToPrint, i));
  }
  if (line) {
      Serial.println();
  }
}
