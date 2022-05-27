# Micro Controller Hello World
Small project to get some code running on the Heltec WifiKit 8 (easily adapted to another esp8266 based device, as long as there is a screen attached).

This code is based on the source written for the 2018 Area41 Security Conference Badge and will do nothing more than display a helix on the screen. Nicely animated with 

## Howto
### Preparation
Initialise the project. 

Important:
- If you pulled this repo, already done, won't be needed anymore
- If you use another IDE, either remove or replace the --ide param

> pio project init --board heltec_wifi_kit_8 --ide clion 

To use CLion as an IDE, or when things wont work as expected, (re-)run this command. Sometimes the IDE gets confused by PlatformIO and needs its config to be re-initialised.

> pio project init --ide clion

### Having fun
To update middleware

> pio update

To compile

> pio run

To upload to the device (attached via USB)

> pio run -t upload

To start the serial monitor

> pio device monitor

## What to look into after things compile and run
- Have a look at the platformio.ini to see some special configuration like monitor_speed and build_flags.
- Can you change speed?
- Can you show more, less discs?
- Can you stop and start the animation using a button?
- 