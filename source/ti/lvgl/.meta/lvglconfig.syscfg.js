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
 *  ======== lvglconfig.syscfg.js ========
 */

"use strict";

/*
 *  ======== onPresetConfigChange ========
 */
function onPresetConfigChange(inst, ui)
{
    if (inst.presetConfig === "low") {
        inst.memSize = "2048U"

        inst.themes = [];
        
        inst.builtInFonts = ["fontRoboto16", "fontUnscii8"]
        inst.fontDefault = "lv_font_unscii_8";

        inst.simpleObjects = ["useLabel", "useImg", "useLine"];
        inst.containerObjects = [];
        inst.dataObjects = [];
        inst.uiObjects = [];
    }
    if (inst.presetConfig === "medium") {
        inst.memSize = "4096U"

        inst.themes = ["material"];
        
        inst.builtInFonts = ["fontRoboto16", "fontUnscii8"]
        inst.fontDefault = "lv_font_roboto_16";

        inst.simpleObjects = ["useLabel", "useImg", "useLine"];
        inst.containerObjects = ["useCont", "usePage", "useTabView"];
        inst.dataObjects = ["useBar", "useChart"];
        inst.uiObjects = ["useBtn", "useBtnMatrix", "useCheckBox", "useDDList", "useSlider"];
    }
    if (inst.presetConfig === "high") {
        inst.memSize = "16U * 1024U"

        inst.themes = ["default", "alien", "night", "mono", "material", "zen", "nemo"];

        inst.builtInFonts = ["fontRoboto12", "fontRoboto16", "fontRoboto22", "fontRoboto28", "fontUnscii8"]
        inst.fontDefault = "lv_font_roboto_16";

        inst.simpleObjects = ["useLabel", "useImg", "useLine", "useArc"];
        inst.containerObjects = ["useCont", "usePage", "useWin", "useTabView", "useTileView"];
        inst.dataObjects = ["useBar", "useLMeter", "useGauge", "useChart", "useTable", "useLED", "useMsgBox", "useTA", "useSpinbox", "useCalendar", "usePreload", "useCanvas"];
        inst.uiObjects = ["useBtn", "useImgBtn", "useBtnMatrix", "useKeyboard",  "useCheckBox", "useList", "useDDList", "useRoller", "useSlider", "useSwitch"];
    }
    onSimpleObjectsChange(inst, ui);
    onContainerObjectChange(inst, ui);
    onDataObjectsChange(inst, ui);
    onUiObjectsChange(inst, ui);
    return;
}

/*
 *  ======== onEnableGCChange ========
 */
function onEnableGCChange(inst, ui)
{
    ui.memCustomRealloc.hidden = !inst.enableGC;
    ui.memCustomGetSize.hidden = !inst.enableGC;
    ui.gcInclude.hidden = !inst.enableGC;
}

/*
 *  ======== onMemCustomChange ========
 */
function onMemCustomChange(inst, ui)
{
    ui.memSize.hidden = inst.memCustom;
    ui.memAttr.hidden = inst.memCustom;
    ui.memAdr.hidden = inst.memCustom;
    ui.memAutoDefrag.hidden = inst.memCustom;

    ui.memCustomInclude.hidden = !inst.memCustom;
    ui.memCustomAlloc.hidden = !inst.memCustom;
    ui.memCustomFree.hidden = !inst.memCustom;
    return;
}

/*
 *  ======== onTickCustomChange ========
 */
function onTickCustomChange(inst, ui)
{
    ui.tickCustomInclude.hidden = !inst.tickCustom;
    ui.tickCustomSysTimeExpr.hidden = !inst.tickCustom;
    return;
}

/*
 *  ======== onSimpleObjectsChange ========
 */
function onSimpleObjectsChange(inst, ui)
{
    ui.labelScrollSpeed.hidden = !inst.simpleObjects.includes("useLabel");
    ui.labelWaitCharCount.hidden = !inst.simpleObjects.includes("useLabel");
    ui.labelTextSel.hidden = !inst.simpleObjects.includes("useLabel");
    ui.labelLongTxtHint.hidden = !inst.simpleObjects.includes("useLabel");
    return;
}

