#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h>

int setButton = 6,
    upButton = 7,
    downButton = 8,
    buzzer = 9,
    lastSet = 0,
    lastUp = 0,
    lastDown = 0;
String timeT;
iarduino_RTC time(RTC_DS1302,3,5,4);
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей


void soundNum1(int buz){
  tone(buz, 1000); 
  delay(200);
 
  noTone(buz);
  delay(15);
  
  tone(buz, 1000); 
  delay(200); 
 
  noTone(buz);
  delay(15);

  tone(buzzer, 1000); 
  delay(200); 
 
  noTone(buz);
  delay(15);
  
  tone(buz, 1000); 
  delay(500); 
 
  noTone(buz);
  delay(1000);
  
}

void soundNum2(int buz){
  tone(buz, 1000);
  delay(500);

  noTone(buz);
  delay(300);
}

void soundNum3(int buz){
  tone(buz, 400);
  delay(300);
  tone(buz, 500);
  delay(300);
  tone(buz, 600);
  delay(300);
  tone(buz, 700);
  delay(300);
  tone(buz, 800);
  delay(300);

  tone(buz, 800);
  delay(300);
  tone(buz, 700);
  delay(300);
  tone(buz, 600);
  delay(300);
  tone(buz, 500);
  delay(300);
  tone(buz, 400);
  delay(300);

  tone(buz, 200);
  delay(1000);
  
  noTone(buz);
  delay(300);
}


void soundNum4(int buz){
  tone(buz, 200);   //Post-punk
  delay(220);

  noTone(buz);
  delay(220);

  tone(buz, 300);
  delay(200);
  noTone(buz);
  delay(60);
  tone(buz, 400);
  delay(200);
  noTone(buz);
  delay(40);
  tone(buz, 400);
  delay(150);

  noTone(buz);
  delay(100);

  tone(buz, 400);
  delay(130);
  noTone(buz);
  delay(100);
  tone(buz, 300);
  delay(150);

  noTone(buz);
  delay(260);

  tone(buz, 200);
  delay(350);

  noTone(buz);
  delay(170);

  tone(buz, 200);
  delay(130);
  noTone(buz);
  delay(110);
  tone(buz, 300);
  delay(130);
  noTone(buz);
  delay(110);
  tone(buz, 350);
  delay(130);
  noTone(buz);
  delay(110);
  tone(buz, 400);
  delay(130);
  noTone(buz);
  delay(110);
  tone(buz, 440);
  delay(130);
  noTone(buz);
  delay(110);
  tone(buz, 400);
  delay(300);
  noTone(buz);
  delay(1000);

}
void soundNum5(int buz){
  while(true){
          lcd.print("soundNum5 >>> ON");
          tone(buz, 2000);
          delay(150);

          if(checkSet(setButton))
            break;
        
          noTone(buz);
          delay(50);

          if(checkSet(setButton))
            break;
          
          tone(buz, 2000);
          delay(150);

          if(checkSet(setButton))
            break;
        
          noTone(buz);
          delay(50);

          if(checkSet(setButton))
            break;
          
          tone(buz, 2000);
          delay(150);

          if(checkSet(setButton))
            break;
        
          noTone(buz);
          delay(50);

          if(checkSet(setButton))
            break;
        
          tone(buz, 2000);
          delay(500);

          if(checkSet(setButton))
            break;
        
          noTone(buz);
          delay(400);
          
          if(checkSet(setButton))
            break;
        }
        noTone(buzzer);
        lcd.print("soundNum5 >> Off");
        delay(3000);
        lcd.clear();
   return;
}        

bool checkSet(int setBuff){
  setBuff = digitalRead(setButton);
  Serial.print(setBuff);
  Serial.print("   ");
  Serial.print(lastSet);
  Serial.println("");
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
  Serial.print(setBuff);
  Serial.print("   ");
  Serial.print(lastUp);
  Serial.println("");
  lcd.setCursor(0, 0);
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
  Serial.print(setBuff);
  Serial.print("   ");
  Serial.print(lastDown);
  Serial.println("");
  lcd.setCursor(0, 0);
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


void changeHour(){
 int hour = 1;

        lcd.setCursor(0, 1);
        lcd.print("set to quit");
        delay(500);
           while(true){
              if(checkSet(setButton)){
                  while(true){
                    if(checkUp(upButton)){
                      if(hour = 23)
                        hour = 0;
                      hour++;
                      delay(25);
                    }
                    if(checkDown(downButton)){
                      if(hour = 0)
                        hour = 23;
                      hour--;
                      delay(25);
                    }
                    if(checkSet(setButton)){
                      break;
                    }
                  }       //Дорабоать подстановку времени в модуль
              }
            }
   return;
}

void changeTime(){
  int pos = 1;
  while(true){
      if(pos = 1)
        while(pos = 1){                   //Меню на изменение часов, pos - позиция времени 1 -час, 2 - минута, 3 -секунда 
          lcd.clear();
          timeT = (time.gettime("H:i:s"));
          lcd.setCursor(0, 0);
            lcd.print("     ");
            lcd.setCursor(5, 0);
            lcd.print(timeT);
            lcd.setCursor(10, 0);
            lcd.print("      ");
            lcd.setCursor(0, 1);
            lcd.print("change hour   > ");
          if(checkSet(setButton))   
              changeHour();
          else if(checkUp(upButton)) pos = 2;
          else if(checkDown(downButton)) pos = 3;
        }

        if(pos = 2)
          while(pos = 2){
            lcd.clear();
            timeT = (time.gettime("H:i:s"));
            lcd.setCursor(0, 0);
            lcd.print("     ");
            lcd.setCursor(5, 0);
            lcd.print(timeT);
            lcd.setCursor(10, 0);
            lcd.print("      ");
            lcd.setCursor(0, 1);
            lcd.print("change min    > ");
            lcd.setCursor(0, 1);
            if(checkSet(setButton))   
               changeHour();         //MIN
            else if(checkUp(upButton)) pos = 3;
            else if(checkDown(downButton)) pos = 1;
         }

         if(pos = 3)
          while(pos = 3){
            lcd.clear();
            timeT = (time.gettime("H:i:s"));
            lcd.setCursor(0, 0);
            lcd.print("     ");
            lcd.setCursor(5, 0);
            lcd.print(timeT);
            lcd.setCursor(10, 0);
            lcd.print("      ");
            lcd.setCursor(0, 1);
            lcd.print("change sec    > ");
            if(checkSet(setButton))    
                changeHour();         //SEC
            else if(checkUp(upButton)) pos = 1;
            else if(checkDown(downButton)) pos = 2;
         }
  }
}

void setup(){
      
    Serial.begin(9600);
  
    lcd.init();                     
    lcd.backlight();// Включаем подсветку дисплея
  
  
  
    pinMode(setButton, INPUT);
    pinMode(upButton, INPUT);
    pinMode(downButton, INPUT);
  
  
  
    pinMode(buzzer, OUTPUT);
  
  
  
    delay(300);
    Serial.begin(9600);
    time.begin();
  //  time.settime(0,58,14,2,2,20,1);  // 0  сек, 51 мин, 21 час, 27, октября, 2015 года, вторник
  
}
void loop(){
       if(checkUp(upButton)){
          soundNum5(buzzer);
       } 
       if(checkDown(downButton)){
          soundNum5(buzzer);
       }  
       if(checkSet(setButton)){
          soundNum5(buzzer);
       }  
    /*   timeT = (time.gettime("H:i:s"));
        lcd.print(timeT);
        delay(1000);
        lcd.clear();    */
}
