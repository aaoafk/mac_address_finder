#include <WiFiClientSecureBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <BearSSLHelpers.h>
#include <WiFiServerSecureBearSSL.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiGeneric.h>
#include <WiFiClientSecure.h>
#include <ESP8266WiFiMulti.h>
#include <CertStoreBearSSL.h>
#include <WiFiUdp.h>
#include <ESP8266WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiClient.h>
#include <WiFiServerSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <ESP8266WiFiType.h>
#include <SPI.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/* configuration  wifi */
const char *ssid = "MAC_ADDRESS_FINDERv0.1";
 
void setup() {

  //Initialize Serial port
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  //Always begin with display.clearDisplay() to make sure things actually print to our display
  display.display();
  delay(2000);
  
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("Configuring Access Point"));
  display.display();
  delay(2000);
  
  WiFi.softAP(ssid);
  
  IPAddress myIP = WiFi.softAPIP();
  
  Serial.print("AP IP address: ");
  Serial.println(myIP);
}
 
void loop() {
  delay(2000); //wait 2 seconds
  client_status();
}

void client_status() {
 
  unsigned char number_client;
  
  struct ip_addr *IPaddress;
  IPAddress address;
  int i=1;
  
  Serial.println("-------------Connected Clients List-----------------------");
  Serial.print(wifi_softap_get_station_num()); Serial.println(" clients.");
  
  struct station_info *station_list = wifi_softap_get_station_info();
  while (station_list != NULL) 
  {
    char station_mac[18] = {0}; sprintf(station_mac, "%02X:%02X:%02X:%02X:%02X:%02X", MAC2STR(station_list->bssid));
    String station_ip = IPAddress((&station_list->ip)->addr).toString();

    display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(0,16);             // Start at top-left corner
    display.println(station_mac);
    display.display();
    delay(2000);
    
    Serial.print(station_mac); Serial.print(" "); Serial.println(station_ip);
    
    station_list = STAILQ_NEXT(station_list, next);
  }
  wifi_softap_free_station_info();
  Serial.println();
    
  delay(500);
}
