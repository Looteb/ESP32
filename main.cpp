#include <Arduino.h>

enum class LedState{
    On,
    Off
};
class LedConfig{
public:
    static constexpr uint8_t LED_PIN = 16;
    static constexpr uint32_t BLINK_INTERVAL_MS = 500;
    static const uint8_t BLINK_COUNT = 3;
};
class Led{
private:
    uint8_t pin;
public:
    explicit Led(uint8_t ledPin) : pin(ledPin){}
    void init(){
        pinMode(pin, OUTPUT);
        set(LedState::Off);
    }
    void set(LedState state){
        if (state == LedState::On){
            digitalWrite(pin, HIGH);
        }
        else{
            digitalWrite(pin, LOW);
        }
    }
};
Led led(LedConfig::LED_PIN);
void setup() {
    Serial.begin(115200);
    led.init();
}

void loop(){
    static LedState ledState = LedState::Off;
    static uint32_t previousMillis = 0;
    const uint32_t currentMillis = millis();
    if ((currentMillis - previousMillis) >= LedConfig::BLINK_INTERVAL_MS){
        previousMillis = currentMillis;
        if (ledState == LedState::Off){
            ledState = LedState::On;
        }
        else{
            ledState = LedState::Off;
        }
        led.set(ledState);
    }
}