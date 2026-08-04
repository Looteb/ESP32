#include <Arduino.h>

const int LED1 = 4;
const int LED2 = 5;
const int EXT_BUTTON = 18;  
const int BOOT_BUTTON = 0;   
int blinkDelay = 1000;        

void setup()
{
    Serial.begin(9600);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(EXT_BUTTON, INPUT_PULLUP);
    pinMode(BOOT_BUTTON, INPUT_PULLUP);
    Serial.println("default mode");
}

void loop()
{
    //режим для зовнішньої кнопки
    if (digitalRead(EXT_BUTTON) == HIGH)
    {
        blinkDelay = 500; 
        delay(50);
        Serial.println("external button mode");
    }
    //режим для boot
    if (digitalRead(BOOT_BUTTON) == LOW)
    {
        blinkDelay = 2000;
        delay(50);
        Serial.println("boot button mode");
    }
    //режим для двох зажатих кнопок
    if(digitalRead(BOOT_BUTTON) == LOW && digitalRead(EXT_BUTTON) == HIGH){
      blinkDelay = 200;
      delay(50);
      Serial.println("boot and external button mode");
    }
  
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(blinkDelay);

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(blinkDelay);
}