void handleMessage(String message){
  Serial.print("This is the message: ");
  Serial.println(message);  

  message.toLowerCase();

  int iDoubleColon = message.indexOf(':');

  
  if(iDoubleColon == -1){
    
    if(message == "remote_mode")
      digitalWrite(mPinLedRemote, HIGH);
      mCurrentMode = remote;
      
  }else{
   
    String parameter = message.substring(iDoubleColon+1);
    message = message.substring(0, iDoubleColon);
    //Serial.print("parameter: ");
    //Serial.println(parameter);
    
    if(message == "dimled"){
      //analogWrite(mPinLed, parameter.toInt());
    }
    
  }
}
