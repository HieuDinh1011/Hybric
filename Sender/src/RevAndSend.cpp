#include "RevAndSend.h"
#include "main.h"
// Create a structured object
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

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
