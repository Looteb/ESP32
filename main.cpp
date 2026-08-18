#include <Arduino.h>

#define LDR_PIN 4

#define ADC_MAX 4095.0
#define VREF 3.1
#define CALLBACK_DELAY 1000

void setup()
{
    Serial.begin(115200);
    analogReadResolution(12);
    analogSetPinAttenuation(LDR_PIN, ADC_11db);
}

void loop()
{
    int raw = analogRead(LDR_PIN);
    float voltage = ((float)raw / ADC_MAX) * VREF;
    float voltage_mV = voltage * 1000.0;
    int measured_mV = analogReadMilliVolts(LDR_PIN);
    float error = 0;
    if (measured_mV != 0){
        error = abs(voltage_mV - measured_mV)/ measured_mV * 100.0;
    }

    Serial.print("RAW: ");
    Serial.print(raw);

    Serial.print(" | volage: ");
    Serial.print(voltage, 2);

    Serial.print(" | calcMVolts: ");
    Serial.print(voltage_mV, 2);
    Serial.print(" mV");

    Serial.print(" | analogReadMVolts: ");
    Serial.print(measured_mV);
    Serial.print(" mV");

    Serial.print(" | Error: ");
    Serial.print(error, 2);
    Serial.println(" %");

    delay(CALLBACK_DELAY);
}