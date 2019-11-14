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
 *  ======== kentectouchwidgets.c ========
 */

/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

/* POSIX Header files */
#include <pthread.h>

/* Driver Header files */
#include <ti/drivers/ADC.h>
#include <ti/drivers/GPIO.h>

/* Board Header file */
#include "Board.h"

/* lvgl Includes */
#include <lv_port_disp.h>
#include <lv_port_indev.h>

/*
 * Notification function called when the posix timer expires
 */
void notifyFxn(sigval val)
{
    lv_tick_inc(1);
}

/*Called when there's a new event on the slider*/
static void slider_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        /* Slider value updated
         * Do something here */
    }
}

/*Called when there's a new event on the button*/
static void button_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        /* The button is clicked.
         * Do something here */
    }
}

/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    /* Call driver init functions */
    GPIO_init();
    ADC_init();

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

    // Initialize input device
    lv_port_indev_init();

    /* Set theme to Material theme */
    lv_theme_t * th = lv_theme_material_init(0, NULL);    // Set a HUE value and a Font for the Night Theme
    lv_theme_set_current(th);                             // Apply the theme

    /* Create a Tab view object */
    lv_obj_t *tabview;
    tabview = lv_tabview_create(lv_scr_act(), NULL);
    lv_tabview_set_sliding(tabview, false);

    /* Add 3 tabs (the tabs are page (lv_page) and can be scrolled */
    lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "Tab 1");
    lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "Tab 2");
    lv_obj_t *tab3 = lv_tabview_add_tab(tabview, "Tab 3");

    /* Create a style */
    static lv_style_t style;
    lv_style_copy(&style, &lv_style_plain);    // Copy a built-in style to initialize the new style
    style.body.grad_color= LV_COLOR_SILVER;

    /* Create a style */
    static lv_style_t style1;
    lv_style_copy(&style1, lv_obj_get_style(tabview));    // Copy a built-in style to initialize the new style
    style1.body.padding.top = 2;
    style1.body.padding.bottom = 2;
    lv_tabview_set_style(tabview, LV_TABVIEW_STYLE_BTN_BG, &style1);

    /* Create a style */
    static lv_style_t style2;
    lv_style_copy(&style2, lv_obj_get_style(tabview));    // Copy a built-in style to initialize the new style
    style2.body.padding.top = 3;
    style2.body.padding.bottom = 3;
    lv_tabview_set_style(tabview, LV_TABVIEW_STYLE_BTN_REL, &style2);

    /****************
     * ADD A TITLE
     ****************/
    lv_obj_t * label = lv_label_create(tab1, NULL);           // First parameters (scr) is the parent
    lv_label_set_text(label, "LittlevGL Demo");               // Set the text
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);    // Align top-middle of tabview

    /****************
     * ADD A SLIDER
     ****************/
    lv_obj_t * slider = lv_slider_create(tab1, NULL);                    // Create a slider
    lv_obj_set_size(slider, lv_obj_get_width(tab1)  / 2, LV_DPI / 3);    // Set the size
    lv_obj_align(slider, label, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);         // Align below the title label
    lv_obj_set_event_cb(slider, slider_event_handler);                   // Set event handler
    lv_slider_set_value(slider, 30, LV_ANIM_OFF);                        // Set the current value

    /* Create a button */
    lv_obj_t * btn1 = lv_btn_create(tab1, NULL);                   // Create a button on the currently loaded screen
    lv_obj_set_event_cb(btn1, button_event_handler);               // Set function to be called when the button is released
    lv_obj_align(btn1, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);    // Align below the slider

    /* Create a label on the button (the 'label' variable can be reused) */
    label = lv_label_create(btn1, NULL);
    lv_label_set_text(label, "Button 1");

    /* Create check box */
    lv_obj_t * cb;
    cb = lv_cb_create(tab2, NULL);
    lv_cb_set_text(cb, "Checkbox");
    lv_obj_align(cb, tab2, LV_ALIGN_IN_TOP_MID, 0, 20);

    /* Create a drop down list */
    lv_obj_t * ddl1 = lv_ddlist_create(tab2, NULL);
    lv_ddlist_set_options(ddl1, "Option 1\n"
                                "Option 2\n"
                                "Option 3");
    lv_obj_align(ddl1, cb, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    /* Create a style for the chart */
    static lv_style_t style_chart;
    lv_style_copy(&style_chart, &lv_style_pretty);
    style_chart.line.color = LV_COLOR_GRAY;

    /* Create a chart */
    lv_obj_t * chart;
    chart = lv_chart_create(tab3, NULL);
    lv_obj_set_size(chart, 200, 150);
    lv_obj_set_style(chart, &style_chart);
    lv_obj_align(chart, tab3, LV_ALIGN_CENTER, 0, 0);
    lv_chart_set_series_width(chart, 4);    // Line width and point radius

    lv_chart_set_range(chart, 0, 100);

    /* Add two data series */
    lv_chart_series_t * ser1 = lv_chart_add_series(chart, LV_COLOR_RED);
    lv_chart_series_t * ser2 = lv_chart_add_series(chart, LV_COLOR_GREEN);

    /* Set the next points on 'dl1' */
    lv_chart_set_next(chart, ser1, 10);
    lv_chart_set_next(chart, ser1, 50);
    lv_chart_set_next(chart, ser1, 70);
    lv_chart_set_next(chart, ser1, 90);

    /* Directly set points on 'dl2' */
    ser2->points[0] = 90;
    ser2->points[1] = 70;
    ser2->points[2] = 65;
    ser2->points[3] = 65;
    ser2->points[4] = 65;
    ser2->points[5] = 65;

    /* Required after direct set */
    lv_chart_refresh(chart);

    while (1) {
        lv_task_handler();
        usleep(5000);
    }
}
