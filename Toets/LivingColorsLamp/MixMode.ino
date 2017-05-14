void mixMode(){
  int reading = analogRead(mPinPot);
  int mapped = map(reading, 0, 1023, 0, 1535);

  byte r, g, b;
  if(mapped < 256){             // blue goes up
    r = 255;
    g = 0;
    b = mapped;
  }else if(mapped < 512){       // red goes down
    r = 255 - (mapped - 256);
    g = 0;
    b = 255;
  }else if(mapped < 768){       // Green goes up
    r = 0;
    g = mapped - 512;
    b = 255;
  }else if(mapped < 1024){      // Blue goes down
    r = 0;
    g = 255;
    b = 255 - (mapped - 768);
  }else if(mapped < 1280){      // Red goes up
    r = mapped - 1024;
    g = 255;
    b = 0;
  }else if(mapped < 1536){      // Green goes down
    r = 255;
    g = 255 - (mapped - 1280);
    b = 0;
  }

  setColor(r, g, b);
}

