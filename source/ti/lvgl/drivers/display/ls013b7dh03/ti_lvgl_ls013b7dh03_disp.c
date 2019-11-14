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
 * @file ti_lvgl_ls013b7dh03_disp.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <lv_port_disp.h>
#include <lv_drv_conf.h>
#include LV_DRV_DISP_INCLUDE

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);

static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p);
#if LV_USE_GPU
static void gpu_blend(lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa);
static void gpu_fill(lv_color_t * dest, uint32_t length, lv_color_t color);
#endif
static uint8_t reverse(uint8_t x);

/**********************
 *  STATIC VARIABLES
 **********************/
unsigned char VCOMbit= 0x40;
static const uint8_t referse_data[] = { 0x0, 0x8, 0x4, 0xC, 0x2, 0xA, 0x6, 0xE, 0x1, 0x9, 0x5, 0xD, 0x3, 0xB, 0x7, 0xF };

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void my_rounder(struct _disp_drv_t * disp_drv, lv_area_t * area)
{
    // Modify invalidate area to cover entire horizontal lines.
    area->x1 = 0;
    area->x2 = LV_HOR_RES - 1;
}

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*-----------------------------
     * Create a buffer for drawing
     *----------------------------*/
    static lv_disp_buf_t disp_buf;
    static lv_color_t buf[LV_HOR_RES_MAX * 10];                      /*A buffer for 10 rows*/
    lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * 10);   /*Initialize the display buffer*/

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = 128;
    disp_drv.ver_res = 128;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.buffer = &disp_buf;

    /*Set invalidate area rounder callback*/
    disp_drv.rounder_cb = my_rounder;

#if LV_USE_GPU
    /*Optionally add functions to access the GPU. (Only in buffered mode, LV_VDB_SIZE != 0)*/

    /*Blend two color array using opacity*/
    disp_drv.gpu_blend = gpu_blend;

    /*Fill a memory array with a color*/
    disp_drv.gpu_fill = gpu_fill;
#endif

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*
 * Reverses the bit order.- Since the bit reversal function is called
 * frequently by the several driver function this function is implemented
 * to maximize code execution
 *
 */
static uint8_t reverse(uint8_t x)
{
    uint8_t b = 0;

    b  = referse_data[x & 0xF] << 4;
    b |= referse_data[(x & 0xF0) >> 4];
    return b;
}

/* Initialize your display and the required peripherals. */
static void disp_init(void)
{
    /*You code here*/
    spi_init();
    LV_DRV_DISP_POWER(1);
    LV_DRV_DISP_ENABLE(1);
    LV_DRV_DISP_SPI_CS(0);

    unsigned char command = SHARP_LCD_CMD_CLEAR_SCREEN;

    LV_DRV_DISP_SPI_CS(1);
    LV_DRV_DISP_SPI_WR_BYTE(command);
    LV_DRV_DISP_SPI_WR_BYTE(SHARP_LCD_TRAILER_BYTE);
    LV_DRV_DISP_SPI_CS(0);

}

/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished. */
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

    unsigned char command = SHARP_LCD_CMD_WRITE_LINE;

    //COM inversion bit
    command = command^VCOMbit;

    // Set CS High
    LV_DRV_DISP_SPI_CS(1);

    LV_DRV_DISP_SPI_WR_BYTE(command);

    int32_t x;
    int32_t y;
    int32_t i;
    for(y = area->y1; y <= area->y2; y++) {
        LV_DRV_DISP_SPI_WR_BYTE(reverse(y + 1));
        for(x = area->x1; x <= area->x2; x+=8) {
            /* Put a pixel to the display. For example: */
            /* put_px(x, y, *color_p)*/
            uint8_t byte = 0;
            for (i = 7; i>=0; i--) {
                byte |= (color_p->full)<<i;
                color_p++;
            }
            LV_DRV_DISP_SPI_WR_BYTE(byte);
        }
        LV_DRV_DISP_SPI_WR_BYTE(SHARP_LCD_TRAILER_BYTE);
    }

    // Set CS Low
    LV_DRV_DISP_SPI_CS(0);

    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);
}

/*OPTIONAL: GPU INTERFACE*/
#if LV_USE_GPU

/* If your MCU has hardware accelerator (GPU) then you can use it to blend to memories using opacity
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/
static void gpu_blend(lv_disp_drv_t * disp_drv, lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa)
{
    /*It's an example code which should be done by your GPU*/

    uint32_t i;
    for(i = 0; i < length; i++) {
        dest[i] = lv_color_mix(dest[i], src[i], opa);
    }
}

/* If your MCU has hardware accelerator (GPU) then you can use it to fill a memory with a color
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/
static void gpu_fill_cb(lv_disp_drv_t * disp_drv, lv_color_t * dest_buf, lv_coord_t dest_width,
                    const lv_area_t * fill_area, lv_color_t color);
{
    /*It's an example code which should be done by your GPU*/
    uint32_t x, y;
    dest_buf += dest_width * fill_area->y1; /*Go to the first line*/

    for(y = fill_area->y1; y < fill_area->y2; y++) {
        for(x = fill_area->x1; x < fill_area->x2; x++) {
            dest_buf[x] = color;
        }
        dest_buf+=dest_width;    /*Go to the next line*/
    }


    uint32_t i;
    for(i = 0; i < length; i++) {
        dest[i] = color;
    }
}

#endif  /*LV_USE_GPU*/
