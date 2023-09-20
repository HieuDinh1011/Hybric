
// // Include Libraries
#include <esp_now.h>
#include <WiFi.h>
int LED_State_Receive; //--> Variable to receive data to control the LEDs on the ESP32 running this code.
int BUTTON_Receive; //--> Variable to receive data to control the LEDs on the ESP32 running this code.
const int LED_Pin= 2;

// Define a data structure
typedef struct struct_message {
 // int LED_State_Receive;
  int BUTTON_Receive;
} struct_message;

// Create a structured object
struct_message myData;
bool isLightOn = false; 
// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin

// Callback function executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Data received: ");
  Serial.println();
  currentState = myData.BUTTON_Receive;
    Serial.print("State BUtton received: ");

  Serial.println(BUTTON_Receive);
    Serial.print("State Light received: ");
  Serial.println("<<<<<");
 if (lastState == HIGH && currentState == LOW){
    isLightOn = !isLightOn;

    // Điều khiển đèn dựa trên trạng thái mới
    digitalWrite(LED_Pin, isLightOn ? HIGH : LOW);
    Serial.println("The button is pressed");}
  else if (lastState == LOW && currentState == HIGH)
    Serial.println("The button is released");

  // save the the last state
  lastState = currentState;


}
void setup() {
  // Set up Serial Monitor
  Serial.begin(115200);
  
  // Set ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  pinMode(LED_Pin, OUTPUT);  

  // Initilize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Register callback function
  esp_now_register_recv_cb(OnDataRecv);
}
  // Trạng thái đèn

void loop() {

  // Kiểm tra nếu nút bấm được nhấn (được kết nối đất)
 
    // Điều khiển đèn dựa trên trạng thái mới
   // digitalWrite(LED_Pin, isLightOn ? HIGH : LOW);
    
    // Đợi một lúc để tránh đọc liên tục khi nút bấm được giữ

}

// void setup() {
//  Serial.begin(112500);
//   //pinMode(GREEN_LED, OUTPUT);
//   pinMode(LED_Pin, OUTPUT);  
//   //pinMode(BUTTON,INPUT_PULLUP);
  
//   digitalWrite(LED_Pin,HIGH);

//   Serial.println("starting");
// }
// bool isLightOn = false;  // Trạng thái đèn



// void loop() {
//   digitalWrite(LED_Pin,HIGH);
//   delay(1000);
//   digitalWrite(LED_Pin,LOW);
//   delay(1000);
// }