#include <Arduino.h>
#include <esp_task_wdt.h>
//3 seconds WDT
#define WDT_TIMEOUT 3

int e = 1;

int add(int a, int b){
  int c = a + b;
  return c;
}

void setup() {
  Serial.begin(119200);
  esp_task_wdt_init(WDT_TIMEOUT, true); //enable panic so ESP32 restarts
  esp_task_wdt_add(NULL); //add current thread to WDT watch
}

void loop() {
  unsigned long seconds = millis()/1000;
  unsigned long minutes = seconds/60;
  unsigned long remSeconds = seconds-(minutes*60);
  int f = 3;
  int d = add(e, f);
  Serial.printf("e = %i, d = %i, %02lu:%02lu\n",e, d, minutes, remSeconds);
  e += 1;
  delay(1000);
}