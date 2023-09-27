 #include <main.h>
 const char* ssid = "vinh";     // Thay thế bằng tên SSID của mạng Wi-Fi
 const char* password = "88888888"; // Thay thế bằng mật khẩu của mạng Wi-Fi
 const int serverPort = 8888; // Cổng để lắng nghe kết nối

 IPAddress IP(192, 168, 1, 1);
 IPAddress gateway(192, 168, 1, 1);
 IPAddress subnet(255, 255, 255, 0);
 WiFiServer server(serverPort); // Tạo một máy chủ Wi-Fi

void setupWifi(){
    Serial.print("Setting up Access Point ... ");
  Serial.println(WiFi.softAPConfig(IP, gateway, subnet) ? "Ready" : "Failed!");
    pinMode(LED_PIN, OUTPUT);

  Serial.print("Starting Access Point ... ");
  Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");

  Serial.print("IP address = ");
  Serial.println(WiFi.softAPIP());
  
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void loopWifi(){
    // Chờ kết nối từ máy khách
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Client connected");

    // Đọc dữ liệu từ máy khách và hiển thị trên Serial Monitor
    while (client.connected()) {
      if (client.available()) {
        // String data = client.readStringUntil('\n');
        // Serial.println("Received: " + data);

        // // Phản hồi lại cho máy khách
        // client.println("Hello from ESP32 #1: " + data);
        char command = client.read();
        Serial.print("ESP32 #2: - Received command: ");
        Serial.println(command);

        if (command == '1')
          digitalWrite(LED_PIN, HIGH); // Turn LED on
        else if (command == '0')
          digitalWrite(LED_PIN, LOW);  // Turn LED off
        }     
    }

    // Đóng kết nối khi máy khách ngắt kết nối
    client.stop();
    Serial.println("Client disconnected");
  }
}