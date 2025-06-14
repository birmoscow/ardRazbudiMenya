//changeTimeMode    //changeClockMode

void changeTime(){                    //после перехода из main строка времени, вверх вниз изменение, set далее, pos 3 off
  int pos = 1,
      buffHInt,
      buffMInt,
      buffSInt;
  String buffTime = (time.gettime("H:i")),
         buffHString,
         buffMString,
         buffSString;        
   
  while(true){
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(buffTime);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("change hour   > ");  
      if(pos == 1)
        while(pos == 1){                   //Меню на изменение часов, pos - позиция времени 1 -час, 2 - минута 3 off 
          timeT = (time.gettime("H:i"));
            if(buffTime != timeT){
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(timeT);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("change hour   > ");
              buffTime = timeT;            
            }
          if(checkSet(setButton)){   
              pos++;
              delay(200);
              break;
          }
          else if(checkUp(upButton)){
              buffHString = time.gettime("H");
              buffMString = time.gettime("i");
              buffSString = time.gettime("s");
              buffHInt = buffHString.toInt();
              buffSInt = buffSString.toInt();
              buffMInt = buffMString.toInt();
              buffHInt++;
              if(buffHInt > 23) buffHInt = 0;
              time.settime(buffSInt,buffMInt,buffHInt);
          }
          else if(checkDown(downButton)){
              buffHString = time.gettime("H");
              buffMString = time.gettime("i");
              buffSString = time.gettime("s");
              buffHInt = buffHString.toInt();
              buffSInt = buffSString.toInt();
              buffMInt = buffMString.toInt();
              buffHInt--;
              if(buffHInt < 0) buffHInt = 23;
              time.settime(buffSInt,buffMInt,buffHInt);
          }
        }

              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(timeT);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("change min    > ");
        
        if(pos == 2)
          while(pos == 2){                   //Меню на изменение часов, pos - позиция времени 1 -час, 2 - минута 3 off 
          timeT = (time.gettime("H:i"));
            if(buffTime != timeT){
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(timeT);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("change min    > ");
              buffTime = timeT;            
            }
          if(checkSet(setButton)){   
              pos++;
              delay(200);
              break;
          }
          else if(checkUp(upButton)){
              buffHString = time.gettime("H");
              buffMString = time.gettime("i");
              buffSString = time.gettime("s");
              buffHInt = buffHString.toInt();
              buffSInt = buffSString.toInt();
              buffMInt = buffMString.toInt();
              buffMInt++;
              if(buffMInt > 59) buffMInt = 0;
              time.settime(buffSInt,buffMInt,buffHInt);
          }
          else if(checkDown(downButton)){
              buffHString = time.gettime("H");
              buffMString = time.gettime("i");
              buffSString = time.gettime("s");
              buffHInt = buffHString.toInt();
              buffSInt = buffSString.toInt();
              buffMInt = buffMString.toInt();
              buffMInt--;
              if(buffMInt < 0) buffMInt = 59;
              time.settime(buffSInt,buffMInt,buffHInt);
          }
         }
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(timeT);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("up/down to exit");
         if(pos == 3)
          while(pos == 3){
            timeT = (time.gettime("H:i"));
            if(buffTime != timeT){
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(timeT);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("up/down to exit");
              buffTime = timeT;            
            }
            if(checkSet(setButton)){  
              pos = 1;
              delay(300);
              break;
            }
            else if(checkUp(upButton)){ 
              delay(300);  
              return;
            }
            else if(checkDown(downButton)){  
              delay(300); 
              return;
            }
      }
  }
}

