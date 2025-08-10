#include <Arduino.h>

#define LED_PIN PB0
#define BUTTON_PIN PB1

int buttonStatus = HIGH;
int ledStatus = LOW;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
    int reading = digitalRead(BUTTON_PIN);
    delay(10); // debounce filter

    if (buttonStatus != reading)
    {
        buttonStatus = reading;

        if (buttonStatus == LOW)
        {
            ledStatus = ledStatus == LOW ? HIGH : LOW;
            digitalWrite(LED_PIN, ledStatus);
        }
    }
}
