/*
  ESP-NOW Demo - Transmit
  esp-now-demo-xmit.ino
  Sends data to Responder
  
  DroneBot Workshop 2022
  https://dronebotworkshop.com
*/

// Include Libraries
#include <esp_now.h>
#include <WiFi.h>
#include "main.h"
#include "RevAndSend.h"
#include "input_reading.h"


void setup() {
  
  // Set up Serial Monitor
  Serial.begin(115200);
  pinMode(BTN_Pin1,INPUT_PULLUP);
  pinMode(LED_Pin,OUTPUT);

  // Set ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Initilize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register the send callback
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
bool isLightOn = false;  // Trạng thái đèn

void loop() {

  // Create test data

  // // Generate a random integer
  // int_value = random(1,20);

  // // Use integer to make a new float
  // float_value = 1.3 * int_value;

  // // Invert the boolean value
  // bool_value = !bool_value;
  
  // Format structured data
  //strcpy(myData.a, "Welcome to the Workshop!");
  // myData.b = int_value;
  // myData.c = float_value;
  // myData.d = bool_value;
  myData.BUTTON_STATUS = digitalRead(BTN_Pin1);
  bool buttonState = digitalRead(BTN_Pin1);

  // Kiểm tra nếu nút bấm được nhấn (được kết nối đất)
  if (buttonState == LOW) {
    // Đảo trạng thái đèn (bật/tắt)
    isLightOn = !isLightOn;

    // Điều khiển đèn dựa trên trạng thái mới
    digitalWrite(LED_Pin, isLightOn ? HIGH : LOW);
    
    // Đợi một lúc để tránh đọc liên tục khi nút bấm được giữ
    delay(250);
  }
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sending confirmed");
  }
  else {
    Serial.println("Sending error");
  }
  delay(250);
}