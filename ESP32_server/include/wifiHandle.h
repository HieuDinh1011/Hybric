#ifndef INC_WIFIHANDLE_H_
#define INC_WIFIHANDLE_H_
#include <WiFi.h>

extern const char* ssid ;     // Thay thế bằng tên SSID của mạng Wi-Fi
extern const char* password ; // Thay thế bằng mật khẩu của mạng Wi-Fi
extern const int serverPort; // Cổng để lắng nghe kết nối

void setupWifi();
void loopWifi();
#endif 
