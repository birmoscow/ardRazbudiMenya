/*void soundNum1(int buz){
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

}*/
void soundNum5(int buz){
  String getTimeToExitStr1 = time.gettime("i"),
         getTimeToExitStr2;
    int flag = 0,
        getTimeToExitInt1 = getTimeToExitStr1.toInt(),
        getTimeToExitInt2;
  delay(150);
  lcd.clear();
  lcd.setCursor(1 , 0);
  lcd.print("Alarm!!! >> ON");
  lcd.setCursor(1 , 1);
  lcd.print("  press set");
  while(true){
          getTimeToExitStr2 = time.gettime("i");
          getTimeToExitInt2 = getTimeToExitStr2.toInt();
          if(abs(getTimeToExitInt2-getTimeToExitInt1) > 4){
            flag = 1;
            break;
          }
          for(int i = 0; i < 10; i++){
            tone(buz, 2000);
            if(checkSet(setButton)){
              flag = 1;
              break;
            }
          }
          if (flag)
            break;

          if(checkSet(setButton))
            break;
        
         /* noTone(buz);
          delay(50);*/
          for(int i = 0; i < 6; i++){
            noTone(buz);
            if(checkSet(setButton)){
              flag = 1;
              break;
            }
          }
          if (flag)
            break;

          if(checkSet(setButton))
            break;
          
          /*tone(buz, 2000);
          delay(150);*/
          for(int i = 0; i < 10; i++){
            tone(buz, 2000);
            if(checkSet(setButton)){
              flag = 1;
              break;
            }
          }
          if (flag)
            break;

          if(checkSet(setButton))
            break;
        
       /*   noTone(buz);
          delay(50);*/

          for(int i = 0; i < 6; i++){
            noTone(buz);
            if(checkSet(setButton)){
              flag = 1;
              break;
            }
          }
          if (flag)
            break;

          if(checkSet(setButton))
            break;
          
      /*    tone(buz, 2000);
          delay(150);*/
          for(int i = 0; i < 10; i++){
            tone(buz, 2000);
            if(checkSet(setButton)){
              flag = 1;
              break;
            }
          }
          if (flag)
            break;

          if(checkSet(setButton))
            break;
        
     /*     noTone(buz);
          delay(50);*/
          for(int i = 0; i < 6; i++){
            noTone(buz);
            if(checkSet(setButton)){
              flag = 1;
              break;
            }
          }
          if (flag)
            break;

          if(checkSet(setButton))
            break;
        
    /*      tone(buz, 2000);
          delay(500);*/

          for(int i = 0; i < 25; i++){
            tone(buz, 2000);
            if(checkSet(setButton)){
              flag = 1;
              break;
            }
          }
          if (flag)
            break;

          if(checkSet(setButton))
            break;
        
    /*      noTone(buz);
          delay(400);*/

          for(int i = 0; i < 15; i++){
            noTone(buz);
            if(checkSet(setButton)){
              flag = 1;
              break;
            }
          }
          if (flag)
            break;
          
          if(checkSet(setButton))
            break;
        }
        noTone(buzzer);
        delay(1000);
        lcd.clear();
        lcd.setCursor(1,1);
        lcd.print("Off");
        lcd.setCursor(1,0);
        lcd.print("press up or down");
        flag = 1;
   return;
}