/*
 *  ======== onContainerObjectChange ========
 */
function onContainerObjectChange(inst, ui)
{
    ui.pageAnimTime.hidden = !inst.containerObjects.includes("usePage");
    ui.tabViewAnimTime.hidden = !inst.containerObjects.includes("useTabView");
    ui.tileViewAnimTime.hidden = !inst.containerObjects.includes("useTileView");
    return;
}

/*
 *  ======== onDataObjectsChange ========
 */
function onDataObjectsChange(inst, ui)
{
    ui.chartAxisTickLabelMaxLen.hidden = !inst.dataObjects.includes("useChart");
    ui.preloadArcLength.hidden = !inst.dataObjects.includes("usePreload");
    ui.preloadSpinTime.hidden = !inst.dataObjects.includes("usePreload");
    ui.preloadAnimType.hidden = !inst.dataObjects.includes("usePreload");
    ui.taCursorBlinkTime.hidden = !inst.dataObjects.includes("useTA");
    ui.taPWDShowTime.hidden = !inst.dataObjects.includes("useTA");
    ui.maxTableCol.hidden = !inst.dataObjects.includes("useTable");
    return;
}

/*
 *  ======== onUiObjectsChange ========
 */
function onUiObjectsChange(inst, ui)
{
    ui.btnInkEffect.hidden = !inst.uiObjects.includes("useBtn");
    ui.imgBtnTiled.hidden = !inst.uiObjects.includes("useImgBtn");
    ui.listFocusTime.hidden = !inst.uiObjects.includes("useList");
    ui.ddListAnimTime.hidden = !inst.uiObjects.includes("useDDList");
    ui.rollerAnimTime.hidden = !inst.uiObjects.includes("useRoller");
    ui.rollerInfPages.hidden = !inst.uiObjects.includes("useRoller");
    return;
}

let graphicalSettings = [
    {
        name        : "horResMax",
        displayName : "Maximum Horizontal Resolution",
        description : "Maximal horizontal resolution to support by the library",
        default     : 320
    },
    {
        name        : "verResMax",
        displayName : "Maximum Vertical Resolution",
        description : "Maximal vertical resolution to support by the library",
        default     : 240
    },
    {
        name: "color16Swap",
        displayName: "Color 16 Swap",
        description: "Swap the 2 bytes of RGB565 color. Useful if the display has a 8 bit interface (e.g. SPI)",
        default: false
    },
    {
        name: "screenTransp",
        displayName: "Screen Transparency",
        description: "1: Enable screen transparency. Useful for OSD or other overlapping GUIs. Requires ARGB8888 colors",
        default: false
    },
    {
        name: "colorTransp",
        displayName: "Transparent Color",
        description: "Images pixels with this color will not be drawn (with chroma keying)",
        default: "LV_COLOR_LIME"
    },
    {
        name: "enableAntiAlias",
        displayName: "Enable Anti-aliasing",
        description: "Enables or disables anti-aliasing (lines, and radiuses will be smoothed)",
        default: false
    },
    {
        name: "defRefreshPeriod",
        displayName: "Default Display Refresh Period (ms)",
        description: "Default Display Refresh Period (ms). Can be changed in the display driver (lv_disp_drv_t)",
        default: 15
    },
    {
        name: "dpi",
        displayName: "Dots Per Inch",
        description: "Dots Per Inch: used to initialize default sizes.  E.g. a button with width = LV_DPI / 2 -> half inch wide. (Not so important, you can adjust it to modify default sizes and spaces)",
        default: 100
    },
    {
        name: "coordType",
        displayName: "Type of Coordinates",
        description: "Type of coordinates. Should be `int16_t` (or `int32_t` for extreme cases)",
        default: "int16_t",
        options     : [
            {
                name: "int16_t",
                displayName: "int16_t",
                description: "16-bit integer type coordinates"
            },
            {
                name: "int32_t",
                displayName: "int32_t",
                description: "32-bit integer type coordinates"
            }
        ]
    }
];

