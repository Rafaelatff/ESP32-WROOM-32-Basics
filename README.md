# ESP32-WROOM-32-Basics
Repository to group all the basics information towards the mission of mastering the ESP32.

# Goals

- [x] 1. Buy/ Test modules / Rate on ML.
- [x] 2. Create and documentate configuration on Visual Studio Code.
- [ ] 3. Create and documentate configuration on Espressif IDE.
- [x] 4. Repositorie for [LOG and timmed funcions, ](https://github.com/Rafaelatff/ESP32-WROOM-32-ESP_LOG).
- [ ] 5. Repositorie for [Digital Input, Digital Output, Analog Input and PWM Output](https://github.com/Rafaelatff/ESP32-WROOM-32-DIG_AN_IO).
- [x] 6. Repositorie for [ESP-NOW protocol](https://github.com/Rafaelatff/ESP32-WROOM-32-ESP-NOW).
- [x] 7. Repositorie for [Another ESP-NOW example](https://github.com/Rafaelatff/ESP32-ESPNOW-EXAMPLE-2).
- [ ] 8. Mesh network?
- [ ] 9. other stuff?
- [ ] 10. Repositorie for [ESP IZ POC](https://github.com/Rafaelatff/ESP32-IZ-POC).
- [ ] 11. Repositorie for [TBC].

# Hardware

I bought 5 ESP32-WROOM-32 from [ML](https://produto.mercadolivre.com.br/MLB-2965077293-kit-com-5-un-esp32-doit-devkit-com-esp32-wroom-32-_JM#is_advertising=true&position=2&search_layout=grid&type=pad&tracking_id=46f1bd68-82e7-451e-a4d9-a6f2c1ea48af&is_advertising=true&ad_domain=VQCATCORE_LST&ad_position=2&ad_click_id=NjlhNzU5MjUtMGNlNi00OTU2LTkxOTUtYjM4MjZjNmI5Zjcw).

ESP32 DEVKITV1 is equivalent to NodeMCU-32S. The USB driver depends on the Bridge (CI) used. There is CP210x, CH340. Mine is CH9102x.

## ESP32 DEVKITV1 Pinout

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/db79070c-5c90-4e5f-8d61-16d919c0a863)

Image from [RandomNerdTutorials](https://randomnerdtutorials.com/esp32-doit-devkit-v1-board-pinout-30-gpios-copy/).

## ESP32 DEVKITV1 Schematic

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/666516b0-06d4-4319-88c7-725b2365b181)

Imagem edited from [embedded-systems-design.github.io](https://embedded-systems-design.github.io/overview-of-the-esp32-devkit-doit-v1/SchematicsforESP32.pdf).

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

IDF - IoT Development Framework

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

* To create a new project, go to 'File' -> 'Open Folder...' -> Create a new folder and select it (in our case it will be GPIO_Setting).
* Open a terminal and type `idf.py create-project -p . <project_name>`, in our case `<project_name>` will be `GPIO_Setting`. It will add to the tree, the **CMakeLists.txt** file and the folder **main** containing the **GPIO_Setting.c** file and also **CMakeLists.txt**.
* Now we access the **MenuConfig** to configure . Type on the terminal `start idf.py menuconfig`.
* Let's configure the clock speed of our board by going to 'Component config --->' -> 'Hardware Settings' -> 'Main XTAL Config' and 'Main XTAL frequency' and set it to '(X) 40 MHz'.
* Change the CPU frequency to 240 MHz by going to 'Component config --->' -> 'ESP System Settings' -> 'CPU frequency' -> '(X) 240 MHz'.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/fd2e4bea-55fc-4ef8-a3e6-1cf86a43cbdb)

* The ESP32 DEVKITV1 has 4 MB of flash and default configuration is set to only 2 MB. To fix that we will go to 'Seruak fkashers config' -> 'Flash size' -> '(X) 4 MB'. Press 'esc' to quit and before leaving confirm saving the configuration. On the project tree, the **sdkconfig** file was created with the saved configuration and  the **sdkconfig.old** with the default, not changed configuration.
* Compile the project by `idf.py build`.
* Program the board by `idf.py -p COM16 flash`.
* As good practice, we can create a 'verion.txt' file, type the firmware version and save. It will lated return on the terminal 'cpu_start: App version: 1.0'.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/c7218501-5646-448e-b0f1-0d57fe62dbdd)

NOTE: The file that is programmed inside the uC, is the 'bootloader.bin', found at the 'build' folder of the tree. The 'GPIO_Setting.bin' (<project_name>.bin) is the project binary file to be loaded un the uC. The 'GPIO_Setting.elf' (<project_name>.elf) it the file used for debugging the firmware.

The documentation to help writing the GPIO code can be found on [Espressif website](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html).

* On 'GPIO_Settint.c' we will add the driver by typing '#include "driver/gpio.h"'. Then we need to click to Edit "includePath" setting.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/1d5f5832-6e6b-4d12-a3d2-283deb541126)

* Once the option for Edit "includePath" setting is selected. It will appear a few options on the project tree. Go to '.vscode' -> 'c_cpp_properties.json' and add the Espressif path to the includePath.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/051bc2d4-4812-430f-9f13-69e946a56276)

* When calling the function 'gpio_set_direction()', just right-click on the function and select 'Go to definition'/'Go to declaration' to learn more about the function. Doing the same thing for expected received variable, we can see the options. Set and control the GPIOS.

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/8dc7f0bf-c791-435c-854b-b6752dad4f50)

```c
#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    // GPIO Settings (GPIO22 as input, GPIO2 as output)
    gpio_set_direction(GPIO_NUM_22,GPIO_MODE_INPUT);
    gpio_set_pull_mode(GPIO_NUM_22,GPIO_PULLUP_ONLY);

    gpio_set_direction(GPIO_NUM_2,GPIO_MODE_OUTPUT);

    while(1){
        // GPIO Controlling
        if (gpio_get_level(GPIO_NUM_22)) {
            // Do nothing, to be implemented
        }
        //gpio_set_level(GPIO_NUM_2,0);
        //vTaskDelay(2400); // From freeRTOS lib
        gpio_set_level(GPIO_NUM_2,1); // To test - GPIO2 is connected to the anode of blue led.
        //vTaskDelay(2400);
    }
}
```
* Build, Flash and check the results.

**Note: I was forgeting of saving the code before building (Ctrl + S). It is very important to do that!!**

I only leave the code to light the blue LED here. For input, we need the pront-on-board and it is not the moment to study timer right now. As results: 

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/1fd5ca22-38b3-49ae-976f-29f15341de43)

