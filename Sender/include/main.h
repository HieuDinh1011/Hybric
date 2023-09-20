#ifndef INC_DATA_H_
#define INC_DATA_H_
#include <esp_now.h>
#include <WiFi.h>
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
extern int int_value;
extern float float_value;
extern bool bool_value;
extern int LED_State_Send; //--> Variable to hold the data to be transmitted to control the LEDs on the paired ESP32.

extern int LED_State_Receive; //--> Variable to receive data to control the LEDs on the ESP32 running this code.
// MAC Address of responder - edit as required
extern uint8_t broadcastAddress[] ;


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
#endif 