let memorySettings = [
    {
        name: "memCustom",
        displayName: "Use Custom malloc/free",
        description: "1: use custom malloc/free, 0: use the built-in lv_mem_alloc/lv_mem_free",
        default: false,
        onChange: onMemCustomChange
    },
    {
        name: "memSize",
        displayName: "Memory Size",
        description: "Size memory used by ``lv_mem_alloc`` in bytes (>= 2kB)",
        default: "2048U"
    },
    {
        name: "memAttr",
        displayName: "Compiler Memory Attribute",
        description: "Complier prefix for big array declaration",
        default: ""
    },
    {
        name: "memAdr",
        displayName: "Memory Pool Address",
        description: "Set an address for memory pool instead of allocation it as an array. Can be in external SRAM too.",
        default: "0"
    },
    {
        name: "memAutoDefrag",
        displayName: "Automatic Memory Defrag",
        description: "Automatically defrag on free",
        default: false
    },
    {
        name: "memCustomInclude",
        displayName: "Custom Memory Include File",
        description: "Header for the dynamic memory function",
        default: "stdlib.h",
        hidden: true
    },
    {
        name: "memCustomAlloc",
        displayName: "Custom Memory Alloc",
        description: "Wrapper to malloc",
        default: "malloc",
        hidden: true
    },
    {
        name: "memCustomFree",
        displayName: "Custom Memory Free",
        description: "Wrapper to free",
        default: "free",
        hidden: true
    },
    {
        displayName: "Garbage Collector Settings",
        config: [
            {
                name: "enableGC",
                displayName: "Enable Garbage Collector",
                description: "",
                default: false,
                onChange: onEnableGCChange
            },
            {
                name: "gcInclude",
                displayName: "Enable Garbage Collector",
                description: "Include Garbage Collector related things",
                default: "gc.h",
                hidden: true
            },
            {
                name: "memCustomRealloc",
                displayName: "Custom Wrapper to realloc",
                description: "Custom wrapper to realloc",
                default: "your_realloc",
                hidden: true
            },
            {
                name: "memCustomGetSize",
                displayName: "Custom Wrapper to lv_mem_get_size",
                description: "Custom Wrapper to lv_mem_get_size",
                default: "your_mem_get_size",
                hidden: true
            }
        ]
    }
];

