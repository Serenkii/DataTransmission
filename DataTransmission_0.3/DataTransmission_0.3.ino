
#define TRANSMISSION_TIME 30

#define SENDER_PIN 7
#define RECEIVER_PIN 8

byte messageToSend = 'n'; //B01101110;
byte receivedMessage = 0;


void setup() {
  pinMode(SENDER_PIN, OUTPUT);
  pinMode(RECEIVER_PIN, INPUT);
  Serial.begin(9600);
  Serial.print("messageToSend:    ");
  printInBinary(messageToSend, true);
}

void loop() {
  receivedMessage = 0;
  for (int i = 7; i >= 0; i--) {
    digitalWrite(SENDER_PIN, bitRead(messageToSend, i));
    delay(10);
    receivedMessage = receivedMessage + (digitalRead(RECEIVER_PIN) << i);
    delay(TRANSMISSION_TIME);
  }
  Serial.print("messageToSend:    ");
  printInBinary(messageToSend, true);
  Serial.print("receivedMessage:  ");
  printInBinary(receivedMessage, true);
  Serial.println((char) receivedMessage);
  delay(5000);
}

void printInBinary(byte byteToPrint, bool line) {
  for (int i = 7; i >= 0; i--) {
    Serial.print(bitRead(byteToPrint, i));
  }
  if (line) {
      Serial.println();
  }
}
