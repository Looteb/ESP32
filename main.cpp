#include <Arduino.h>

#define LED1 15
#define LED2 16
#define LED3 17

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

const unsigned long interval1 = 200;
const unsigned long interval2 = 500;
const unsigned long interval3 = 1000;

bool led1State = LOW;
bool led2State = LOW;
bool led3State = LOW;

void setup(){
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
}

void loop(){
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis1 >= interval1){
        previousMillis1 = currentMillis;
        led1State = !led1State;
        digitalWrite(LED1, led1State);
    }
    if (currentMillis - previousMillis2 >= interval2){
        previousMillis2 = currentMillis;
        led2State = !led2State;
        digitalWrite(LED2, led2State);
    }
    if (currentMillis - previousMillis3 >= interval3){
        previousMillis3 = currentMillis;
        led3State = !led3State;
        digitalWrite(LED3, led3State);
    }
}