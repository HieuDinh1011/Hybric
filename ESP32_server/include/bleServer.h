#ifndef INC_BLECLIENT_H
#define INC_BLECLIENT_H
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <main.h>

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_1 "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define CHARACTERISTIC_UUID_2 "1c95d5e3-d8f7-413a-bf3d-7a2e5d7be87e"

extern BLEServer *pServer;
extern BLECharacteristic *pCharacteristic_1;
extern BLECharacteristic *pCharacteristic_2;
extern BLEDescriptor *pDescr;
extern BLE2902 *pBLE2902_1;
extern BLE2902 *pBLE2902_2;

extern bool deviceConnected;
extern bool oldDeviceConnected;
extern uint32_t value;

void CreateSetUpBLE();
void loopBLE();
#endif
