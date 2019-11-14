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
 * @file ti_lvgl_ssd2119_disp.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <lv_port_disp.h>
#include <lv_drv_conf.h>
#include LV_DRV_DISP_INCLUDE
#include LV_DRV_DELAY_INCLUDE

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

static void ssd2119_reset(void);
static void ssd2119_reg_init(void);
static void ssd2119_init_bl(void);

static inline void ssd2119_cmd_mode(void);
static inline void ssd2119_data_mode(void);
static inline void ssd2119_cmd(uint8_t cmd);
static inline void ssd2119_data(uint16_t data);
static inline void ssd2119_array(uint8_t *array, uint32_t length);

/**********************
 *  STATIC VARIABLES
 **********************/
static bool cmd_mode = true;
static uint8_t color_array[LV_HOR_RES_MAX * 10 * 2];

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

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
    disp_drv.hor_res = 320;
    disp_drv.ver_res = 240;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.buffer = &disp_buf;

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

/* Initialize your display and the required peripherals. */
static void disp_init(void)
{
    /*You code here*/
    spi_init();
    ssd2119_reset();
    ssd2119_reg_init();
    ssd2119_init_bl();

    LV_DRV_DELAY_MS(30);
}

/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished. */
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

    /*Return if the area is out the screen*/
    if(area->x2 < 0) return;
    if(area->y2 < 0) return;
    if(area->x1 > LV_HOR_RES - 1) return;
    if(area->y1 > LV_VER_RES - 1) return;

    ssd2119_cmd(SSD2119_ENTRY_MODE_REG);
    ssd2119_data(MAKE_ENTRY_MODE(HORIZ_DIRECTION));

    ssd2119_cmd(SSD2119_H_RAM_START_REG);
    ssd2119_data(MAPPED_X(area->x2, area->y2));

    ssd2119_cmd(SSD2119_H_RAM_END_REG);
    ssd2119_data(MAPPED_X(area->x1, area->y1));

    ssd2119_cmd(SSD2119_V_RAM_POS_REG);
    ssd2119_data(MAPPED_Y(area->x2, area->y2) |
             (MAPPED_Y(area->x1, area->y1) << 8));

    ssd2119_cmd(SSD2119_X_RAM_ADDR_REG);
    ssd2119_data(MAPPED_X(area->x1, area->y1));

    ssd2119_cmd(SSD2119_Y_RAM_ADDR_REG);
    ssd2119_data(MAPPED_Y(area->x1, area->y1));

    ssd2119_cmd(SSD2119_RAM_DATA_REG);

    uint32_t size = (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1);
    uint32_t i;

    for(i = 0; i < (size*2); i+=2) {
        uint16_t color = lv_color_to16(*color_p);
        color_array[i] = color >> 8;
        color_array[i+1] = color;
        color_p++;
    }
    ssd2119_array(color_array, size*2);

    //
    // Reset the X extents to the entire screen.
    //
    ssd2119_cmd(SSD2119_H_RAM_START_REG);
    ssd2119_data(0x0000);
    ssd2119_cmd(SSD2119_H_RAM_END_REG);
    ssd2119_data(0x013F);

    //
    // Reset the Y extent to the full screen
    //
    ssd2119_cmd(SSD2119_V_RAM_POS_REG);
    ssd2119_data(0xEF00);

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

static void ssd2119_reset(void)
{
    /*Hardware reset*/
    LV_DRV_DISP_RST(0);
    LV_DRV_DELAY_MS(10);
    LV_DRV_DISP_RST(1);
    LV_DRV_DELAY_MS(20);

}


