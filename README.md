# mac-address-finder
Hardware mac address finder project

[Mac Address Finder project](https://learn.adafruit.com/mac-address-finder)

Here are some of the parts required for this project:

[ESP8266 Board](https://www.amazon.com/gp/product/B07L8W9SP3/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

[OLED Displays](https://www.amazon.com/gp/product/B0761LV1SD/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

## How to run this code:
A media access control address [MAC address](https://en.wikipedia.org/wiki/MAC_address) of a device is a unique identifier assigned to a network interface controller [NIC](https://en.wikipedia.org/wiki/Network_interface_controller).

This code was pushed to a ESP8266 NodeMCU 12-E board via the Arduino IDE (version 1.8.9). It will turn any ESP8266 board its pushed into a mac-address-finder. The ESP8266 is configured as a soft access point. So, it will emit a wifi signal that devices can connect to. Once that device is connected to the board it will print the mac address to the OLED screen.

In order to push this code to a ESP8266 board it has to be uploaded to the board via the Arduino IDE.

[Instructions for Linux](https://www.arduino.cc/en/Guide/Linux#toc4)

[Instructions for Windows] (https://www.arduino.cc/en/Guide/Windows)

[Instructions for Mac] (https://www.arduino.cc/en/Guide/MacOSX)

After installing the Arduino IDE. The board has to be connected to your computer via micro-USB. The boards options have to be configured. Make sure that these options are set:

Set up your chip as:
Tools -> Board -> NodeMCU 1.0 (ESP-12E Module)
Tools -> Flash Size -> 4M (3M SPIFFS)
Tools -> CPU Frequency -> 80 Mhz
Tools -> Upload Speed -> 921600
Tools-->Port--> (whatever port the board is mounted on for me it was /dev/sdX <-- X will be different for you.

Open the serial monitor (ctrl+shift+m). This allows you to see the output that the board is printing. If you don't see any output or get garbage make sure that your upload speed and baud rate are the same. You can change the baud rate after opening the serial monitor it should be at the bottom of the serial monitors window.
