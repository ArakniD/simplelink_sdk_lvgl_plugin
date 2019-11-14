/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
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
 */

/**
 * @file lv_port_indev.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
 #include <unistd.h>
#include "lv_port_indev.h"
#include <ti/drivers/ADC.h>
#include <ti/drivers/GPIO.h>
#if defined(DeviceFamily_CC13X2) || defined(DeviceFamily_CC26X2)
#include <ti/drivers/gpio/GPIOCC26XX.h>
#endif
#include "Board.h"

/*********************
 *      DEFINES
 *********************/

#define TOUCH_THRESHOLD         300

int32_t g_pi32TouchParameters[7] =
{
    413568,                     // M0
    7552,                      // M1
    -204526976,                 // M2
    24,                       // M3
    -364968,                    // M4
    1276805328,                 // M5
    4466716,                     // M6
};

int32_t m0, m1, m2, m3, m4, m5, m6;

static uint32_t g_ui32TSState;
#define TS_STATE_INIT           0
#define TS_STATE_READ_X         1
#define TS_STATE_READ_Y         2
#define TS_STATE_SKIP_X         3
#define TS_STATE_SKIP_Y         4

ADC_Handle   adc;
ADC_Params   params;
int_fast16_t res;
uint16_t g_i16TouchX = 0;
uint16_t g_i16TouchY = 0;

static int calibrationState;
#define TS_CAL_STATE_DRAW       0
#define TS_CAL_STATE_WAIT       1
#define TS_CAL_STATE_PRESSED    2
#define TS_CAL_STATE_CALCULATE  3
#define TS_CAL_STATE_DONE       4

int32_t i32Idx, ppi32Points[3][4];

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void touchpad_init(void);
static bool touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static bool touchpad_is_pressed(void);
static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;

static lv_coord_t last_x = -10;
static lv_coord_t last_y = 250;
volatile lv_coord_t old_x = -1;
volatile lv_coord_t old_y = -1;

