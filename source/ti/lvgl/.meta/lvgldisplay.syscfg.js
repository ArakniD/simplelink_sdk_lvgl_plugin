/*
 * Copyright (c) 2018-2019, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 *  ======== lvgldisplay.syscfg.js ========
 */

"use strict";

let board = system.deviceData.board.name;
let lvglconfig = system.getScript("./lvglconfig");

/*
 *  ======== modules ========
 *  Express dependencies for other modules
 *
 *  Invoked on any configuration change to the given instance.
 */
function modules(inst)
{
    let modules = new Array();

    modules.push({
        name       : "LittlevGL Config",
        moduleName : "/ti/lvgl/lvglconfig"
    });

    return (modules);
}

/*
 * ======== moduleInstances ========
 */
function moduleInstances(inst)
{
    var moduleDep = [];
    if (inst.displayController === "LS013B7DH03") {
        moduleDep.push(
            {
                name       : "LCD Enable",
                moduleName : "/ti/drivers/GPIO",
                hardware   : inst.$hardware ? inst.$hardware.subComponents.LCD_ENABLE : null,
                args       : { $name: "Board_GPIO_SHARP_LCD_ENABLE", mode: "Output" }
            },
            {
                name       : "LCD Power",
                moduleName : "/ti/drivers/GPIO",
                hardware   : inst.$hardware ? inst.$hardware.subComponents.LCD_POWER : null,
                args       : { $name: "Board_GPIO_SHARP_LCD_POWER", mode: "Output" }
            },
            {
                name       : "LCD SS",
                moduleName : "/ti/drivers/GPIO",
                hardware   : inst.$hardware ? inst.$hardware.subComponents.LCD_SS : null,
                args       : { $name: "Board_GPIO_SHARP_LCD_CS", mode: "Output" }
            }
        );
    }
    if (inst.displayController.match("SSD2119")) {
        moduleDep.push(
            {
                name       : "LCD Backlight",
                moduleName : "/ti/drivers/GPIO",
                hardware   : inst.$hardware ? inst.$hardware.subComponents.LCD_BACKLIGHT : null,
                args       : { $name: "Board_GPIO_KENTEC_LCD_BACKLIGHT", mode: "Output" }
            },
            {
                name       : "LCD Reset",
                moduleName : "/ti/drivers/GPIO",
                hardware   : inst.$hardware ? inst.$hardware.subComponents.LCD_RESET : null,
                args       : { $name: "Board_GPIO_KENTEC_LCD_RESET", mode: "Output" }
            },
            {
                name       : "LCD DC",
                moduleName : "/ti/drivers/GPIO",
                hardware   : inst.$hardware ? inst.$hardware.subComponents.LCD_DC : null,
                args       : { $name: "Board_GPIO_KENTEC_LCD_DC", mode: "Output" }
            },
            {
                name       : "LCD SS",
                moduleName : "/ti/drivers/GPIO",
                hardware   : inst.$hardware ? inst.$hardware.subComponents.LCD_SS : null,
                args       : { $name: "Board_GPIO_KENTEC_LCD_CS", mode: "Output" }
            }
        );
        if (inst.useTouchScreen == true) {
            moduleDep.push(
                {
                    name       : "Touchscreen ADC Y+",
                    moduleName : "/ti/drivers/ADC",
                    hardware   : inst.$hardware ? inst.$hardware.subComponents.TS_YP_AIN : null,
                    args       : inst.$hardware ? { $name: "Board_ADC_KENTEC_TS_YP", resolution: "12 Bits", adc: { adcPin: { $assignAllowConflicts: "boosterpack.23" }}} : { resolution: "12 Bits" }
                },
                {
                    name       : "Touchscreen ADC X+",
                    moduleName : "/ti/drivers/ADC",
                    hardware   : inst.$hardware ? inst.$hardware.subComponents.TS_XP_AIN : null,
                    args       : inst.$hardware ? { $name: "Board_ADC_KENTEC_TS_XP", resolution: "12 Bits", adc: { adcPin: { $assignAllowConflicts: "boosterpack.24" }}} : { resolution: "12 Bits" }
                },
                {
                    name       : "Touchscreen Y+",
                    moduleName : "/ti/drivers/GPIO",
                    hardware   : inst.$hardware ? inst.$hardware.subComponents.TS_YP : null,
                    args       : inst.$hardware ? { $name: "Board_GPIO_KENTEC_TS_YP", mode: "Dynamic", gpioPin: { $assignAllowConflicts: "boosterpack.23" }} : { $name: "Board_GPIO_KENTEC_TS_YP", mode: "Dynamic" }
                },
                {
                    name       : "Touchscreen X+",
                    moduleName : "/ti/drivers/GPIO",
                    hardware   : inst.$hardware ? inst.$hardware.subComponents.TS_XP : null,
                    args       : inst.$hardware ? { $name: "Board_GPIO_KENTEC_TS_XP", mode: "Dynamic", gpioPin: { $assignAllowConflicts: "boosterpack.24" }} : { $name: "Board_GPIO_KENTEC_TS_XP", mode: "Dynamic" }
                },
                {
                    name       : "Touchscreen Y-",
                    moduleName : "/ti/drivers/GPIO",
                    hardware   : inst.$hardware ? (board.match(/CC135/) ? null : inst.$hardware.subComponents.TS_YN) : null,
                    args       : inst.$hardware ? (board.match(/CC135/) ? { $name: "Board_GPIO_KENTEC_TS_YN", mode: "Dynamic", gpioPin: { $assign: "boosterpack.18" }} : { $name: "Board_GPIO_KENTEC_TS_YN", mode: "Dynamic" }) : { $name: "Board_GPIO_KENTEC_TS_YN", mode: "Dynamic" }
                },
                {
                    name       : "Touchscreen X-",
                    moduleName : "/ti/drivers/GPIO",
                    hardware   : inst.$hardware ? inst.$hardware.subComponents.TS_XN : null,
                    args       : { $name: "Board_GPIO_KENTEC_TS_XN", mode: "Dynamic" }
                }
            );
        }
    }

    if (inst.displayController != "Custom"){
        if (inst.displayController.match("LS013B7DH03")) {
            moduleDep.push(
                {
                    name       : "sharpTemplates",
                    moduleName : "/ti/lvgl/templates_sharp",
                    hidden     : true
                }
            );
        }
        if (inst.displayController.match("SSD2119")) {
            moduleDep.push(
                {
                    name       : "kentecTemplates",
                    moduleName : "/ti/lvgl/templates_kentec",
                    hidden     : true
                }
            );
            if (inst.useTouchScreen == true) {
                moduleDep.push(
                    {
                        name       : "indevTemplates",
                        moduleName : "/ti/lvgl/templates_indev",
                        hidden     : true
                    }
                );
            }
        }
    }

    return (moduleDep);
}

