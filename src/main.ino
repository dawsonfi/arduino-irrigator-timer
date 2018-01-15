#include <TimeLib.h>
#include <TimeAlarms.h>

#define RELAY_PIN 5
#define LED_PIN 1

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  setTime(7, 00, 0, 24, 04, 17);

  Alarm.alarmRepeat(7, 05, 0, activateWaterPump);
  Alarm.alarmRepeat(7, 35, 0, deactivateWaterPump);

  Alarm.alarmRepeat(17, 30, 0, activateWaterPump);
  Alarm.alarmRepeat(18, 00, 0, deactivateWaterPump);
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
