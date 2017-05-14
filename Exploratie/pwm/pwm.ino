#define PIN_POT A0
#define PIN_LED 11
#define PIN_HANDICAPPED_LED 5
#define PIN_HANDICAPPED_LED2 6

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_POT, INPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_HANDICAPPED_LED, OUTPUT);
  pinMode(PIN_HANDICAPPED_LED2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte value = map(analogRead(PIN_POT), 0, 1023, 0, 255);
  analogWrite(PIN_LED, value);
  analogWrite(PIN_HANDICAPPED_LED, value);
  analogWrite(PIN_HANDICAPPED_LED2, value);
  delay(100);
}
