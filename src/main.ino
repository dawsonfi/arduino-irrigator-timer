#include <TimeLib.h>
#include <TimeAlarms.h>

#define RELAY_PIN 0
#define LED_PIN 1

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  deactivateWaterPump();

  setTime(18, 00, 0, 13, 10, 19); // Set time to October 13 2019 - 18:00:00

  Alarm.alarmRepeat(5, 05, 0, activateWaterPump);
  Alarm.alarmRepeat(5, 35, 0, deactivateWaterPump);

  Alarm.alarmRepeat(18, 05, 0, activateWaterPump);
  Alarm.alarmRepeat(18, 35, 0, deactivateWaterPump);
}

void loop() {
  Alarm.delay(1000);
}

void activateWaterPump() {
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
}

void deactivateWaterPump() {
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
}
