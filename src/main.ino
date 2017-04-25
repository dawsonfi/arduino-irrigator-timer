#include <TimeLib.h>
#include <TimeAlarms.h>

#define RELAY_PIN 5

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  setTime(8, 28, 0, 24, 04, 17);

  Alarm.alarmRepeat(8,30,0, activateWaterPump);
  Alarm.alarmRepeat(8,40,0, deactivateWaterPump);
}

void loop() {
  Alarm.delay(1000);
}

void activateWaterPump() {
  digitalWrite(RELAY_PIN, LOW);
}

void deactivateWaterPump() {
  digitalWrite(RELAY_PIN, HIGH);
}