static void ssd2119_reg_init(void)
{
    LV_DRV_DELAY_MS(250);

    // Enter sleep mode (if we are not already there).
    ssd2119_cmd(SSD2119_SLEEP_MODE_1_REG);
    ssd2119_data(0x0001);

    // Set initial power parameters.
    ssd2119_cmd(SSD2119_PWR_CTRL_5_REG);
    ssd2119_data(0x00BA);
    ssd2119_cmd(SSD2119_VCOM_OTP_1_REG);
    ssd2119_data(0x0006);

    // Start the oscillator
    ssd2119_cmd(SSD2119_OSC_START_REG);
    ssd2119_data(0x0001);

    // Set pixel format and basic display orientation (scanning direction).
    ssd2119_cmd(SSD2119_OUTPUT_CTRL_REG);
    ssd2119_data(0x30EF);
    ssd2119_cmd(SSD2119_LCD_DRIVE_AC_CTRL_REG);
    ssd2119_data(0x0600);

    // Exit sleep mode.
    ssd2119_cmd(SSD2119_SLEEP_MODE_1_REG);
    ssd2119_data(0x0000);

    // Delay 30mS
    LV_DRV_DELAY_MS(30);

    // Configure pixel color format and MCU interface parameters.
    ssd2119_cmd(SSD2119_ENTRY_MODE_REG);
    ssd2119_data(ENTRY_MODE_DEFAULT);

    // Enable the display.
    ssd2119_cmd(SSD2119_DISPLAY_CTRL_REG);
    ssd2119_data(0x0033);

    // Set VCIX2 voltage to 6.1V.
    ssd2119_cmd(SSD2119_PWR_CTRL_2_REG);
    ssd2119_data(0x0005);

    // Configure gamma correction.
    ssd2119_cmd(SSD2119_GAMMA_CTRL_1_REG);
    ssd2119_data(0x0000);
    ssd2119_cmd(SSD2119_GAMMA_CTRL_2_REG);
    ssd2119_data(0x0400);
    ssd2119_cmd(SSD2119_GAMMA_CTRL_3_REG);
    ssd2119_data(0x0106);
    ssd2119_cmd(SSD2119_GAMMA_CTRL_4_REG);
    ssd2119_data(0x0700);
    ssd2119_cmd(SSD2119_GAMMA_CTRL_5_REG);
    ssd2119_data(0x0002);
    ssd2119_cmd(SSD2119_GAMMA_CTRL_6_REG);
    ssd2119_data(0x0702);
    ssd2119_cmd(SSD2119_GAMMA_CTRL_7_REG);
    ssd2119_data(0x0707);
    ssd2119_cmd(SSD2119_GAMMA_CTRL_8_REG);
    ssd2119_data(0x0203);
    ssd2119_cmd(SSD2119_GAMMA_CTRL_9_REG);
    ssd2119_data(0x1400);
    ssd2119_cmd(SSD2119_GAMMA_CTRL_10_REG);
    ssd2119_data(0x0F03);

    // Configure Vlcd63 and VCOMl.
    ssd2119_cmd(SSD2119_PWR_CTRL_3_REG);
    ssd2119_data(0x0007);
    ssd2119_cmd(SSD2119_PWR_CTRL_4_REG);
    ssd2119_data(0x3100);

    // Set the display size and ensure that the GRAM window is set to allow
    // access to the full display buffer.
    ssd2119_cmd(SSD2119_V_RAM_POS_REG);
    ssd2119_data((LV_VER_RES-1) << 8);
    ssd2119_cmd(SSD2119_H_RAM_START_REG);
    ssd2119_data(0x0000);
    ssd2119_cmd(SSD2119_H_RAM_END_REG);
    ssd2119_data(LV_HOR_RES-1);
    ssd2119_cmd(SSD2119_X_RAM_ADDR_REG);
    ssd2119_data(0x00);
    ssd2119_cmd(SSD2119_Y_RAM_ADDR_REG);
    ssd2119_data(0x00);
}


static void ssd2119_init_bl(void)
{
    LV_DRV_DISP_BACKLIGHT(1);
}


/**
 * Command mode
 */
static inline void ssd2119_cmd_mode(void)
{
    if(cmd_mode == false) {
        LV_DRV_DISP_CMD_DATA(SSD2119_CMD_MODE);
        cmd_mode = true;
    }
}

/**
 * Data mode
 */
static inline void ssd2119_data_mode(void)
{
    if(cmd_mode != false) {
        LV_DRV_DISP_CMD_DATA(SSD2119_DATA_MODE);
        cmd_mode = false;
    }
}

/**
 * Write command
 * @param cmd the command
 */
static inline void ssd2119_cmd(uint8_t cmd)
{
    ssd2119_cmd_mode();
    LV_DRV_DISP_SPI_CS(0);
    LV_DRV_DISP_SPI_WR_WORD(cmd);
    LV_DRV_DISP_SPI_CS(1);
}

/**
 * Write data
 * @param data the data
 */
static inline void ssd2119_data(uint16_t data)
{
    ssd2119_data_mode();
    LV_DRV_DISP_SPI_CS(0);
    LV_DRV_DISP_SPI_WR_WORD(data);
    LV_DRV_DISP_SPI_CS(1);
}

/**
 * Write array
 * @param array the data array
 */
static inline void ssd2119_array(uint8_t * array, uint32_t length)
{
    ssd2119_data_mode();
    LV_DRV_DISP_SPI_CS(0);
    LV_DRV_DISP_SPI_WR_ARRAY(array, length);
    LV_DRV_DISP_SPI_CS(1);
}

/*OPTIONAL: GPU INTERFACE*/
#if USE_LV_GPU

/* If your MCU has hardware accelerator (GPU) then you can use it to blend to memories using opacity
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/
static void mem_blend(lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa)
{
    /*It's an example code which should be done by your GPU*/

    uint32_t i;
    for(i = 0; i < length; i++) {
        dest[i] = lv_color_mix(dest[i], src[i], opa);
    }
}

/* If your MCU has hardware accelerator (GPU) then you can use it to fill a memory with a color
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/
static void mem_fill(lv_color_t * dest, uint32_t length, lv_color_t color)
{
    /*It's an example code which should be done by your GPU*/

    uint32_t i;
    for(i = 0; i < length; i++) {
        dest[i] = color;
    }
}

#endif  /*USE_LV_GPU*/
