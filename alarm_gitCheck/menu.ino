
void  mainMenu(){
    int countTime = 0;
    String buffTime1 = (time.gettime("H:i"));
    timeT = buffTime1;
    lcd.backlight();
    while(true){ 
              initFlag0();
              countTime = 0;
        if(flagTime == 0)
          while(true){      //проверка будильника
            if(checkTime()){
                initFlag0();      //загрузка дисплея
            }       
            if(countTime > 800){     //спящий режим
              sleepMode();
              initFlag0();
              countTime = 0;
            }
            else{
              countTime++;
            }
            timeT = (time.gettime("H:i"));
            if(buffTime1 != timeT){
              initFlag0();
              buffTime1 = timeT;            
            }                                     //ВремяДата -> Будильник 1 -> Будильник 2 -> Будильник 3 -> Будильник 4 -> Будильник 5 -> ВремяДата 
            if(checkSet(setButton)){                 //Пока ВремяДата -> Будильник 1 -> ВремяДата 
                delay(200);
                changeTime();        //настройка времени
                initFlag0();          //загрузка дисплея
                
            }
            if(checkUp(upButton)){
                              //буд 1
               flagTime = 1;
               countTime = 0;
               delay(200);
               break;
            }
            if(checkDown(downButton)){
               flagTime = 1;
               countTime = 0;
               delay(200);
               break;
            }
          }
        else if(flagTime == 1){   //буд 1
          initFlag1();           //загрузка дисплея
          while(true){                
            if(checkTime()){          //проверка будильника
                initFlag1(); 
            }
            if(countTime > 1100){     //спящий режим
              sleepMode();
              initFlag1();
              countTime = 0;
            }
            else{
              countTime++;
            }                             
            if(checkSet(setButton)){
               delay(300);
               alarmClock();    
               initFlag1();    //загрузка дисплея
            }
            if(checkUp(upButton)){
                              //меню
               flagTime = 0;
               delay(200);
               break;
            }
            if(checkDown(downButton)){
                             //меню
               flagTime = 0;
               delay(200);
               break;
            }
          }
        }
 /*       else if(flagTime == 2){//буд 2 
          lcd.clear(); 
          lcd.print("");
          while(true){                                     
            if(checkSet(setButton)){
                              
            }
            if(checkUp(upButton)){
                              //буд 3
               flagTime++;
               break;
            }
            if(checkDown(downButton)){
                             //буд 1
               flagTime--;
               break;
            }
          }
        }
        else if(flagTime == 3){
          lcd.clear(); 
          lcd.print("");
          while(true){                                     
            if(checkSet(setButton)){
                              
            }
            if(checkUp(upButton)){
                              //буд 4
               flagTime++;
               break;
            }
            if(checkDown(downButton)){
                             //буд 2
               flagTime--;
               break;
            }
          }
        }
        else if(flagTime == 4){
         lcd.clear(); 
          lcd.print("");
          while(true){                                     
            if(checkSet(setButton)){
                              
            }
            if(checkUp(upButton)){
                              //буд 5
               flagTime++;
               break;
            }
            if(checkDown(downButton)){
                             //буд 3
               flagTime--;
               break;
            }
          }
        }
        else{
         lcd.clear(); 
          lcd.print("");
          while(true){                                     
            if(checkSet(setButton)){
                              
            }
            if(checkUp(upButton)){
                              //меню
               flagTime++;
               break;
            }
            if(checkDown(downButton)){
                             //буд 4
               flagTime--;
               break;
            }
          }
        }*/
   }
}

bool sleepMode(){
  lcd.clear();
  lcd.noBacklight();
  delay(300);
  while(true){
      if(checkTime()){
             break;
      }
      if(checkSet(setButton)){
            delay(200);
            break;
      }
      else if(checkUp(upButton)){
            delay(200);
            break;
      }
      else if(checkDown(downButton)){
            delay(200);
            break;
      }
  }
  lcd.backlight();
  return;
}

void initFlag0(){
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print(" current: ");
   lcd.print(timeT);
   if(bud1 == "on"){   
     lcd.setCursor(0, 1);
     lcd.print(" alarm  : ");  
     lcd.print(time1);     
   }
}

void initFlag1(){
  lcd.clear(); 
  lcd.print("     ");
  lcd.print(time1);
  lcd.setCursor(0, 1);
  lcd.print("menu  ");
  lcd.print(bud1);
}


void setupConf(){
  byte confHour = eeprom_read_byte(0),
       confMin = eeprom_read_byte(1),
       confBud = eeprom_read_byte(2);
  time1 = "";
  if(confHour < 10)
      time1 = time1 + "0" + confHour;
  else
      time1 = time1 + confHour;
  time1 = time1 + ":";
  if(confMin < 10)
      time1 = time1 + "0" + confMin;
  else
      time1 = time1 + confMin;
  if(confBud == 1)
      bud1 = "on";
  else
      bud1 = "off";
  return;
}

void loadConf(){
  String  confHourStr = "",
          confMinStr = "",
          confBudStr = bud1;
          confHourStr = confHourStr + time1[0] + time1[1];
          confMinStr = confMinStr + time1[3] + time1[4];
  byte confHour = confHourStr.toInt(),
       confMin = confMinStr.toInt(),
       confBud = 0;
  if(confBudStr == "on")  confBud = 1;
    eeprom_write_byte(0, confHour);
    eeprom_write_byte(1, confMin);
    eeprom_write_byte(2, confBud);
  return;
  
}

