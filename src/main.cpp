#include <Arduino.h>
#include <SPIFFS.h>

void setup() {
  Serial.begin(115200);
  

  if (!SPIFFS.begin(true)) {  
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

 
  File file = SPIFFS.open("/texto.txt", "r");
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  } else {
    Serial.println("File opened successfully");
  }

  Serial.print("File size: ");
  Serial.println(file.size());

  
  Serial.println("File Content (hexadecimal):");
  while (file.available()) {
    uint8_t byte = file.read();
    Serial.printf("%02X ", byte);
  }
  Serial.println(); 
  file.close();
}
 
void loop() {
  
}
