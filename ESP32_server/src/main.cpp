#include <main.h>
// Hạn chế đụng vào main.cpp nhé, chỉ dùng để gọi function hay khai báo pinmode thôi
//-------------------

void setup()
{
  Serial.begin(112500);
  setupWifi();
  Serial.println("Set Up Wifi Suscess!!!!!");
  CreateSetUpBLE();
  Serial.println("Set Up BlueTooth Suscess!!!!!");
}

void loop()
{
  // loopWifi();
  // loopBLE();
}
