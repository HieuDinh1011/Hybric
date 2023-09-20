#include <Arduino.h>
#include <WiFi.h>

#define WIFI_SSID "Vinh"
#define WIFI_PASSWORD "88888888"
const int RED_LED = 0;
const int BUTTON = 2;
void setup() {
 Serial.begin(112500);
  //pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);  
  pinMode(BUTTON,INPUT_PULLUP);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  digitalWrite(RED_LED,HIGH);

  Serial.println("starting");
}
bool isLightOn = false;  // Trạng thái đèn

void buttonHandle(){
  int isPressed = digitalRead(BUTTON);
  int status = 0;
  switch (status)
  {
  case 0:
    digitalWrite(RED_LED,LOW);
    if(isPressed==1){status = 1;break;}
    break;
  case 1:
    digitalWrite(RED_LED,HIGH);
    if(isPressed==1){status = 0;break;}
    break;
  default:
    break;
  }
}
void loop() {
  bool buttonState = digitalRead(BUTTON);

  // Kiểm tra nếu nút bấm được nhấn (được kết nối đất)
  if (buttonState == LOW) {
    // Đảo trạng thái đèn (bật/tắt)
    isLightOn = !isLightOn;

    // Điều khiển đèn dựa trên trạng thái mới
    digitalWrite(RED_LED, isLightOn ? HIGH : LOW);
    
    // Đợi một lúc để tránh đọc liên tục khi nút bấm được giữ
    delay(10);
  }
}