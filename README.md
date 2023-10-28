# ESP32-WROOM-32-Basics
Repository to group all the basics information towards the mission of mastering the ESP32.

# Goals

- [ ] 1. Buy/ Install Espressif IDF/ Test/
- [x] 2. 
- [x] 3. 
- [x] 4. 

# Hardware

[TBW]

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

