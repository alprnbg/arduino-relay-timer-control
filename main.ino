#include <config.h>
#include <ds3231.h>

#include <Wire.h>
 
struct ts t; 
 
int relay = 8;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  DS3231_init(0);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  /*
  t.hour=0; 
  t.min=57;
  t.sec=0;
  t.mday=12;
  t.mon=7;
  t.year=2020;
  */
  //DS3231_set(t); 
}

void loop() {
  DS3231_get(&t);
  
  if (t.hour == 6 || t.hour == 18){
    digitalWrite(relay, LOW);
  } else {
    digitalWrite(relay, HIGH);
  }
  /*
  Serial.println(t.hour);
  Serial.println(t.min);
  Serial.println(t.sec);
  Serial.println();
  */
  delay(1000);

}
