# 433MHz Receiver Log with NodeMCU

This repository contains a code snippet for creating a simple web server using NodeMCU (ESP8266) to log and display messages received from a 433MHz receiver.

![Preview](/.docs/preview.png)

## Prerequisites

- NodeMCU board (ESP8266-based)
- Arduino IDE or compatible development environment
- `ESP8266WiFi` library
- `ESP8266WebServer` library
- `RCSwitch` library

## Wiring Diagram

| NodeMCU | 433MHz Receiver |
|---------|-----------------|
| D2      | Data Pin        |
| 3.3V    | VCC             |
| GND     | GND             |

## Getting Started

1. Clone or download this repository.

2. Open the `433MHz_Receiver_Log.ino` file in the Arduino IDE.

3. Install the required libraries:
   - `ESP8266WiFi`: Install via Arduino Library Manager.
   - `ESP8266WebServer`: Install via Arduino Library Manager.
   - `RCSwitch`: Download the library from https://github.com/sui77/rc-switch and install manually.

4. Connect your NodeMCU board to your computer.

5. Set the Wi-Fi credentials:
   - Update the `ssid` and `password` variables in the code with your desired SSID and password for the Wi-Fi hotspot (default `443` and `adminadmin`)

6. Upload the code to your NodeMCU board.

7. Open the Arduino IDE serial monitor to view the IP address assigned to the Wi-Fi hotspot.

8. Connect to the Wi-Fi hotspot using the provided SSID and password.

9. Open a web browser and enter the IP address displayed in the serial monitor.

10. The web page will display the received messages, including the decimal and binary representation of each value.

## Customize

- If you want to change the pin for the 433MHz receiver, modify the `receiverPin` constant in the code. By default, it is set to `D2` on the NodeMCU board.

## License

This code is licensed under the MIT License.

