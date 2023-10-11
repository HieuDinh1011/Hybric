#ifndef INC_BLECLIENT_H_
#define INC_BLECLIENT_H_

#include "BLEDevice.h"
// #include "BLEScan.h"
#include "main.h"
// Define UUIDs:
static BLEUUID serviceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
static BLEUUID charUUID_1("beb5483e-36e1-4688-b7f5-ea07361b26a8");
static BLEUUID charUUID_2("1c95d5e3-d8f7-413a-bf3d-7a2e5d7be87e");

// Callback function for Notify function
static void notifyCallback(BLERemoteCharacteristic *pBLERemoteCharacteristic,
                           uint8_t *pData,
                           size_t length,
                           bool isNotify);

// Function that is run whenever the server is connected
bool connectToServer();

// Function to check Characteristic
bool connectCharacteristic(BLERemoteService *pRemoteService, BLERemoteCharacteristic *l_BLERemoteChar);

void BLE_setUpConnect();

void BLE_loopClientBLE();

#endif