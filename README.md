# ESP32-WROOM-32-Basics
Repository to group all the basics information towards the mission of mastering the ESP32.

# Goals

- [ ] 1. Buy/ Install Espressif IDF/ Test/
- [x] 2. 
- [x] 3. 
- [x] 4. 

# Hardware

[TBW]

# ESP-IDF 5.1 CMD

* First we go to a project folder by typing its path ```cd examples\get-started\blink```.
* Then we compile the code ```idf.py build```. First time it happens it takes a lot of time.
* Connect the ESP32-WROOM-32 board to one of the USBs. Check in the Computer Management board the in which COM the board is connected.
* At last we send a command to program the microcontroller by ```idf.py -p COM4 flash```.

It returned me a few information of the board:

* Chip is ESP32-D0WD-V3 (revision v3.0)
* Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
* Crystal is 40MHz
* MAC: 48:e7:29:ca:f9:78

It didn't blink the LED, probably because the PIN isn't configured corrected. In any moment we choose the model of the development board or any other important information. Let's do something about it.
We go to the blink code, open by using a text editor e changed the pin to 2.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/0879c341-9189-4f2c-8204-9b11a4969e58)

Then we go through all the steps again. The results:

![WhatsApp Video 2023-10-28 at 16 37 20](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/f994becf-a74a-4b49-aafb-fe4ee690e5a8)

# Eclipse

To use the Eclipse IDE, we follow the [Eclipse setup setup for Windows from Espressif documentation](https://docs.espressif.com/projects/esp-idf/en/release-v3.0/get-started/eclipse-setup-windows.html#eclipse-windows-setup). Basically we need:

* [Download](https://www.eclipse.org/downloads/) and install the Eclipse IDE. The installation must be set to **Eclipse IDE for C/C++ Developers** and not the ~~Eclipse IDE for Embedded C/C++ Developers~~, as showed next.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/32974188-a281-4f9a-a14d-9a18fb5bde30)

* After installation is completed, Open the Eclipse IDE and go to File -> Import. Then go to C/C++ and select 'Existing Code as Makefile Project'. 

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/9ac7e297-b7b2-425a-a94e-9cf80912007e)

* In the next page, we set the path for the example code, then **uncheck** “Show only available toolchains that support this platform”. On the extended list that appears, wee choose “Cygwin GCC” and click Finish.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/54d3660a-3aca-416a-bf38-b29034b1696a)

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/3214169e-9305-4a4e-a39c-d8d775a8b944)

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/69f6c867-367f-44c4-b675-38c72d765e45)


we’re going to reconfigure Eclipse to find our toolchain

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/b60d76a9-9f4b-4721-8259-7470a78307d7)

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/4e512656-7454-4a8a-b8ff-5262b6a169e2)