let miscSettings = [
    {
        displayName: "Input Device",
        config: [
            {
                name: "indevReadPeriod",
                displayName: "Read Period [ms]",
                description: "Input device read period [ms]",
                default: 15
            },
            {
                name: "indevDragLimit",
                displayName: "Drag Limit [pixels]",
                description: "Drag threshold in pixels",
                default: 10
            },
            {
                name: "indevDragThrow",
                displayName: "Drag Throw [%]",
                description: "Drag throw slow-down in [%] (must be > 0). Greater value means faster slow-down",
                default: 20
            },
            {
                name: "indevLongPressTime",
                displayName: "Long Press Time [ms]",
                description: "Long press time [ms]",
                default: 400
            },
            {
                name: "indevLongPressRepTime",
                displayName: "Long Press Repeat Time [ms]",
                description: "Repeated trigger period in long press [ms]",
                default: 100
            }
        ]
    },
    {
        displayName: "Feature Usage",
        config: [
            {
                name: "useAnimation",
                displayName: "Animation",
                description: "1: Enable animations",
                default: true
            },
            {
                name: "useShadow",
                displayName: "Shadow",
                description: "1: Enable shadows",
                default: false
            },
            {
                name: "useGroup",
                displayName: "Object Groups",
                description: "1: Enable object groups (for keyboard/encoder navigation)",
                default: false
            },
            {
                name: "useGPU",
                displayName: "GPU",
                description: "1: Enable GPU interface",
                default: false
            },
            {
                name: "useFileSystem",
                displayName: "File System",
                description: "1: Enable file system (might be required for images)",
                default: false
            },
            {
                name: "useUserData",
                displayName: "User Data",
                description: "1: Add a user_data to drivers and objects",
                default: true
            }
        ]
    },
    {
        displayName: "Image Decoder and Cache",
        config: [
            {
                name: "imgIndexed",
                displayName: "Enable Indexed (Palette) Images",
                description: "1: Enable Indexed (palette) Images",
                default: true
            },
            {
                name: "imgAlpha",
                displayName: "Enable Alpha Indexed Images",
                description: "1: Enable Alpha Indexed Images",
                default: true
            },
            {
                name: "imgCacheSize",
                displayName: "Default Image Cache Size",
                description: "LV_IMG_CACHE_DEF_SIZE must be >= 1",
                longDescription: "Image caching keeps the images opened. "
                    + "If only the built-in image formats are used there is no "
                    + "real advantage of caching. (I.e. no new image decoder is added) "
                    + "With complex image decoders (e.g. PNG or JPG) caching can "
                    + "save the continuous open/decode of images. However the opened "
                    + "images might consume additional RAM.",
                default: 1
            }
        ]
    },
    {
        displayName: "Compiler Settings",
        config: [
            {
                name: "attributeTickInc",
                displayName: "Custom Compiler Attribute for lv_tick_inc()",
                description: "Define a custom attribute to `lv_tick_inc` function",
                default: ""
            },
            {
                name: "attributeTaskHandler",
                displayName: "Custom Compiler Attribute for lv_task_handler()",
                description: "Define a custom attribute to `lv_task_handler` function",
                default: ""
            },
            {
                name: "attributeMemAlign",
                displayName: "Custom Compiler Attribute for Memory Alignment",
                description: "E.g. __attribute__((aligned(4)))",
                longDescription: "With size optimization (-Os) the compiler might "
                    + "not align data to 4 or 8 byte boundary. This alignment will "
                    + "be explicitly applied where needed.",
                default: ""
            },
            {
                name: "attributeLargeConstArray",
                displayName: "Custom Compiler Attribute for Large Constant Arrays",
                description: "Attribute to mark large constant arrays for example font's bitmaps",
                default: ""
            }
        ]
    },
    {
        displayName: "HAL Settings",
        config: [
            {
                name: "tickCustom",
                displayName: "Use Custom Tick Source",
                description: "1: use a custom tick source (removing the need to manually update the tick with `lv_tick_inc)",
                default: false,
                onChange: onTickCustomChange
            },
            {
                name: "tickCustomInclude",
                displayName: "Custom Tick Header Include File",
                description: "Header for the sys time function",
                default: "something.h",
                hidden: true
            },
            {
                name: "tickCustomSysTimeExpr",
                displayName: "Custom System Time Expression",
                description: "Expression evaluating to current systime in ms",
                default: "millis()",
                hidden: true
            },
        ]
    },
    {
        displayName: "Log Settings",
        config: [
            {
                name: "useLog",
                displayName: "Enable Logs",
                description: "Enable/disable the log module",
                default: false
            },
            {
                name: "logLevel",
                displayName: "Log Level",
                description: "How import logs should be added",
                options: [
                    {
                        name: "LV_LOG_LEVEL_TRACE",
                        displayName: "Trace",
                        description: "A lot of logs to give detailed information"
                    },
                    {
                        name: "LV_LOG_LEVEL_INFO",
                        displayName: "Info",
                        description: "Log important events"
                    },
                    {
                        name: "LV_LOG_LEVEL_WARN",
                        displayName: "Warn",
                        description: "Log if something unwanted happened but didn't caused problem"
                    },
                    {
                        name: "LV_LOG_LEVEL_ERROR",
                        displayName: "Error",
                        description: "Only critical issue, when the system may fail"
                    }
                ],
                default: "LV_LOG_LEVEL_WARN"
            },
            {
                name: "logPrintf",
                displayName: "Print Log with printf",
                description: "1: Print the log with 'printf'; 0: user need to register a callback with lv_log_register_print`",
                default: false
            }
        ]
    }
];

let themeSettings = [
    {
        name: "themeLiveUpdate",
        displayName: "Allow Theme Live Update",
        description: "1: Allow theme switching at run time. Uses 8..10 kB of RAM",
        default: false
    },
    {
        name: "themes",
        displayName: "Use Themes",
        description: "Enable the selected themes",
        options: [
            {
                name: "templ",
                displayName: "Template",
                description: "Just for test"
            },
            {
                name: "default",
                displayName: "Default",
                description: "Built mainly from the built-in styles. Consumes very few RAM"
            },
            {
                name: "alien",
                displayName: "Alien",
                description: "Dark futuristic theme"
            },
            {
                name: "night",
                displayName: "Night",
                description: "Dark elegant theme"
            },
            {
                name: "mono",
                displayName: "Mono",
                description: "Mono color theme for monochrome displays"
            },
            {
                name: "material",
                displayName: "Material",
                description: "Flat theme with bold colors and light shadows"
            },
            {
                name: "zen",
                displayName: "Zen",
                description: "Peaceful, mainly light theme"
            },
            {
                name: "nemo",
                displayName: "Nemo",
                description: "Water-like theme based on the movie 'Finding Nemo'"
            }
        ],
        default: [],
        minSelections: 0
    }
];

