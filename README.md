# mac-address-finder

Mac Address Finder 

## Introduction
This project was proposed by **Christina Webster**, who is a Technical Support Specialist, of ITS at Swarthmore College as part of the 2019 Swarthmore Projects for Educational Exploration & Development ([SPEED](https://www.swarthmore.edu/its/swarthmore-projects-educational-exploration-and-development-speed-program)) Program. The project is led by Anthony Weed of Swarthmore College, as well as **Steven Fernandez ('20)** and **Helen Huh ('21)**.

## Motivation
Often times, when using smart devices that don't have a browser or an operating system (i.e. smart lightbulbs), it can be difficult to connect to the Internet on which these devices depend on for use. Without a browser or an operating system, the MAC address of these types of smart devices cannot be easily identified. One way to connect to the Internet is using the device's unique MAC address. A media access control address [(MAC address)](https://en.wikipedia.org/wiki/MAC_address) of a device is a unique identifier assigned to a network interface controller [NIC](https://en.wikipedia.org/wiki/Network_interface_controller). Idenitfying a device's unique MAC address allows the device to be connected to the Internet. 

## Goals
We wanted to create a physical MAC address finder. The MAC address finder would act like a hotspot that devices would be able to connect to and would then display the device's MAC address. This physical MAC address finder encompassed the necessary code, electronics, hardware, and the case.

## Process Overview & Tools

We used a previously existing [project](https://learn.adafruit.com/mac-address-finder) as a guideline for our own project.

**Here are some of the parts required for this project:**

[ESP8266 Board](https://www.amazon.com/gp/product/B07L8W9SP3/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

[OLED Displays](https://www.amazon.com/gp/product/B0761LV1SD/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

[IRFD9024 Mosfet](https://www.vishay.com/docs/91137/sihfd902.pdf)

[Pin Diode]

[Adafruit Mini Lipo w/Mini-B USB Jack - USB LiIon/LiPoly charger - v1](https://www.adafruit.com/product/1905?gclid=Cj0KCQjwvo_qBRDQARIsAE-bsH__Asb4inO1-XE0V_F_KAbHImAmh22P0SS0DY36mvQU5T1CZnm-2j8aAr6FEALw_wcB)

(Any switch you want off amazon.)

**How to run this code:**

This code was pushed to a ESP8266 NodeMCU 12-E board via the Arduino IDE (version 1.8.9). It will turn any ESP8266 board its pushed into a mac-address-finder. The ESP8266 is configured as a soft access point. So, it will emit a wifi signal that devices can connect to. Once that device is connected to the board it will print the mac address to the OLED screen.

In order to push this code to a ESP8266 board it has to be uploaded to the board via the Arduino IDE.

[Instructions for Linux](https://www.arduino.cc/en/Guide/Linux#toc4)

[Instructions for Windows](https://www.arduino.cc/en/Guide/Windows)

[Instructions for Mac](https://www.arduino.cc/en/Guide/MacOSX)

After installing the Arduino IDE. The board has to be connected to your computer via micro-USB. The boards options have to be configured. Make sure that these options are set:

Set up your chip as:
* Tools -> Board -> NodeMCU 1.0 (ESP-12E Module)
* Tools -> Flash Size -> 4M (3M SPIFFS)
* Tools -> CPU Frequency -> 80 Mhz
* Tools -> Upload Speed -> 115200
* Tools-->Port--> (whatever port the board is mounted on for me it was /dev/sdX <-- X will be different for you.

Open the serial monitor (ctrl+shift+m). This allows you to see the output that the board is printing. If you don't see any output or get garbage make sure that your upload speed and baud rate are the same. You can change the baud rate after opening the serial monitor it should be at the bottom of the serial monitors window.

**Case**

The case needed three openings (one for the switch, one for the battery charger's port, and one for the screen), a holder for the rechargable battery, and a holder for the main board. We used Rhinoceros as our 3D modeling software to create the case. Our final prototype was 3D printed using a Markforged Onyx Series 3D printer with a black nylon material. The file containing the model for the case can be found in the repository. 

**Assembly**
The cicruit for this board was built using this schematic:

[Circuit Image](charger circuit.png)


## Future Extensions

If any enhancements or changes need to be made for the MAC address finder, the board allows for new or modified code to be uploaded onto the device. Additionally, the case may need a form of hinge and latch combination in order for the MAC address finder to be opened and closed securely and with more ease. 

## Acknowledgements

We would like to thank Christina for proposing the MAC address finder project in order to help all faculty, staff, and students in their daily lives. It has taught us the benefits of being creative in our problem-solving and how it can be applied to addressing the campus' needs.

We are incredibly grateful to our project supervisors, **Anthony Weed** and **Nabil Kashyap**, our SPEED program supervisor, **Doug Willen**, and project contributor, **Andrew Ruether**, for their constant support, helping hands, and considerate insight. All provided us with their own expertise and encouragement as we learned how to navigate through assemblying electronics hardware and 3D design. Thank you also to the Swarthmore College Librarians and ITS for all their support behind the scenes through the whole process.

Additionally, we would like to thank all of our fellow SPEED members, **Alice Huang ('22)**, **Bilal Soukouna ('22)**, and **Katie Knox ('21)**, for providing us with supportive feedback and constant support during the duration of this project. Lastly, thank you to **Eva Low '22** from the Makerspace who helped us design, prepare, and print out our final product.

This project was funded by the Swarthmore Projects for Educational Exploration and Development (SPEED) Program at Swarthmore College.
