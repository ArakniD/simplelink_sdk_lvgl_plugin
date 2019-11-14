### SysConfig Notice

All examples will soon be supported by SysConfig, a tool that will help you graphically configure your software components. A preview is available today in the examples/syscfg_preview directory. Starting in 3Q 2019, with SDK version 3.30, only SysConfig-enabled versions of examples will be provided. For more information, click [here](http://www.ti.com/sysconfignotice).

---
# sharpsimpledisplay

---

## Example Summary

Demonstrate simple LittlevGL graphics capabilities by drawing texts, lines, and an image on the Sharp128x128 Display (BOOSTXL-SHARP128).

## Hardware Modifications

> This example requires an external display device.  If you're using an IDE
(such as CCS or IAR), please refer to Board.html in
your project directory for resources used and board-specific jumper settings.
Otherwise, you can find Board.html in the directory
&lt;SDK_INSTALL_DIR&gt;/source/ti/boards/&lt;BOARD&gt;.

### CC3220S, CC3220SF, CC3235S, CC3235SF LaunchPads

Jumper wire the following on the back of the LaunchPad

* BoosterPack Header Pin 2 `P58(NC)` to BoosterPack Header Pin 1 `3V3`
* BoosterPack Header Pin 6 `P59(NC)` to BoosterPack Header Pin 4 `P03`

## Example Usage

* Run the example.

* A TI logo will be displayed on the LCD and with a bounding box drawn around it.

* A title string "LittlevGL Demo" will scroll from left to right repeatedly.

## Application Design Details

TI-RTOS:

* When building in Code Composer Studio, the kernel configuration project will
be imported along with the example. The kernel configuration project is
referenced by the example, so it will be built first. The "release" kernel
configuration is the default project used. It has many debug features disabled.
These features include assert checking, logging and runtime stack checks. For a
detailed difference between the "release" and "debug" kernel configurations and
how to switch between them, please refer to the SimpleLink MCU SDK User's
Guide. The "release" and "debug" kernel configuration projects can be found
under &lt;SDK_INSTALL_DIR&gt;/kernel/tirtos/builds/&lt;BOARD&gt;/(release|debug)/(ccs|gcc).

FreeRTOS:

* Please view the `FreeRTOSConfig.h` header file for example configuration
information.
