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

/*
 *  ======== sharpsimpledisplay.c ========
 */

/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

/* POSIX Header files */
#include <pthread.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>

/* Board Header file */
#include "Board.h"

/* lvgl Includes */
#include <lv_port_disp.h>

LV_IMG_DECLARE(ti_logo_96_indexed_2colors);

/*
 * Notification function called when the posix timer expires
 */
void notifyFxn(sigval val)
{
    lv_tick_inc(1);
}

/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    /* Call driver init functions */
    GPIO_init();

    /***********************
     * Initialize LittlevGL
     ***********************/
    lv_init();

    /***********************
     * Tick interface
     ***********************/
    /* Initialize a Timer for 1 ms period and
     * in its interrupt call
     * lv_tick_inc(1); */
    sigevent    sev;
    timer_t           timer;
    struct itimerspec its;
    int               retc;

    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_notify_function = &notifyFxn;
    sev.sigev_notify_attributes = NULL;

    retc = timer_create(CLOCK_MONOTONIC, &sev, &timer);
    if (retc != 0) {
        /* timer_create() failed */
        while(1);
    }

    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 1000000;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 1000000;

    retc = timer_settime(timer, 0, &its, NULL);
    if (retc != 0) {
        /* timer_settime() failed */
        while(1);
    }

    /***********************
     * Display interface
     ***********************/
    // Initialize display
    lv_port_disp_init();

    /****************
     * ADD A TITLE
     ****************/
    lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL);    // First parameters (scr) is the parent
    lv_label_set_text(label1, "LittlevGL Demo");                // Set the text
    lv_obj_align(label1, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);      // Align top middle of screen

    /* Create a marquee animation for the title */
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, label1, (lv_anim_exec_xcb_t) lv_obj_set_x);
    lv_anim_set_time(&a, 5000, 0);
    lv_anim_set_values(&a, -110, 128);               // Set start and end values.
    lv_anim_set_path_cb(&a, lv_anim_path_linear);    // Set path from `lv_anim_path_...` functions or a custom one.
    lv_anim_set_repeat(&a, 0);                       // Enable repeat of the animation with 0 ms delay.
    lv_anim_create(&a);

    /* Create the first image without re-color */
    lv_obj_t * img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, &ti_logo_96_indexed_2colors);
    lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, 0);


    /* Create an array for the points of the line */
    static lv_point_t line_points[] = {{10, 10}, {117, 10}, {117, 117}, {10, 117}, {10, 10}};

    /* Create new style (thin light blue) */
    static lv_style_t style_line1;
    lv_style_copy(&style_line1, &lv_style_plain);
    style_line1.line.width = 1;

    /* Copy the previous line and apply the new style */
    lv_obj_t * line1 = lv_line_create(lv_scr_act(), NULL);
    lv_line_set_points(line1, line_points, 5);     // Set the points
    lv_line_set_style(line1, LV_LINE_STYLE_MAIN, &style_line1);
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

    while (1) {
        lv_task_handler();
        usleep(5000);
    }
}
