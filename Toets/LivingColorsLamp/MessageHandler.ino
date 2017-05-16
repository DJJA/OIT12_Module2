void handleMessage(String message){
  message.toLowerCase();

  int iDoubleColon = message.indexOf(':');

  
  if(iDoubleColon == -1){                                 // Check if parameter is present
    
  if(mCurrentMode != remote &&message == "remote_control")
      enterRemoteMode();                                 // Enter remote mode
  }else{
   
    String parameter = message.substring(iDoubleColon+1); // Get parameter
    message = message.substring(0, iDoubleColon);         // Cut message from string

    if(mCurrentMode == remote){                           // Messages only for remote mode
      if(message == "set_red"){                           // SET_RED
        setRed(parameter.toInt());
      }else if(message == "set_green"){                   // SET_GREEN
        setGreen(parameter.toInt());
      }else if(message == "set_blue"){                    // SET_BLUE
        setBlue(parameter.toInt());    
      }
    }
    
  }
}