lv_obj_t * calibrationDot;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
    /* Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The ..._read() function are only examples.
     *  You should shape them according to your hardware
     */


    lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad if you have*/
    touchpad_init();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    indev_touchpad = lv_indev_drv_register(&indev_drv);

    /* Calibrate Touchscreen */
    lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);    // First parameters (scr) is the parent
    lv_label_set_text(label, "Calibrate Touchscreen");         // Set the text
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);      // Align top-middle of screen

    calibrationState = TS_CAL_STATE_DRAW;
    i32Idx = 0;

    calibrationDot = lv_obj_create(lv_scr_act(), NULL);

    //
    // Set the points used for calibration based on the size of the screen.
    //
    ppi32Points[0][0] = 320 / 10;
    ppi32Points[0][1] = (240 * 2) / 10;
    ppi32Points[1][0] = 320 / 2;
    ppi32Points[1][1] = (240 * 9) / 10;
    ppi32Points[2][0] = (320 * 9) / 10;
    ppi32Points[2][1] = 240 / 2;

    /* Wait for touchScreen calibration to finish */
    while (calibrationState != TS_CAL_STATE_DONE) {
        lv_task_handler();
        usleep(5000);
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/



/*------------------
 * Touchpad
 * -----------------*/

/*Initialize your touchpad*/
static void touchpad_init(void)
{
    /*Your code comes here*/

    g_ui32TSState = TS_STATE_INIT;

    GPIO_setConfig(Board_GPIO_KENTEC_TS_YP, GPIO_CFG_OUT_LOW);
    GPIO_setConfig(Board_GPIO_KENTEC_TS_YN, GPIO_CFG_OUT_LOW);
    GPIO_setConfig(Board_GPIO_KENTEC_TS_XP, GPIO_CFG_OUT_LOW);
    GPIO_setConfig(Board_GPIO_KENTEC_TS_XN, GPIO_CFG_OUT_LOW);
}

/* Will be called by the library to read the touchpad */
static bool touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    switch (calibrationState)
    {
        case TS_CAL_STATE_DONE:
        {
            break;
        }
        case TS_CAL_STATE_CALCULATE:
        {
            m0 = (((ppi32Points[0][0] - ppi32Points[2][0]) *
                    (ppi32Points[1][3] - ppi32Points[2][3])) -
                   ((ppi32Points[1][0] - ppi32Points[2][0]) *
                    (ppi32Points[0][3] - ppi32Points[2][3])));

            m1 = (((ppi32Points[0][2] - ppi32Points[2][2]) *
                    (ppi32Points[1][0] - ppi32Points[2][0])) -
                   ((ppi32Points[0][0] - ppi32Points[2][0]) *
                    (ppi32Points[1][2] - ppi32Points[2][2])));

            m2 = ((((ppi32Points[2][2] * ppi32Points[1][0]) -
                    (ppi32Points[1][2] * ppi32Points[2][0])) * ppi32Points[0][3]) +
                  (((ppi32Points[0][2] * ppi32Points[2][0]) -
                    (ppi32Points[2][2] * ppi32Points[0][0])) * ppi32Points[1][3]) +
                  (((ppi32Points[1][2] * ppi32Points[0][0]) -
                    (ppi32Points[0][2] * ppi32Points[1][0])) *
                   ppi32Points[2][3]));

            m3 = (((ppi32Points[0][1] - ppi32Points[2][1]) *
                    (ppi32Points[1][3] - ppi32Points[2][3])) -
                   ((ppi32Points[1][1] - ppi32Points[2][1]) *
                    (ppi32Points[0][3] - ppi32Points[2][3])));

            m4 = (((ppi32Points[0][2] - ppi32Points[2][2]) *
                    (ppi32Points[1][1] - ppi32Points[2][1])) -
                   ((ppi32Points[0][1] - ppi32Points[2][1]) *
                    (ppi32Points[1][2] - ppi32Points[2][2])));

            m5 = ((((ppi32Points[2][2] * ppi32Points[1][1]) -
                    (ppi32Points[1][2] * ppi32Points[2][1])) * ppi32Points[0][3]) +
                  (((ppi32Points[0][2] * ppi32Points[2][1]) -
                    (ppi32Points[2][2] * ppi32Points[0][1])) * ppi32Points[1][3]) +
                  (((ppi32Points[1][2] * ppi32Points[0][1]) -
                    (ppi32Points[0][2] * ppi32Points[1][1])) *
                   ppi32Points[2][3]));

            m6 = (((ppi32Points[0][2] - ppi32Points[2][2]) *
                    (ppi32Points[1][3] - ppi32Points[2][3])) -
                   ((ppi32Points[1][2] - ppi32Points[2][2]) *
                    (ppi32Points[0][3] - ppi32Points[2][3])));

            g_pi32TouchParameters[0] = m0;
            g_pi32TouchParameters[1] = m1;
            g_pi32TouchParameters[2] = m2;
            g_pi32TouchParameters[3] = m3;
            g_pi32TouchParameters[4] = m4;
            g_pi32TouchParameters[5] = m5;
            g_pi32TouchParameters[6] = m6;

            lv_obj_del(calibrationDot);
            calibrationState = TS_CAL_STATE_DONE;

            break;
        }
        case TS_CAL_STATE_DRAW:
        {
            /* draw rectangle */
            lv_obj_set_size(calibrationDot, 10, 10);
            lv_obj_set_pos(calibrationDot, ppi32Points[i32Idx][0], ppi32Points[i32Idx][1]);
            calibrationState = TS_CAL_STATE_WAIT;
            break;
        }
    }

    touchpad_get_xy(&last_x, &last_y);

    /*Save the pressed coordinates and the state*/
    if(touchpad_is_pressed()) {
        if (calibrationState == TS_CAL_STATE_WAIT){
            ppi32Points[i32Idx][2] = g_i16TouchX;
            ppi32Points[i32Idx][3] = g_i16TouchY;
            calibrationState = TS_CAL_STATE_PRESSED;
        }

        /*Set the last pressed coordinates*/
        data->point.x = last_x;
        data->point.y = last_y;
        old_x = last_x;
        old_y = last_y;
        data->state = LV_INDEV_STATE_PR;
    } else {
        if (calibrationState == TS_CAL_STATE_PRESSED){
            i32Idx++;
            if (i32Idx < 3)
                calibrationState = TS_CAL_STATE_DRAW;
            else
                calibrationState = TS_CAL_STATE_CALCULATE;
        }
        data->point.x = old_x;
        data->point.y = old_y;
        data->state = LV_INDEV_STATE_REL;
    }

    /*Return false because we are not buffering and no more data to read*/
    return false;
}

/*Return true is the touchpad is pressed*/
static bool touchpad_is_pressed(void)
{
    /*Your code comes here*/

    return (g_i16TouchX >= TOUCH_THRESHOLD && g_i16TouchY >= TOUCH_THRESHOLD);
}