/*
 * ======== sharedModuleInstances ========
 */
function sharedModuleInstances(inst)
{
    var moduleDep = [];

    if (inst.displayInterface == "SPI") {
        moduleDep.push(
            {
                name       : "SPI",
                moduleName : "/ti/drivers/SPI",
                hardware   : inst.$hardware ? inst.$hardware.subComponents.LCD_SPI : null
            }
        );
    }

    return (moduleDep);
}

/*
 *  ========= filterHardware ========
 */
function filterHardware(component)
{
    let ret = false;

    if (component.displayName) {
        if (component.displayName.match("Sharp LCD Display")) {
            return (true);
        }
        if (component.displayName.match("Kentec LCD Display")) {
            return (true);
        }
    }

    return (ret);
}

/*
 * ======== onHardwareChanged ========
 */
function onHardwareChanged(inst, ui)
{
    if (inst.$hardware) {
        if (inst.$hardware.displayName) {
            if (inst.$hardware.displayName.match("Sharp LCD Display")) {
                inst.displayController = "LS013B7DH03";
                inst.horRes = 128;
                inst.verRes = 128;
                inst.colorDepth = "1";
                
                ui.displayController.readOnly = true;
                ui.horRes.readOnly = true;
                ui.verRes.readOnly = true;
                ui.colorDepth.readOnly = true;
                if (inst.displayInterface === "SPI") {
                    inst.spiBitRate = 1000000;
                }

                ui.useTouchScreen.hidden = true;

                return;
            }
            if (inst.$hardware.displayName.match("Kentec LCD Display")) {
                inst.displayController = "SSD2119";
                inst.horRes = 320;
                inst.verRes = 240;
                inst.colorDepth = "16";

                ui.displayController.readOnly = true;
                ui.horRes.readOnly = true;
                ui.verRes.readOnly = true;
                ui.colorDepth.readOnly = true;
                if (inst.displayInterface === "SPI") {
                    inst.spiBitRate = 24000000;
                }
                
                ui.useTouchScreen.hidden = false;

                return;
            }
        }
    }
    else {
        ui.displayController.readOnly = false;
        ui.horRes.readOnly = false;
        ui.verRes.readOnly = false;
        ui.colorDepth.readOnly = false;

        return;
    }
}

