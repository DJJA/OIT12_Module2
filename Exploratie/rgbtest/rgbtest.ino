const byte red = 9, green = 10, blue = 11, pot = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(pot);
  Serial.println("-------------------------------------------");
  Serial.print("pot=");
  Serial.println(value);
  setColor(map(value, 0, 1023, 0, 1535));
  delay(50);
}

void setColor(int var) {
  Serial.print("var=");
  Serial.println(var);
  byte r, g, b;
  if(var < 256){  // Blue goes up
    r = 255;
    g = 0;
    b = var;
  }else if(var < 512){  // Red goes down  - Bij deze overgang is hij twee keer 255,0,255
    r = 255 - (var - 256);
    g = 0;
    b = 255;
  }else if(var < 768){  // Green goes up
    r = 0;
    g = var - 512;
    b = 255;
  }else if(var < 1024){ // Blue goes down
    r = 0;
    g = 255;
    b = 255 - (var - 768);
  }else if(var < 1280){ // Red goes up
    r = var - 1024;
    g = 255;
    b = 0;
  }else if(var < 1536){ // Green goes down
    r = 255;
    g = 255 - (var - 1280);
    b = 0;
  }

  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}

