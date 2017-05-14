const int mPin = 9;
float value = 1023;

void setup() {
  // put your setup code here, to run once:
  pinMode(mPin, OUTPUT);
  //analogWrite(mPin, 512);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = value - 24;
  if(value < 0)
    value = 1023;
  analogWrite(mPin, value);
  delay(50);
}
