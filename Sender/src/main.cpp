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
//----------------------------------------Variables to accommodate the data to be sent.
#define CONNECT_SUSCESS 1
#define CONNECT_FAIL 2
#define LED_Pin   0
#define BTN_Pin1   2
#define BTN_Pin2  3
#define BTN_Pin3   4

// //----------------------------------------Wifi Setting
#define WIFI_SSID "Vinh"
#define WIFI_PASSWORD "88888888"
// Variables for test data

extern int LED_State_Send; //--> Variable to hold the data to be transmitted to control the LEDs on the paired ESP32.

extern int LED_State_Receive; //--> Variable to receive data to control the LEDs on the ESP32 running this code.
// MAC Address of responder - edit as required


// Define a data structure
 struct struct_message {
  // char a[32];
  // int b;
  // float c;
  // bool d;
  int BUTTON_STATUS;
} ;

// Create a structured object
extern struct_message myData;

// Peer info
extern esp_now_peer_info_t peerInfo;
struct_message myData;
uint8_t broadcastAddress[] = {0xC4, 0xDE, 0xE2, 0x1F, 0x3D, 0x0C};
esp_now_peer_info_t peerInfo;
int int_value;
float float_value;
bool bool_value = true;
// Callback function called when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

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