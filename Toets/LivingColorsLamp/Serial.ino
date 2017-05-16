void readSerial(){
  static String mBuffer = "";
  
  if (Serial.available() > 0) {                     // Check if there are bytes to read in the serial
      mBuffer += (char) Serial.read();              // Read a byte, cast it to char and add it to the buffer

      int hekje = mBuffer.indexOf('#');
      int procent = mBuffer.indexOf('%');

      if((hekje == -1 && procent > -1) || (procent > -1 && hekje > procent)){       // # not present and % is or % seen earlier than #
        mBuffer = mBuffer.substring(procent+1);                                     // Cut string off from % char forward
        hekje = mBuffer.indexOf('#');                                               // Refresh the indexes, mBuffer has changed
        procent = mBuffer.indexOf('%');                                             //
      }
      
      if(hekje > -1 && procent > -1 && hekje < procent){              // If # and % are present and # appears in front of %
        String message = mBuffer.substring(hekje+1, procent);         // Copy the message from the buffer
        mBuffer = mBuffer.substring(procent+1);                       // Remove the copied message from the buffer
        handleMessage(message);
      }
  }
}

void sendRGBValues(){                 // Send the current led values to the computer if they've changed
  if(mRedChanged){
    mRedChanged = false;
    Serial.print("#RED_STATUS:");
    Serial.print(mRedValue);
    Serial.println("%");
  }
  if(mGreenChanged){
    //Serial.println(mGreenChanged);
    mGreenChanged = false;
    Serial.print("#GREEN_STATUS:");
    Serial.print(mGreenValue);
    Serial.println("%");
  }
  if(mBlueChanged){
    mBlueChanged = false;
    Serial.print("#BLUE_STATUS:");
    Serial.print(mBlueValue);
    Serial.println("%");
  }
}
