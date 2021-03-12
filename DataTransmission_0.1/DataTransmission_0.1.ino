
#define TRANSMISSION_TIME 200

#define SENDER_PIN 7
#define RECEIVER_PIN 8

byte messageToSend = B01101110;
byte receivedMessage = 0;


void setup() {
  pinMode(SENDER_PIN, OUTPUT);
  pinMode(RECEIVER_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    receivedMessage = receivedMessage + ((0x80 >> i) * (bitRead(messageToSend, 7 - i)));
    delay(TRANSMISSION_TIME);
  }
  Serial.print("messageToSend:    ");
  printInBinary(messageToSend, true);
  Serial.print("receivedMessage:  ");
  printInBinary(receivedMessage, true);
  delay(60000);
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