let fontTextSettings = [
    {
        name: "builtInFonts",
        displayName: "Built-in Fonts",
        longDescription: "The built-in fonts contains the ASCII range and some Symbols with  "
            + "4 bit-per-pixel. The symbols are available via ``LV_SYMBOL_...`` defines\n\r"
            + "More info about fonts: https://docs.littlevgl.com/#Fonts\n\r"
            + "To create a new font go to: https://littlevgl.com/ttf-font-to-c-array",
        options: [
            {
                name: "fontRoboto12",
                displayName: "Roboto 12",
                description: "Robot fonts with bpp = 4 https://fonts.google.com/specimen/Roboto"
            },
            {
                name: "fontRoboto16",
                displayName: "Roboto 16",
                description: "Robot fonts with bpp = 4 https://fonts.google.com/specimen/Roboto"
            },
            {
                name: "fontRoboto22",
                displayName: "Roboto 22",
                description: "Robot fonts with bpp = 4 https://fonts.google.com/specimen/Roboto"
            },
            {
                name: "fontRoboto28",
                displayName: "Roboto 28",
                description: "Robot fonts with bpp = 4 https://fonts.google.com/specimen/Roboto"
            },
            {
                name: "fontUnscii8",
                displayName: "Unscii 8",
                description: "Pixel perfect monospace font http://pelulamu.net/unscii/"
            }
        ],
        default: ["fontUnscii8"],
        minSelections: 0
    },
    {
        name: "fontCustomDeclare",
        displayName: "Custom Font Declares",
        description: "Comma separated list of custom fonts. E.g. my_font1, myfont2",
        default: ""
    },
    {
        name: "fontDefault",
        displayName: "Default Font",
        description: "Always set a default font from the built-in fonts",
        default: "lv_font_unscii_8"
    },
    {
        name: "charEncoding",
        displayName: "Character Encoding",
        description: "Select a character encoding for strings. Your IDE or editor should have the same character encoding",
        options: [
            {
                name: "LV_TXT_ENC_UTF8",
                displayName: "UTF8",
                description: "UTF8 Character Encoding"
            },
            {
                name: "LV_TXT_ENC_ASCII",
                displayName: "ASCII",
                description: "ASCII Character Encoding"
            }
        ],
        default: "LV_TXT_ENC_UTF8"
    },
    {
        name: "breakChars",
        displayName: "Break (wrap) Characters",
        description: "Can break (wrap) text on these chars",
        default: " ,.;:-_"
    }
];

let simpleObjects = {
    name: "simpleObjects",
    displayName: "Simple Objects",
    options: [
        {
            name: "useArc",
            displayName: "Arc",
            description: "Use Arc (dependencies: -)"
        },
        {
            name: "useLabel",
            displayName: "Label",
            description: "Use Label (dependencies: -)"
        },
        {
            name: "useImg",
            displayName: "Image",
            description: "Use Image (dependencies: lv_label)"
        },
        {
            name: "useLine",
            displayName: "Line",
            description: "Use Line (dependencies: -)"
        }
    ],
    default: ["useLabel", "useImg", "useLine"],
    onChange: onSimpleObjectsChange,
    minSelections: 0
};

