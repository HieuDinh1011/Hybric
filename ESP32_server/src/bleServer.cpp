#include <bleServer.h>

BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristic_1 = NULL;
BLECharacteristic *pCharacteristic_2 = NULL;
BLEDescriptor *pDescr_1;
BLE2902 *pBLE2902_1;
BLE2902 *pBLE2902_2;

bool deviceConnected = false;
bool oldDeviceConnected = false;
uint32_t value = 0;

class MyServerCallbacks : public BLEServerCallbacks
{
  void onConnect(BLEServer *pServer)
  {
    deviceConnected = true;
  };

  void onDisconnect(BLEServer *pServer)
  {
    deviceConnected = false;
  }
};

void CreateSetUpBLE()
{
  Serial.begin(115200);

  // Create the BLE Device
  BLEDevice::init("ESP32");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic_1 = pService->createCharacteristic(
      CHARACTERISTIC_UUID_1,
      BLECharacteristic::PROPERTY_NOTIFY);

  pCharacteristic_2 = pService->createCharacteristic(
      CHARACTERISTIC_UUID_2,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE |
          BLECharacteristic::PROPERTY_NOTIFY);

  // Create a BLE Descriptor
  pDescr_1 = new BLEDescriptor((uint16_t)0x2901);
  pDescr_1->setValue("A very interesting variable");
  pCharacteristic_1->addDescriptor(pDescr_1);

  // Add the BLE2902 Descriptor because we are using "PROPERTY_NOTIFY"
  pBLE2902_1 = new BLE2902();
  pBLE2902_1->setNotifications(true);
  pCharacteristic_1->addDescriptor(pBLE2902_1);

  pBLE2902_2 = new BLE2902();
  pBLE2902_2->setNotifications(true);
  pCharacteristic_2->addDescriptor(pBLE2902_2);

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0); // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting a client connection to notify...");
}

void loopBLE()
{
  if (deviceConnected)
  {
    pCharacteristic_1->setValue(value);
    pCharacteristic_1->notify();
    value++;

    std::string rxValue = pCharacteristic_2->getValue();
    Serial.print("Characteristic 2 (getValue): ");
    Serial.println(rxValue.c_str());

    String txValue = "String with random value from Server: " + String(random(1000));
    pCharacteristic_2->setValue(txValue.c_str());
    Serial.println("Characteristic 2 (setValue): " + txValue);

    delay(1000);
  }
  if (!deviceConnected && oldDeviceConnected)
  {
    delay(500);
    pServer->startAdvertising();
    Serial.println("start advertising");
    oldDeviceConnected = deviceConnected;
  }
  if (deviceConnected && !oldDeviceConnected)
  {
    // do stuff here on connecting
    oldDeviceConnected = deviceConnected;
  }
}