# Arduino IDE

# Issues

## Error at run_serial_tool.cmake:66

In my personal computer, I had no problemns programming the ESP boards. At company I had the following issue:
When trying to program the ESP32 board by using `idf.py -p COM5 flash` and it return the following error (with the 5 boards):

```
A fatal error occurred: Could not open COM5, the port is busy or doesn't exist.
(could not open port 'COM5': PermissionError(13, 'Access is denied.', None, 5))

CMake Error at run_serial_tool.cmake:66 (message):

  C:/Espressif/python_env/idf5.1_py3.11_env/Scripts/python.exe;;C:/Espressif/frameworks/esp-idf-v5.1.1/components/esptool_py/esptool/esptool.py;--chip;esp32
  failed.

FAILED: CMakeFiles/flash C:/Espressif/frameworks/esp-idf-v5.1.1/examples/get-started/blink/build/CMakeFiles/flash
cmd.exe /C "cd /D C:\Espressif\frameworks\esp-idf-v5.1.1\components\esptool_py && C:\Espressif\tools\cmake\3.24.0\bin\cmake.exe -D IDF_PATH=C:/Espressif/frameworks/esp-idf-v5.1.1 -D SERIAL_TOOL=C:/Espressif/python_env/idf5.1_py3.11_env/Scripts/python.exe;;C:/Espressif/frameworks/esp-idf-v5.1.1/components/esptool_py/esptool/esptool.py;--chip;esp32 -D SERIAL_TOOL_ARGS=--before=default_reset;--after=hard_reset;write_flash;@flash_args -D WORKING_DIRECTORY=C:/Espressif/frameworks/esp-idf-v5.1.1/examples/get-started/blink/build -P C:/Espressif/frameworks/esp-idf-v5.1.1/components/esptool_py/run_serial_tool.cmake"
ninja: build stopped: subcommand failed.
ninja failed with exit code 1, output of the command is in the C:\Espressif\frameworks\esp-idf-v5.1.1\examples\get-started\blink\build\log\idf_py_stderr_output_13376 and C:\Espressif\frameworks\esp-idf-v5.1.1\examples\get-started\blink\build\log\idf_py_stdout_output_13376
```
And the COM is the correct one:

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/72111334-467d-43f7-8abe-893c11c358cb)

You can fix that by, clicking on the 'USB-Enhanced-SERIAL CH9102 (COM5)' Properties, then going to the TAB 'Port Settings' -> 'Advanced...', and changing the COM port:

![image](https://github.com/Rafaelatff/ESP32-WROOM-32-Basics/assets/58916022/acf01de6-b263-48c9-a34a-e0c6b939ea15)

After that, all 5 boards worked fine.
I also had problem with my USB cable (that short circuited input and GND), but computer + system managed that (it turn off usb once the surge happened). Changed the cable and all returned to work properly.

# Bibliografy

All the links that help me through the process of ESP32 learning.

* [ESP32 - Getting Started with ESP-IDF using Visual Studio Code [Easiest Method]](https://www.youtube.com/watch?v=5IuZ-E8Tmhg)
* [QUICK FIX for IDF Terminal inside VS CODE](https://www.youtube.com/watch?v=N93RvZz6dEc)
* [ESP32 - How to create your First ESP IDF project (From Scratch)](https://www.youtube.com/watch?v=oHHOCdmLiII)
* [ESP32 & could not open port ‘COM5’: PermissionError(13, ‘Access is denied.’, None, 5)](https://community.platformio.org/t/esp32-could-not-open-port-com5-permissionerror-13-access-is-denied-none-5/22396)