let additionalSimpleObjectsSettings = {
    displayName: "Additional Simple Object Settings",
    config: [
        {
            name: "labelScrollSpeed",
            displayName: "Label Scroll Speed",
            description: "Hor, or ver. scroll speed [px/sec] in 'LV_LABEL_LONG_SCROLL/ROLL' mode",
            default: 25,
            hidden: true
        },
        {
            name: "labelWaitCharCount",
            displayName: "Label Animation Wait Period",
            description: "Waiting period at beginning/end of animation cycle",
            default: 3,
            hidden: true
        },
        {
            name: "labelTextSel",
            displayName: "Enable Label Text Selection",
            description: "Enable selecting text of labels",
            default: false,
            hidden: true
        },
        {
            name: "labelLongTxtHint",
            displayName: "Label Long Text Hint",
            description: "Store extra info in labels (12 bytes) to speed up drawing of very long texts",
            default: false,
            hidden: true
        }
    ]
};

let containerObjects = 	{
    name: "containerObjects",
    displayName: "Container Objects",
    options: [
        {
            name: "useCont",
            displayName: "Container",
            description: "Use Container (dependencies: -)"
        },
        {
            name: "usePage",
            displayName: "Page",
            description: "Use Page (dependencies: lv_cont)"
        },
        {
            name: "useTabView",
            displayName: "Tab View",
            description: "Use Tab View (dependencies: lv_page, lv_btnm)"
        },
        {
            name: "useTileView",
            displayName: "Tile View",
            description: "Use Tile View (dependencies: lv_page)"
        },
        {
            name: "useWin",
            displayName: "Window",
            description: "Use Window (dependencies: lv_cont, lv_btn, lv_label, lv_img, lv_page)"
        }
    ],
    default: [],
    onChange: onContainerObjectChange,
    minSelections: 0
};

let additionalContainerObjectsSettings = {
    displayName: "Additional Container Object Settings",
    config: [
        {
            name: "pageAnimTime",
            displayName: "Page Focus Animation Time (ms)",
            description: "Focus default animation time [ms] (0: no animation)",
            default: 400,
            hidden: true
        },
        {
            name: "tabViewAnimTime",
            displayName: "Tab View Animation Time [ms]",
            description: "Time of slide animation [ms] (0: no animation)",
            default: 300,
            hidden: true
        },
        {
            name: "tileViewAnimTime",
            displayName: "Tile View Animation Time [ms]",
            description: "Time of slide animation [ms] (0: no animation)",
            default: 300,
            hidden: true
        }
    ]
};

let dataObjects = {
    name: "dataObjects",
    displayName: "Data Visualization Objects",
    options: [
        {
            name: "useBar",
            displayName: "Bar",
            description: "Use Bar (dependencies: -)"
        },
        {
            name: "useCalendar",
            displayName: "Calendar",
            description: "Use Calendar (dependencies: -)"
        },
        {
            name: "useCanvas",
            displayName: "Canvas",
            description: "Use Canvas (dependencies: lv_img)"
        },
        {
            name: "useChart",
            displayName: "Chart",
            description: "Use Chart (dependencies: -)"
        },
        {
            name: "useGauge",
            displayName: "Gauge",
            description: "Use Gauge (dependencies:lv_bar, lv_lmeter)"
        },
        {
            name: "useLED",
            displayName: "LED",
            description: "Use LED (dependencies: -)"
        },
        {
            name: "useLMeter",
            displayName: "Line Meter",
            description: "Use Line Meter (dependencies: -)"
        },
        {
            name: "useMsgBox",
            displayName: "Message Box",
            description: "Use Message Box (dependencies: lv_rect, lv_btnm, lv_label)"
        },
        {
            name: "usePreload",
            displayName: "Preloader",
            description: "The preloader object is a spinning arc over a border (dependencies: lv_arc, lv_anim)"
        },
        {
            name: "useSpinbox",
            displayName: "Spinbox",
            description: "A Spinbox object is a numeric entry field with buttons to increment and decrement the displayed value (dependencies: lv_ta)"
        },
        {
            name: "useTA",
            displayName: "Text Area",
            description: "The Text Area is a page with a label and a cursor on it (dependencies: lv_label, lv_page)"
        },
        {
            name: "useTable",
            displayName: "Table",
            description: "Use Table (dependencies: lv_label)"
        }
    ],
    default: [],
    onChange : onDataObjectsChange,
    minSelections: 0
};

