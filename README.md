# ESP32-WROOM-32-Basics
Repository to group all the basics information towards the mission of mastering the ESP32.

# Goals

- [ ] 1. Buy/ Install Espressif IDF/ Test/
- [x] 2. 
- [x] 3. 
- [x] 4. 

# Hardware

I bought 5 ESP32-WROOM-32 from [ML](https://produto.mercadolivre.com.br/MLB-2965077293-kit-com-5-un-esp32-doit-devkit-com-esp32-wroom-32-_JM#is_advertising=true&position=2&search_layout=grid&type=pad&tracking_id=46f1bd68-82e7-451e-a4d9-a6f2c1ea48af&is_advertising=true&ad_domain=VQCATCORE_LST&ad_position=2&ad_click_id=NjlhNzU5MjUtMGNlNi00OTU2LTkxOTUtYjM4MjZjNmI5Zjcw).

ESP32 DEVKITV1 is equivalent to NodeMCU-32S. The USB driver depends on the Bridge (CI) used. There is CP210x, CH340. Mine is CH9102x.

## ESP32 DEVKITV1 Pinout

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/db79070c-5c90-4e5f-8d61-16d919c0a863)

Image from [RandomNerdTutorials](https://randomnerdtutorials.com/esp32-doit-devkit-v1-board-pinout-30-gpios-copy/).

## ESP32-D0WD-V3

* Wi-Fi
  - 802.11b/g/n
  - 802.11n (2.4 GHz), up to 150 Mbps
* Bluetooth®
  - Compliant with Bluetooth v4.2 BR/EDR and Bluetooth LE specifications
* Core
  - Xtensa® single-/dual-core 32-bit LX6 microprocessor(s)
  - CoreMark® score:
    - 1 core at 240 MHz: 504.85 CoreMark; 2.10 CoreMark/MHz
    - 2 cores at 240 MHz: 994.26 CoreMark; 4.14 CoreMark/MHz
  - 448 KB ROM
  - 520 KB SRAM
  - 16 KB SRAM in RTC
  - QSPI supports multiple flash/SRAM chips
* Clocks
  - Internal 8 MHz oscillator with calibration
  - Internal RC oscillator with calibration
  - External 2 MHz ~ 60 MHz crystal oscillator (40 MHz only for Wi-Fi/Bluetooth functionality)
  - External 32 kHz crystal oscillator for RTC with calibration
* Advanced Peripheral Interfaces
  - 34 × programmable GPIOs
    - 5 strapping GPIOs
    - 6 input-only GPIOs
    - 6 GPIOs needed for in-package flash/PSRAM (ESP32-D0WDR2-V3, ESP32-U4WDH)
  - 12-bit SAR ADC up to 18 channels
  - 2 × 8-bit DAC
  - 10 × touch sensors
  - 4 × SPI
  - 2 × I2S
  - 2 × I2C
  - 3 × UART
  - Motor PWM
  - LED PWM up to 16 channels
* Security
  - Secure boot
  - Flash encryption
  - 1024-bit OTP, up to 768-bit for customers
  - Cryptographic hardware acceleration:
    - AES
    - Hash (SHA-2)
    - RSA
    - ECC
    - Random Number Generator (RNG)

# ESP-IDF 5.1 CMD

* First we go to a project folder by typing its path ```cd examples\get-started\blink```.
* Then we compile the code ```idf.py build```. First time it happens it takes a lot of time.
* Connect the ESP32-WROOM-32 board to one of the USBs. Check in the Computer Management board the in which COM the board is connected.
* At last we send a command to program the microcontroller by ```idf.py -p COM4 flash```.

It returned me a few information of the board:

* Chip is [ESP32-D0WD-V3 (revision v3.0)](https://www.espressif.com/sites/default/files/documentation/esp32-s2_datasheet_en.pdf).
* Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
* Crystal is 40MHz
* MAC: 48:e7:29:ca:f9:78

It didn't blink the LED, probably because the PIN isn't configured corrected. In any moment we choose the model of the development board or any other important information. Let's do something about it.
We go to the blink code, open by using a text editor e changed the pin to 2.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/0879c341-9189-4f2c-8204-9b11a4969e58)

Then we go through all the steps again. The results:

![WhatsApp Video 2023-10-28 at 16 37 20](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/f994becf-a74a-4b49-aafb-fe4ee690e5a8)

Note: To have access to the Espressif IDE, during installation tick the option Espressif-IDE during the Select Components window:

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/8d153378-0724-4931-8f08-48574897612b)

# Visual Studio Code

I found a lot of throuble by trying to set the Eclipse IDE, so I decided to configure the VSCode first. I had the impression that nowdays the Eclipse hasn't the required suport.

* Download and install the [VS Code](https://code.visualstudio.com/docs/).
* Configure the extensions. I installed the **Python**, **C/C++**, **Shortcut Menu Bar** and **PlatformIO**.
* Let's open a project by: File -> Open Folder... -> 'C:\Espressif\frameworks\esp-idf-v5.1.1\examples\get-started\blink'.
* Before compiling or anything we need to save the workspace: File -> Save Workspace As... -> blink.code-workspace -> Save (inside the blink folder).

We need to configure the terminal now. For that, we followed [this tutorial](https://www.youtube.com/watch?v=N93RvZz6dEc).

* Press F1 and search for the **settings.json** (choose the User settings).
* Add the line ```"terminal.integrated.defaultProfile.windows": "Command Prompt",```.
* Then also add: ```"terminal.integrated.profiles.windows": {``` and press TAB so it will auto complete itself.
* Add the following lines:

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/a736d434-f51b-41d3-8840-ef5b5b57ea09)

* The second argument is the address for the **idf_cmd_init.bat**, inside the Espressif folder (with the inverted slashes /) plus, the code found in the Properties of the **ESP-IDF 5.1 CMD** desktop shortcut icon.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/ca0deb7f-503b-4568-bb38-82b9f137d070)

* Save and close the **settings.json** TAB.
* Let's open the terminal by going to: Terminal -> New Terminal.
* Type ```idf.py build``` to build.
* Type ```idf.py -p COM4 flash``` to programn the ESP-WROOM-32 board.

## Creating a new project
Now we need to configure the C/C++ paths for the includes.

* Click to Edit "includePath" setting.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/1d5f5832-6e6b-4d12-a3d2-283deb541126)

* Once the option for Edit "includePath" setting is selected. It will appear a few options on the project tree. Go to '.vscode' -> 'c_cpp_properties.json' and add the Espressif path to the includePath.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/051bc2d4-4812-430f-9f13-69e946a56276)


This repository will contain a template file.

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


