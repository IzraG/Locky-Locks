#include <EEPROM.h>
#include <Servo.h>
Servo servo;
char state;

void setup() {
  // put your setup code here, to run once:

  pinMode(13,OUTPUT);
  if(EEPROM.read(0) == 1)
   {
        digitalWrite(13,HIGH);
        delay(200);
   }
   else if(EEPROM.read(0) == 2)
   {
        digitalWrite(13,LOW);
        delay(200);
   }

  Serial.begin (9600);
  
}

void loop() {
  if(Serial.available() > 0)
  {
    char data;
    data = Serial.read();
    
    switch(data){
       case'1':
       if(EEPROM.read(0) == 1) 
        {
          EEPROM.write(0, 2);  
          Serial.print("3"); 
          digitalWrite(13,LOW);
         
        }
    
    
        else if(EEPROM.read(0) == 2) 
        {
          EEPROM.write(0, 1); 
          Serial.print("4"); 
          digitalWrite(13,HIGH);
         
        }
        
        break;
    
    case '3':
      if(EEPROM.read(0) == 1)
        {
          Serial.print("4");
        }
        else if(EEPROM.read(0) == 2)
        {
          Serial.print("3");
        }
        
      break;
    }
   
        
      
      
      
    
   }
  
  // put your main code here, to run repeatedly:

}