/*
 *  ======== onDisplayControllerChange ========
 */
function onDisplayControllerChange(inst, ui)
{
    if (inst.displayController === "LS013B7DH03") {
        ui.displayInterface.hidden = false;
        ui.spiBitRate.hidden = false;
        ui.useTouchScreen.hidden = true;

        inst.displayInterface = "SPI";
        if (inst.displayInterface === "SPI") {
            inst.spiBitRate = 1000000;
        }
        inst.horRes = 128;
        inst.verRes = 128;
        inst.colorDepth = "1";

        return;
    }
    if (inst.displayController === "SSD2119") {
        ui.displayInterface.hidden = false;
        ui.spiBitRate.hidden = false;
        ui.useTouchScreen.hidden = false;
        
        inst.displayInterface = "SPI";
        if (inst.displayInterface === "SPI") {
            inst.spiBitRate = 24000000;
        }
        inst.horRes = 320;
        inst.verRes = 240;
        inst.colorDepth = "16";

        return;
    }
    else {
        ui.displayInterface.hidden = true;
        ui.spiBitRate.hidden = true;
        ui.useTouchScreen.hidden = true;

        inst.displayInterface = "Custom";

        return;
    }
}

/*
 *  ======== onDisplayInterfaceChange ========
 */
function onDisplayInterfaceChange(inst, ui)
{
    if (inst.displayInterface === "SPI")
        ui.spiBitRate.hidden = false;
    else
        ui.spiBitRate.hidden = true;
    return;
}

var littlevGLDisplayModule = {
    displayName: "LittlevGL Display",
    longDescription: "The LittlevGL Display provides support for graphical displays using the open source graphics library LittlevGL.",
    maxInstances: 1,
    templates: {
        "/ti/lvgl/lv_conf.h.xdt": true
    },
    moduleStatic: lvglconfig,
    config: [
        {
            name        : "displayController",
            displayName : "Display Controller",
            description : "Choose a display controller to support",
            longDescription: "The Display Controller parameter determines the appropriate "
                + "driver source to be generated in the project. The Custom option can "
                + "be selected if users wish to provide their own display drivers. ",
            default     : "LS013B7DH03",
            options: [
                {
                    name: "LS013B7DH03",
                    description: "Use the LS013B7DH03 Display Controller Driver"
                },
                {
                    name: "SSD2119",
                    description: "Use the SSD2119 Display Controller Driver"
                },
                {
                    name: "Custom",
                    description: "Use Custom Display Controller Driver"
                }
            ],
            onChange: onDisplayControllerChange
        },
        {
            name        : "horRes",
            displayName : "Horizontal Resolution",
            description : "Horizontal resolution of the library (LV_VER_RES)",
            default     : 128
        },
        {
            name        : "verRes",
            displayName : "Vertical Resolution",
            description : "Vertical resolution of the library (LV_HOR_RES)",
            default     : 128
        },
        {
            name        : "colorDepth",
            displayName : "Color Depth",
            description : "Color Depth",
            default     : "1",
            options     : [
                {
                    name: "1",
                    displayName: "1",
                    description: "1 byte per pixel"
                },
                {
                    name: "8",
                    displayName: "8",
                    description: "RGB233"
                },
                {
                    name: "16",
                    displayName: "16",
                    description: "RGB565"
                },
                {
                    name: "32",
                    displayName: "32",
                    description: "ARGB8888"
                }
            ]
        },
        {
            name        : "useTouchScreen",
            displayName : "Use Touch Screen",
            description : "Use Touch Screen",
            default     : false,
            hidden      : true
        },
        {
            name        : "displayInterface",
            displayName : "Display Communication Interface",
            description : "Data communication interface with the display",
            default     : "SPI",
            options: [
                {
                    name: "SPI",
                    description: "Use Serial Peripheral Interface"
                },
                // {
                //     name: "I2C",
                //     description: "Use I2C serial Communication protocol"
                // },
                // {
                //     name: "Parallel",
                //     description: "Use Parallel Communication Interface"
                // },
                {
                    name: "Custom",
                    description: "Use a Custom Communication Interface"
                }
            ],
            readOnly    : true,
            onChange    : onDisplayInterfaceChange
        },
        {
            name        : "spiBitRate",
            displayName : "SPI Bit Rate",
            description : "SPI Bit Rate",
            default     : 1000000
        }
    ],
    filterHardware        : filterHardware,
    onHardwareChanged     : onHardwareChanged,
    moduleInstances       : moduleInstances,
    sharedModuleInstances : sharedModuleInstances
};
 
exports = littlevGLDisplayModule;