/*Get the x and y coordinates if the touchpad is pressed*/
static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y)
{

    /*Your code comes here*/

    switch(g_ui32TSState)
    {
        //
        // The new sample is an X-axis sample that should be discarded.
        //
        case TS_STATE_SKIP_X:
        {
#if defined(DeviceFamily_CC13X2) || defined(DeviceFamily_CC26X2)
            GPIOCC26xx_release(Board_GPIO_KENTEC_TS_YP);
#endif
            ADC_Params_init(&params);
            adc = ADC_open(Board_ADC_KENTEC_TS_YP, &params);

            if (adc == NULL) {
                while (1);
            }

            GPIO_setConfig(Board_GPIO_KENTEC_TS_YN, GPIO_CFG_INPUT);

            //
            // The next sample will be a valid X-axis sample.
            //
            g_ui32TSState = TS_STATE_READ_X;

            break;
        }
        //
        // The new sample is an X-axis sample that should be processed.
        //
        case TS_STATE_READ_X:
        {
            //
            // Read the raw ADC sample.
            //
            res = ADC_convert(adc, &g_i16TouchX);

            ADC_close(adc);

            GPIO_setConfig(Board_GPIO_KENTEC_TS_YP, GPIO_CFG_OUT_HIGH);
            GPIO_setConfig(Board_GPIO_KENTEC_TS_YN, GPIO_CFG_OUT_LOW);
            GPIO_setConfig(Board_GPIO_KENTEC_TS_XP, GPIO_CFG_OUT_LOW);
            GPIO_setConfig(Board_GPIO_KENTEC_TS_XN, GPIO_CFG_OUT_LOW);

            //
            // The next sample will be an invalid Y-axis sample.
            //
            g_ui32TSState = TS_STATE_SKIP_Y;

            break;
        }
        //
        // The new sample is a Y-axis sample that should be discarded.
        //
        case TS_STATE_SKIP_Y:
        {
#if defined(DeviceFamily_CC13X2) || defined(DeviceFamily_CC26X2)
            GPIOCC26xx_release(Board_GPIO_KENTEC_TS_XP);
#endif
            ADC_Params_init(&params);
            adc = ADC_open(Board_ADC_KENTEC_TS_XP, &params);

            if (adc == NULL) {
                while (1);
            }

            GPIO_setConfig(Board_GPIO_KENTEC_TS_XN, GPIO_CFG_INPUT);

            //
            // The next sample will be a valid Y-axis sample.
            //
            g_ui32TSState = TS_STATE_READ_Y;

            break;
        }
        //
        // The new sample is a Y-axis sample that should be processed.
        //
        case TS_STATE_READ_Y:
        {
            //
            // Read the raw ADC sample.
            //
            res = ADC_convert(adc, &g_i16TouchY);

            ADC_close(adc);
        }
        //
        // The state machine is in its initial state
        //
        case TS_STATE_INIT:
        {
            GPIO_setConfig(Board_GPIO_KENTEC_TS_YP, GPIO_CFG_OUT_LOW);
            GPIO_setConfig(Board_GPIO_KENTEC_TS_YN, GPIO_CFG_OUT_LOW);
            GPIO_setConfig(Board_GPIO_KENTEC_TS_XP, GPIO_CFG_OUT_HIGH);
            GPIO_setConfig(Board_GPIO_KENTEC_TS_XN, GPIO_CFG_OUT_LOW);

            //
            // If this is the valid Y sample state, then there is a new X/Y
            // sample pair.  In that case, run the touch screen debouncer.
            //
            if(g_ui32TSState == TS_STATE_READ_Y)
            {
                int32_t i32X, i32Y, i32Temp;

                i32X = g_i16TouchX;
                i32Y = g_i16TouchY;
                i32Temp = (((i32X * g_pi32TouchParameters[0]) +
                            (i32Y * g_pi32TouchParameters[1]) + g_pi32TouchParameters[2]) /
                           g_pi32TouchParameters[6]);
                i32Y = (((i32X * g_pi32TouchParameters[3]) +
                         (i32Y * g_pi32TouchParameters[4]) + g_pi32TouchParameters[5]) /
                        g_pi32TouchParameters[6]);
                i32X = i32Temp;

                (*x) = i32X;
                (*y) = i32Y;
            }

            //
            // The next sample will be an invalid X-axis sample.
            //
            g_ui32TSState = TS_STATE_SKIP_X;

            break;
        }
    }
}
