#ifndef INC_WIFICLIENT_H_
#define INC_WIFICLIENT_H_
#include <WiFi.h>

extern int lastState ;  // the previous state from the input pin
extern int currentState;     // the current reading from the input pin
extern char isTurnon ;

extern const char* ssid ;     // Thay thế bằng tên SSID của mạng Wi-Fi
extern const char* password ; // Thay thế bằng mật khẩu của mạng Wi-Fi
extern const char* serverAddress ; // Thay thế bằng địa chỉ IP của ESP32 #1
extern const int serverPort; // Cổng kết nối

extern WiFiClient client;

void Wifi_setupConnection();
void Wifi_setupSignalConnection();
#endif