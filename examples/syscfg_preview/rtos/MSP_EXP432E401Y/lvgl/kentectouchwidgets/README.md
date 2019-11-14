### SysConfig Notice

All examples will soon be supported by SysConfig, a tool that will help you graphically configure your software components. A preview is available today in the examples/syscfg_preview directory. Starting in 3Q 2019, with SDK version 3.30, only SysConfig-enabled versions of examples will be provided. For more information, click [here](http://www.ti.com/sysconfignotice).

---
# kentectouchwidgets

---

## Example Summary

Demonstrate more advanced LittlevGL graphics capabilities by creating a demo User Interface complete with touchscreen interactions.

## Hardware Modifications

> This example requires an external display device.  If you're using an IDE
(such as CCS or IAR), please refer to Board.html in
your project directory for resources used and board-specific jumper settings.
Otherwise, you can find Board.html in the directory
&lt;SDK_INSTALL_DIR&gt;/source/ti/boards/&lt;BOARD&gt;.

### CC1352R1, CC1352P1, CC1352P_2 LaunchPads

* Jumper wire the following on the back of the LaunchPad
  * BoosterPack Header Pin 11 `(NC)` to BoosterPack Header Pin 18 `DIO11`

### CC3220S, CC3220SF LaunchPads

* Jumper wire the following on the back of the LaunchPad
  * BoosterPack Header Pin 40 `P02(NC)` to BoosterPack Header Pin 10 `P02`
* Remove `R102, R103, R104, R105`
* Replace with 1K resistor – `R100, R101`
* Replace with 1.2K resistor – `C53, C54`
* Remove Jumpers `TCK` and `TDM` on J3
* Move Jumper to the bottom position on J6
* Switch J13 to configure SOP[2:0] = 001 for SWD

> Configure Target Configuration to use Serial Wire Debug (SWD) instead of JTAG.  
> Open targetConfigs -> CC3220S/SF.ccxml -> Board or Device -> Select CC3220S/SF_SWD -> Save
> Configuration

### CC3235S, CC3235SF LaunchPads

* Jumper wire the following on the back of the LaunchPad
  * BoosterPack Header Pin 40 `P02(NC)` to BoosterPack Header Pin 10 `P02`
* Remove `R114, R115, R116, R117`
* Replace with 1K resistor – `R112, R113`
* Replace with 1.2K resistor – `C71, C71`
* Remove Jumpers `TCK` and `TDM` on J4
* Move Jumper to the bottom position on J10
* Switch J15, J16, J17 to configure SOP[2:0] = 001 for SWD

> Configure Target Configuration to use Serial Wire Debug (SWD) instead of JTAG.  
> Open targetConfigs -> CC3235S/SF.ccxml -> Board or Device -> Select CC3235S_SWD/CC3235SF_SWD
> -> Save Configuration

## Example Usage

* Run the example.

* Touchscreen Calibration is necessary for using the touchscreen. Press on 3 different points on the screen as they appear to calibrate.

* The demo GUI will be displayed with various touchscreen widgets. There are 3 different tab views that can be switched to via touch.

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
