const byte mPinLed = 11;

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        //Serial.setTimeout(0);
        pinMode(mPinLed, OUTPUT);
}

void loop() {
        // send data only when you receive data:
        readSerial();
}

void readSerial(){
  static String mBuffer = "";
  
  if (Serial.available() > 0) { // Check if there are bytes to read in the serial
      mBuffer += (char) Serial.read();  // Read a byte, cast it to char and add it to the buffer

      int hekje = mBuffer.indexOf('#');
      int procent = mBuffer.indexOf('%');
      if(hekje > -1 && procent > -1 && hekje < procent){ // If # and % are present and # appears in front of %
        String message = mBuffer.substring(hekje+1, procent);
        mBuffer = mBuffer.substring(procent+1);
        handleMessage(message);
      }
      //Serial.println(hekje);
      //Serial.println(procent);
      Serial.println(mBuffer);
  }
}

void handleMessage(String message){
  Serial.print("This is the message: ");
  Serial.println(message);
  /*switch(message){
    case "Led on":
      digitalWrite(mPinLed, HIGH);
      break;
    case "Led off":
      digitalWrite(mPinLed, LOW);
  }*/

  Serial.println(message.startsWith("ho"));
  

  message.toLowerCase();

  int iDoubleColon = message.indexOf(':');
  if(iDoubleColon == -1){
    if(message == "led on")
      digitalWrite(mPinLed, HIGH);
    else if(message == "led off")
      digitalWrite(mPinLed, LOW);
  }else{
    String parameter = message.substring(iDoubleColon+1);
    Serial.print("parameter: ");
    Serial.println(parameter);
    if(message.startsWith("dimled")){
      analogWrite(mPinLed, parameter.toInt());
    }
  }
}

