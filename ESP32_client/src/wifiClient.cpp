#include <wifiClient.h>
#include <main.h>
#include <Arduino.h>
const char *ssid = "vinh";                 // Thay thế bằng tên SSID của mạng Wi-Fi
const char *password = "88888888";         // Thay thế bằng mật khẩu của mạng Wi-Fi
const char *serverAddress = "192.168.1.1"; // Thay thế bằng địa chỉ IP của ESP32 #1
const int serverPort = 8888;               // Cổng kết nối
WiFiClient client;

int lastState;          // the previous state from the input pin
int currentState = LOW; // the current reading from the input pin
char isTurnon = '0';
void Wifi_setupConnection()
{

  // Kết nối đến mạng Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  // Kết nối đến máy chủ (ESP32 #1)
  if (client.connect(serverAddress, serverPort))
  {
    Serial.println("Connected to server");
  }
  else
  {
    Serial.println("Connection to server failed");
  }
}

void Wifi_setupSignalConnection()
{
  // Gửi dữ liệu đến máy chủ và đọc phản hồi từ máy chủ
  if (client.connected())
  {
    // client.println("Hello from ESP32 #2");
    delay(1000);
    if (lastState == HIGH && currentState == LOW)
    {
      digitalWrite(led, !digitalRead(led));
      Serial.println("The button is pressed");
      if (isTurnon == '0')
        isTurnon = '1';
      else if (isTurnon == '1')
        isTurnon = '0';
      client.write(isTurnon);
    }
    else if (lastState == LOW && currentState == HIGH)
    {
      Serial.println("The button is released");
    }
    lastState = currentState;
    while (client.available())
    {
      String response = client.readStringUntil('\n');
      Serial.println("Received: " + response);
    }
  }
  else
  {
    Serial.println("Server disconnected");
    client.stop();
    delay(1000);

    // Thử kết nối lại
    if (client.connect(serverAddress, serverPort))
    {
      Serial.println("Reconnected to server");
    }
    else
    {
      Serial.println("Reconnection to server failed");
    }
  }
  currentState = digitalRead(BUTTON_PIN);
}