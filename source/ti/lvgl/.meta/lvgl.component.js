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
 *  ======== lvgl.component.js ========
 */

"use strict";

let topModules;
let displayName = "LittlevGL";
let description = "LittlevGL Configuration";
let deviceId = system.deviceData.deviceId;

topModules = [
    {
        displayName: displayName,
        description: description,
        modules: [
            "/ti/lvgl/lvgldisplay"
        ]
    }
];

let templates = [
    {
        "name": "/ti/lvgl/lv_conf.h.xdt",
        "outputPath": "lv_conf.h"
    },
    {
        "name": "/ti/lvgl/lv_drv_conf.h.xdt",
        "outputPath": "lv_drv_conf.h"
    },
    {
        "name": "/ti/lvgl/ti_lvgl_disp_interface.c.xdt",
        "outputPath": "ti_lvgl_disp_interface.c"
    },
    {
        "name": "/ti/lvgl/ti_lvgl_disp_interface.h.xdt",
        "outputPath": "ti_lvgl_disp_interface.h"
    },
    {
        "name": "/ti/lvgl/ti_lvgl_ls013b7dh03_disp.c.xdt",
        "outputPath": "ti_lvgl_ls013b7dh03_disp.c"
    },
    {
        "name": "/ti/lvgl/ti_lvgl_ssd2119_disp.c.xdt",
        "outputPath": "ti_lvgl_ssd2119_disp.c"
    },
    {
        "name": "/ti/lvgl/lv_port_disp.h.xdt",
        "outputPath": "lv_port_disp.h"
    },
    {
        "name": "/ti/lvgl/lv_port_indev.c.xdt",
        "outputPath": "lv_port_indev.c"
    },
    {
        "name": "/ti/lvgl/lv_port_indev.h.xdt",
        "outputPath": "lv_port_indev.h"
    }
];

exports = {
    displayName: displayName,
    topModules: topModules,
    templates: templates
};