let additionalDataObjectsSettings = {
    displayName: "Additional Data Object Settings",
    config: [
        {
            name: "chartAxisTickLabelMaxLen",
            displayName: "Max Length of Chart Axis Tick Label",
            description: "Max length of chart axis tick label",
            default: 20,
            hidden: true
        },
        {
            name: "preloadArcLength",
            displayName: "Preload Arc Length [deg]",
            description: "Preload Arc Length [deg]",
            default: 60,
            hidden: true
        },
        {
            name: "preloadSpinTime",
            displayName: "Preload Spin Time [ms]",
            description: "Preload Spin Time [ms]",
            default: 1000,
            hidden: true
        },
        {
            name: "preloadAnimType",
            displayName: "Preload Animation Type",
            description: "Preload Animation Type",
            default: "LV_PRELOAD_TYPE_SPINNING_ARC",
            options: [
                {
                    name: "LV_PRELOAD_TYPE_SPINNING_ARC",
                    displayName: "Spinning Arc",
                    description: "Spinning Arc"
                },
                {
                    name: "LV_PRELOAD_TYPE_FILLSPIN_ARC",
                    displayName: "Fill Spin Arc",
                    description: "Fill Spin Arc"
                }
            ],
            hidden: true
        },
        {
            name: "taCursorBlinkTime",
            displayName: "Text Area Cursor Blink Time [ms]",
            description: "Text Area Cursor Blink Time [ms]",
            default: 400,
            hidden: true
        },
        {
            name: "taPWDShowTime",
            displayName: "Text Area PWD Show Time [ms]",
            description: "Text Area PWD Show Time [ms]",
            default: 1500,
            hidden: true
        },
        {
            name: "maxTableCol",
            displayName: "Max Table Columns",
            description: "Maximum number of Table Columns",
            default: 12,
            hidden: true
        }
    ]
};

let uiObjects = {
    name: "uiObjects",
    displayName: "User Input Objects",
    options: [
        {
            name: "useBtn",
            displayName: "Button",
            description: "Use Button (dependencies: lv_cont)"
        },
        {
            name: "useBtnMatrix",
            displayName: "Button Matrix",
            description: "Use Button Matrix (dependencies: -)"
        },
        {
            name: "useCheckBox",
            displayName: "Check Box",
            description: "Use Check Box (dependencies: lv_btn, lv_label)"
        },
        {
            name: "useDDList",
            displayName: "Drop Down List",
            description: "Use Drop Down List (dependencies: lv_page, lv_label, lv_symbol_def.h)"
        },
        {
            name: "useImgBtn",
            displayName: "Image Button",
            description: "Use Image Button (dependencies: lv_btn)"
        },
        {
            name: "useKeyboard",
            displayName: "Keyboard",
            description: "Use Keyboard (dependencies: lv_btnm)"
        },
        {
            name: "useList",
            displayName: "List",
            description: "Use List (dependencies: lv_page, lv_btn, lv_label, (lv_img optionally for icons ))"
        },
        {
            name: "useRoller",
            displayName: "Roller",
            description: "Use Roller (dependencies: lv_ddlist)"
        },
        {
            name: "useSlider",
            displayName: "Slider",
            description: "Use Slider (dependencies: lv_bar)"
        },
        {
            name: "useSwitch",
            displayName: "Switch",
            description: "Use Switch (dependencies: lv_slider)"
        }
    ],
    default: [],
    onChange: onUiObjectsChange,
    minSelections: 0
};

let additionalUiObjectsSettings = {
    displayName: "Additional UI Object Settings",
    config: [
        {
            name: "btnInkEffect",
            displayName: "Button-State Animation",
            description: "Enable button-state animations - draw a circle on click (dependencies: USE_LV_ANIMATION)",
            default: true,
            hidden: true
        },
        {
            name: "ddListAnimTime",
            displayName: "Drop Down List Animation Time",
            description: "Open and close default animation time [ms] (0: no animation)",
            default: 200,
            hidden: true
        },
        {
            name: "imgBtnTiled",
            displayName: "Image Button Tiled",
            description: "1: The imgbtn requires left, mid and right parts and the width can be set freely",
            default: false,
            hidden: true
        },
        {
            name: "listFocusTime",
            displayName: "List Focus Time",
            description: "Default animation time of focusing to a list element [ms] (0: no animation)",
            default: 100,
            hidden: true
        },
        {
            name: "rollerAnimTime",
            displayName: "Roller Animation Time",
            description: "Focus animation time [ms] (0: no animation)",
            default: 200,
            hidden: true
        },
        {
            name: "rollerInfPages",
            displayName: "Number of Roller Infinite Pages",
            description: "Number of extra 'pages' when the roller is infinite",
            default: 7,
            hidden: true
        }
    ]
};

