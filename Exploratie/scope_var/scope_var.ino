int buttonPin = A1;
int counter  = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(38400);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    delay(200);
    int counter = 0;
    while (counter < 10)
    {
      counter++;
    }
  }
  Serial.print("Counter = "); 
  Serial.println(counter); // What's the printed value of 'counter'
                           // if the button was pressed?

                           // Zoals ik al dacht blijf hij 0, omdat de counter var in de if statemennt zelf alleen maar wordt geincrement.
}

