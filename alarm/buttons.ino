bool checkSet(int setBuff){
  setBuff = digitalRead(setButton);
  lcd.setCursor(0, 0);
  delay(10);
  if(!setBuff){
      if(lastSet = 1){   
          lastSet = 0;
          return false;
      }
      else{
        lastSet = 1;
        return true;
      }
  }
  else{
    if(lastSet = 1){
          return true;
      }
      else{
        return false;
      }
  }
}


bool checkUp(int setBuff){
  setBuff = digitalRead(upButton);
  delay(10);
  if(!setBuff){
      if(lastUp = 1){   
          lastUp = 0;
          return false;
      }
      else{
        lastUp = 1;
        return true;
      }
  }
  else{
    if(lastUp = 1){
          return true;
      }
      else{
        return false;
      }
  }
}


bool checkDown(int setBuff){
  setBuff = digitalRead(downButton);
  delay(10);
  if(!setBuff){
      if(lastDown = 1){   
          lastDown = 0;
          return false;
      }
      else{
        lastDown = 1;
        return true;
      }
  }
  else{
    if(lastDown = 1){
          return true;
      }
      else{
        return false;
      }
  }
}
