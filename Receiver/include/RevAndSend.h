#ifndef INC_REVANDSEND_H_
#define INC_REVANDSEND_H_
#include <esp_now.h>
#include <WiFi.h>
#include "main.h"
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
#endif 