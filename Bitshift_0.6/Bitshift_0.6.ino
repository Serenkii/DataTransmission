 /*
  * efficiency testing
  * 
  * METHOD OF CHOICE:
  *   -method2
  *   -method3 
  *   
  *   -method1 isn't ideal because at the beginning the first bit is saved at the least significant bit, only at the end the position is correct....
  */
  #define arrayLength 256
  
  byte savedBits1[arrayLength];
  byte savedBits2[arrayLength];
  byte savedBits3[arrayLength];

  long method1Time;
  long method2Time;
  long method3Time;
void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long startMillis = millis();

  /*
   * TIME WITH "Serial.print"s:     56375
   * TIME WITHOUT "Serial.print"s:  464 - 464 - 466 - 466 - 466 - 466 -- 464 - 466 - 466
   */
  for (int i = 0; i < arrayLength; i++) {
    method1(savedBits1[i]);
    Serial.println();
  }
  method1Time = millis() - startMillis;
  Serial.print("method1 TIME:");
  Serial.println(method1Time);
  delay(10000);

  /*
   * TIME WITH "Serial.print"s:     41465
   * TIME WITHOUT "Serial.print"s:  465 - 465 - 465 - 464 - 465 - 465 -- 465 - 465 - 464
   */
  startMillis = millis();
  for (int i = 0; i < arrayLength; i++) {
    method2(savedBits2[i]);
    Serial.println();
  }
  method2Time = millis() - startMillis;
  Serial.print("method2 TIME:");
  Serial.println(method2Time);
  delay(10000);

  /*
   * TIME WITH "Serial.print"s:     41466
   * TIME WITHOUT "Serial.print"s:  464 - 466 - 465 - 465 - 465 - 464 -- 466 - 465 - 465
   */
  startMillis = millis();
  for (int i = 0; i < arrayLength; i++) {
    method3(savedBits3[i]);
    Serial.println();
  }
  method3Time = millis() - startMillis;
  Serial.print("method3 TIME:");
  Serial.println(method3Time);
  delay(10000);
}

byte method3(byte bits) {
  //Serial.println("method3:");
  for (int i = 7; i >= 0; i--) {
    byte tempRandom = random(0,2);
    //Serial.print(tempRandom);
    //Serial.print("  ---  ");
    bits = bits + (tempRandom << i);
    //printInBinary(bits, true);
  }
  return bits;
}

byte method2(byte bits) {
  //Serial.println("method2:");
  for (int i = 0; i < 8; i++) {
    byte tempRandom = random(0,2);
    //Serial.print(tempRandom);
    //Serial.print("  ---  ");
    bits = bits + ((0x80 >> i) * tempRandom);
    //printInBinary(bits, true);
  }
  return bits;
}

byte method1(byte bits) {
  //Serial.println("method1:");
  for (int i = 0; i < 8; i++) {
    bits = bits << 1;       //bitshift to the left
    //printInBinary(bits, false);
    bits = bits + random(0,2);       
    //Serial.print("  ---  ");
    //printInBinary(bits, true);
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
