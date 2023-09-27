#include <main.h>
//Hạn chế đụng vào main.cpp nhé, chỉ dùng để gọi function hay khai báo pinmode thôi 

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  BLE_setUpConnect();
}
void loop() {
  BLE_loopClientBLE();
}
