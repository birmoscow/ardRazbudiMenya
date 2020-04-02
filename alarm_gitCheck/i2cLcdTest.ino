#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h>
#include <avr/eeprom.h>

int setButton = 6,
    upButton = 7,
    downButton = 8,
    buzzer = 9,
    lastSet = 0,
    lastUp = 0,
    lastDown = 0,
    flagTime = 0,//из menu
    isAlarm = 0;
    //конечно, работа с памятью ужасная, но это первый проект т.ч. бывает
   
String timeT = "",
       bud1 = "",
       time1 = "";
iarduino_RTC time(RTC_DS1302,3,5,4);
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей      
void setup(){
    Serial.begin(9600);
  
    lcd.init();                     
    lcd.backlight();  // Включаем подсветку дисплея
  
    pinMode(setButton, INPUT);
    pinMode(upButton, INPUT);
    pinMode(downButton, INPUT);
 
    pinMode(buzzer, OUTPUT);
  
    delay(300);
    Serial.begin(9600);
    time.begin();
    setupConf();
}
void loop(){
    mainMenu();
}