let objSettings = [
    {
        name: "objRealign",
        displayName: "Enable Object Realign",
        description: "Enable `lv_obj_realign()` based on `lv_obj_align()` parameters",
        default: true
    },
    {
        name: "objExtraClickArea",
        displayName: "Extra Object Clickable Area",
        description: "Enable to make the object clickable on a larger area.",
        longDescription: "Enable to make the object clickable on a larger area.\n\r"
            + "LV_EXT_CLICK_AREA_OFF or 0: Disable this feature\n\r"
            + "LV_EXT_CLICK_AREA_TINY: The extra area can be adjusted horizontally and vertically (0..255 px)\n\r"
            + "LV_EXT_CLICK_AREA_FULL: The extra area can be adjusted in all 4 directions (-32k..+32k px)",
        options: [
            {
                name: "LV_EXT_CLICK_AREA_OFF",
                displayName: "Off",
                description: "LV_EXT_CLICK_AREA_OFF: Disable this feature"
            },
            {
                name: "LV_EXT_CLICK_AREA_TINY",
                displayName: "Tiny",
                description: "LV_EXT_CLICK_AREA_TINY: The extra area can be adjusted horizontally and vertically (0..255 px)"
            },
            {
                name: "LV_EXT_CLICK_AREA_FULL",
                displayName: "Full",
                description: "LV_EXT_CLICK_AREA_FULL: The extra area can be adjusted in all 4 directions (-32k..+32k px)"
            }
        ],
        default: "LV_EXT_CLICK_AREA_OFF"
    },
    simpleObjects,
    additionalSimpleObjectsSettings,
    containerObjects,
    additionalContainerObjectsSettings,
    dataObjects,
    additionalDataObjectsSettings,
    uiObjects,
    additionalUiObjectsSettings
];

let config = [
    {
        name: "presetConfig",
        displayName: "Preset LittlevGL Configurations",
        description: "Select a toplevel preset configuration",
        longDescription: "Toplevel preset LittlevGL configurations that provide good "
            + "starting grounds for various end applications.\n\r"
            + "* Low: Only Default Theme and lv_monospace_8 Font is enabled. Label, Image, and Line are enabled\n\r"
            + "* Medium: Default and Material Themes are enabled. lv_font_dejavu10, lv_font_dejavu20, lv_font_dejavu30, lv_font_dejavu40, and lv_monospace8 are enabled @ 1-bit-per-pixel. TabView, Bar, Chart, Button, CheckBox, Dropdownlist, & Slider are enabled.\n\r"
            + "* High: All built-in themes, fonts, and objects are enabled\n\r",
        default : "low",
        onChange: onPresetConfigChange,
        options: [
            {
                name: "low",
                displayName: "Low",
                description: "Minimal theme, fonts, and objects are enabled"
            },
            {
                name: "medium",
                displayName: "Medium",
                description: "Basic theme, fonts, and objects are enabled"
            },
            {
                name: "high",
                displayName: "High",
                description: "All themes, fonts, and objects are enabled"
            }
        ]
    },
    {
        displayName: "Graphical Settings",
        config: graphicalSettings
    },
    {
        displayName: "Memory Manager Settings",
        config: memorySettings
    },
    {
        displayName: "Misc Settings",
        config: miscSettings
    },
    {
        displayName: "Theme Usage",
        config: themeSettings
    },
    {
        displayName: "Font & Text Settings",
        config: fontTextSettings
    },
    {
        displayName: "Object Settings",
        config: objSettings
    }
];

var littlevGLConfigModule = {
    displayName: "LittlevGL Config",
    config: [{
        displayName: "LittlevGL Library Configuration",
        config: config
    }]
};

exports = littlevGLConfigModule;