#include <Wire.h>
#include <MOD1005.h>

int sec, mins, hrs, dow, date, month, year, psec, previous;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Embedded Adventures DSP-7S04B demo\n\r");
  mod1005.init();
}

void loop() {
  updateClock();
  print_serial();
  delay(1007);
}

void updateClock() { 
  psec = mod1005.getPartSeconds(); 
  sec = mod1005.getSeconds();
  mins = mod1005.getMinutes();
  hrs = mod1005.getHours();
  dow = mod1005.getDayOfWeek();
  date = mod1005.getDate();
  month = mod1005.getMonth();
  year = mod1005.getYear();
}

void print_serial() {
  Serial.println("Showing time - ");
  Serial.print(hrs);
  Serial.print(":");
  Serial.print(mins);
  Serial.print(":");
  Serial.print(sec);
  Serial.print(":");
  Serial.println(psec);
}