void alarmClock(){                    //после перехода из main строка времени, вверх вниз изменение, set далее, pos 4 off   Часы, минуты, позиция;
  String buffHString = "",
         buffMString = "",
         buffTime = time1,
         fastBuff = "",
         buffPos = bud1;
  buffHString = buffHString + time1[0] + time1[1];
  buffMString = buffMString + time1[3] + time1[4];   
  int pos = 1,
      buffHInt = buffHString.toInt(),
      buffMInt = buffMString.toInt();
  while(true){                          //Меню на изменение часа будильника
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(time1);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("change hour   > ");
              buffTime = time1;             
      if(pos == 1)
        while(pos == 1){ 
             if(buffTime != time1){
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(time1);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("change hour   > ");
              buffTime = time1;            
            }                 
          if(checkSet(setButton)){   
              pos++;
              delay(300);
              break;
          }
          else if(checkUp(upButton)){
              buffHInt++;
              if(buffHInt > 23){
                buffHInt = 0;
              }
              if(buffHInt < 10)
                 fastBuff = fastBuff + "0" + buffHInt + time1[2] + time1[3] + time1[4];
              else
                 fastBuff = fastBuff + buffHInt + time1[2] + time1[3] + time1[4];
              time1 = fastBuff;
              fastBuff = "";
              delay(250);
          }
          else if(checkDown(downButton)){
              buffHInt--;
              if(buffHInt < 0) buffHInt = 23;
              if(buffHInt < 10)
                 fastBuff = fastBuff + "0" + buffHInt + time1[2] + time1[3] + time1[4];
              else
                 fastBuff = fastBuff + buffHInt + time1[2] + time1[3] + time1[4];
              time1 = fastBuff;
              fastBuff = "";
              delay(250);
          }
        }

              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(time1);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("change min    > ");
        
        if(pos == 2)
          while(pos == 2){                  
            if(buffTime != time1){
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(time1);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("change min    > ");
              buffTime = time1;            
            }
          if(checkSet(setButton)){   
              pos++;
              delay(300);
              break;
          }
          else if(checkUp(upButton)){
              buffMInt++;
              if(buffMInt > 59) buffMInt = 0;
              if(buffMInt < 10)
                 fastBuff = fastBuff + time1[0] + time1[1] + time1[2] + "0" + buffMInt;
              else
                 fastBuff = fastBuff + time1[0] + time1[1] + time1[2] + buffMInt;
              time1 = fastBuff;
              fastBuff = "";
              delay(150);
          }
          else if(checkDown(downButton)){
              buffMInt--;
              if(buffMInt < 0) buffMInt = 59;
              if(buffMInt < 10)
                 fastBuff = fastBuff + time1[0] + time1[1] + time1[2] + "0" + buffMInt;
              else
                 fastBuff = fastBuff + time1[0] + time1[1] + time1[2] + buffMInt;
              time1 = fastBuff;
              fastBuff = "";
              delay(150);
          }
         }
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(time1);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("     ");
              lcd.print(bud1);
         if(pos == 3)
          while(pos == 3){
            if(buffPos != bud1){
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("      ");
              lcd.setCursor(5, 0);
              lcd.print(time1);
              lcd.setCursor(10, 0);
              lcd.print("     ");
              lcd.setCursor(0, 1);
              lcd.print("     ");
              lcd.print(bud1);
              buffPos = bud1;            
            }
            if(checkSet(setButton)){  
              pos++;
              delay(250);
              break;
            }
            else if(checkUp(upButton)){   
              if(bud1 == "off") bud1 = "on";
                else  bud1 = "off";
              delay(300);  
            }
            else if(checkDown(downButton)){  
              if(bud1 == "off") bud1 = "on";
                else  bud1 = "off";
              delay(300); 
            }
      }
        if(pos == 4){
           lcd.clear();
           lcd.setCursor(0, 0);
           lcd.print("      ");
           lcd.setCursor(5, 0);
           lcd.print(time1);
           lcd.setCursor(10, 0);
           lcd.print("     ");
           lcd.setCursor(0, 1);
           lcd.print("up/down to exit");
            while(pos == 4){
              if(checkSet(setButton)){  
                pos = 1;
                delay(300);
                break;
              }
              else if(checkUp(upButton)){ 
                loadConf();
                delay(300);  
                return;
              }
              else if(checkDown(downButton)){  
                loadConf();
                delay(300); 
                return;
              }
        }
     }
  }
}

bool checkTime(){
   String timeT = (time.gettime("H:i"));
   if(timeT != time1)
        isAlarm = 0;
   if(bud1 == "on"){ 
        if(isAlarm == 0 && timeT == time1){
          lcd.backlight();
          soundNum5(buzzer);
          lcd.clear();
          isAlarm = 1;
          return true;
      }
      else{
        return false;
      }
   }
   else{
      return false;
   }
  
}

