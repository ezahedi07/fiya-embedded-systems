# Embedded Systems Team Null 
#### Hardware used: ESP32
#### IDE: Sloeber

### Current Functionality:
- RGB LED pin set and outputted red, green amber values
- Button debouncing
- PIR sensor value to identify if room is VACANT or OCCUPIED,
- DHT sensor value to change LED states/outputs
- Write to volatile memory with the preferences library
- Debug string outputting
	- Humidity
	- Temperature
	- LED State
	- PIR State
	- Interval
	- Time from system boot
- SYSTEM_READY checks now in place 
- Button can identify between short and long presses
	- Long button press for changing interval timer
	- Short button press being read
- Interval timer changes rate at which latest reading is stored to volatile memory 

> V0.3
