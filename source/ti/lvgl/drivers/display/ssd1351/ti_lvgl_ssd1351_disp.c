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
 * @file ti_lvgl_ssd1351_disp.c
 *
 * Araknid Notes: Based on SSD2119 file and other ssd1351 projects online. 
 * GPIO 0x02 is used to drive Vcc -> +13Vdd for OLED driver.
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

static void ssd1351_reset(void);
static void ssd1351_reg_init(void);
static void ssd1351_init_bl(void);

static inline void ssd1351_cmd_mode(void);
static inline void ssd1351_data_mode(void);
static inline void ssd1351_cmd(uint8_t cmd);
static inline void ssd1351_data(uint8_t data);
static inline void ssd1351_array(uint8_t *array, uint32_t length);

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
    disp_drv.hor_res = 128;
    disp_drv.ver_res = 96;

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
    ssd1351_reset();
    ssd1351_reg_init();
    ssd1351_init_bl();

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

    ssd1351_cmd(SSD1351_CMD_SET_COLUMN_REG);
    ssd1351_array((uint8_t[]){ area->x1, area->x2},2);
    //    MAPPED_X(area->x1, area->y1),
    //    MAPPED_X(area->x2, area->y2)},
    //2);

    ssd1351_cmd(SSD1351_CMD_SET_ROW_REG);
    ssd1351_array((uint8_t[]){ area->y1, area->y2},2);
    //    MAPPED_Y(area->x1, area->y1),
    //    MAPPED_Y(area->x2, area->y2)},
    //2);

    ssd1351_cmd(SSD1351_CMD_WRITERAM_REG);

    uint32_t size = (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1);
    uint32_t i;

    for(i = 0; i < (size*2); i+=2) {
        uint16_t color = lv_color_to16(*color_p);
        color_array[i] = color >> 8;
        color_array[i+1] = color;
        color_p++;
    }
    ssd1351_array(color_array, size*2);

    //
    // Reset the X and Y extents to the entire screen.
    //
    ssd1351_cmd(SSD1351_CMD_SET_COLUMN_REG);
    ssd1351_array((uint8_t[]){0,LV_HOR_RES_MAX}, 2);


    ssd1351_cmd(SSD1351_CMD_SET_ROW_REG);
    ssd1351_array((uint8_t[]){0,LV_VER_RES_MAX}, 2);

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

static void ssd1351_reset(void)
{
    /*Hardware reset*/
    LV_DRV_DISP_RST(0);
    LV_DRV_DELAY_MS(10);
    LV_DRV_DISP_RST(1);
    LV_DRV_DELAY_MS(20);

}


static void ssd1351_reg_init(void)
{
    /* Physical display size */
    static const uint8_t    SSD_COMMANDLOCK1        =   0x12;
    static const uint8_t    SSD_COMMANDLOCK2        =   0xB1;
    static const uint8_t    SSD_MUXRATIO            =   0x5F;
    static const uint8_t    SSD_SETGPIO             =   0x0F;
    static const uint8_t    SSD_PRECHARGE2          =   0x01;
    static const uint8_t    SSD_FUNCTIONSELECT      =   0x01;
    static const uint8_t    SSD_DISPLAYOFFSET       =   0x00;
    static const uint8_t    SSD_PRECHARGE           =   0x32; // set reset / pre-charge period - phase 2: 3 DCLKs, phase 1: 5 DCLKs
    static const uint8_t    SSD_CLOCKDIV            =   0xF1;
    static const uint8_t    SSD_SETVSL_A            =   0xA0;
    static const uint8_t    SSD_SETVSL_B            =   0xB5;
    static const uint8_t    SSD_SETVSL_C            =   0x55;
    static const uint8_t    SSD_VCOMH               =   0x05; // set VComH voltage - 0.82*Vcc
    static const uint8_t    SSD_MASTERCURRENT       =   0x0F; // master contrast current control - no change
    static const uint8_t    SSD_CONTRAST_A          =   0xC8;
    static const uint8_t    SSD_CONTRAST_B          =   0x80;
    static const uint8_t    SSD_CONTRAST_C          =   0xC8;
    static const uint8_t    SSD_PRECHARGELEVEL      =   0x17; // set pre-charge voltage - 0.6*Vcc

    uint8_t oledRemap;

    oledRemap = 0b01100100 | HORIZ_DIRECTION;
    // [0] : address increment (0: horizontal, 1: vertical, reset 0)
    // [1] : column remap (0: 0..127, 1: 127..0, reset 0)
    // [2] : color remap (0: A->B->C, 1: C->B->A, reset 0)
    // [3] : reserved
    // [4] : column scan direction (0: top->down, 1: bottom->up, reset 0)
    // [5] : odd/even split COM (0: disable, 1: enable, reset 1)
    // [6..7] : color depth (00,01: 65k, 10: 262k, 11: 262k format 2)

    LV_DRV_DELAY_MS(250);

    ssd1351_cmd (SSD1351_CMD_SET_COMMAND_LOCK_REG);
    ssd1351_data (SSD_COMMANDLOCK1);

    ssd1351_cmd(SSD1351_CMD_SET_COMMAND_LOCK_REG);
    ssd1351_data (SSD_COMMANDLOCK2);

    ssd1351_cmd (SSD1351_CMD_SET_SLEEP_ON_REF);

    ssd1351_cmd (SSD1351_CMD_SET_GPIO_REG);
    ssd1351_data (SSD_SETGPIO);

    // Delay 30mS
    LV_DRV_DELAY_MS(30);

    ssd1351_cmd (SSD1351_CMD_SET_CLOCKDIV_REG);
    ssd1351_data (SSD_CLOCKDIV);

    ssd1351_cmd (SSD1351_CMD_SET_MUX_RATIO_REG);
    ssd1351_data (SSD_MUXRATIO);

    ssd1351_cmd (SSD1351_CMD_SET_REMAP_REG);
    ssd1351_data(oledRemap);

    ssd1351_cmd (SSD1351_CMD_SET_COLUMN_REG);
    ssd1351_array((uint8_t[] ) { 0x00, LV_HOR_RES }, 2);

    ssd1351_cmd (SSD1351_CMD_SET_ROW_REG);
    ssd1351_array((uint8_t[] ) { 0x00, LV_VER_RES }, 2);

    ssd1351_cmd (SSD1351_CMD_SET_STARTLINE_REG);
    ssd1351_data(0);

    ssd1351_cmd (SSD1351_CMD_SET_DISPLAY_OFFSET_REG);
    ssd1351_data (SSD_DISPLAYOFFSET);

    ssd1351_cmd (SSD1351_CMD_SET_FUNCTION_SELECT_REG);
    ssd1351_data (SSD_FUNCTIONSELECT);

    // Delay 1mS
    LV_DRV_DELAY_MS(1);

    ssd1351_cmd (SSD1351_CMD_SET_PRECHARGE_REG);
    ssd1351_data (SSD_PRECHARGE);

    ssd1351_cmd (SSD1351_CMD_SET_VCOMH_REG);
    ssd1351_data (SSD_VCOMH);

    ssd1351_cmd (SSD1351_CMD_SET_PRECHARGE_LEVEL_REG);
    ssd1351_data (SSD_PRECHARGELEVEL);

    ssd1351_cmd (SSD1351_CMD_SET_CONTRAST_ABC_REG);
    ssd1351_array(
            (uint8_t[] ) { SSD_CONTRAST_A, SSD_CONTRAST_B, SSD_CONTRAST_C },
            3);

    ssd1351_cmd (SSD1351_CMD_SET_CONTRAST_MASTER_REG);
    ssd1351_data (SSD_MASTERCURRENT);

    ssd1351_cmd (SSD1351_CMD_SET_VSL_REG);
    ssd1351_array((uint8_t[] ) { SSD_SETVSL_A, SSD_SETVSL_B, SSD_SETVSL_C }, 3);

    ssd1351_cmd (SSD1351_CMD_SET_PRECHARGE2_REG);
    ssd1351_data (SSD_PRECHARGE2);

    ssd1351_cmd (SSD1351_CMD_SET_SLEEP_OFF_REF);

    // Delay 30mS
    LV_DRV_DELAY_MS(30);
}


static void ssd1351_init_bl(void)
{
    ssd1351_cmd (SSD1351_CMD_SET_DISPLAY_NORMAL_REG);
}


/**
 * Command mode
 */
static inline void ssd1351_cmd_mode(void)
{
    if(cmd_mode == false) {
        LV_DRV_DISP_CMD_DATA(SSD1351_CMD_MODE);
        cmd_mode = true;
    }
}

/**
 * Data mode
 */
static inline void ssd1351_data_mode(void)
{
    if(cmd_mode != false) {
        LV_DRV_DISP_CMD_DATA(SSD1351_DATA_MODE);
        cmd_mode = false;
    }
}

/**
 * Write command
 * @param cmd the command
 */
static inline void ssd1351_cmd(uint8_t cmd)
{
    ssd1351_cmd_mode();
    LV_DRV_DISP_SPI_CS(0);
    LV_DRV_DISP_SPI_WR_BYTE(cmd);
    LV_DRV_DISP_SPI_CS(1);
}

/**
 * Write data
 * @param data the data
 */
static inline void ssd1351_data(uint8_t data)
{
    ssd1351_data_mode();
    LV_DRV_DISP_SPI_CS(0);
    LV_DRV_DISP_SPI_WR_BYTE(data);
    LV_DRV_DISP_SPI_CS(1);
}

/**
 * Write array
 * @param array the data array
 */
static inline void ssd1351_array(uint8_t * array, uint32_t length)
{
    ssd1351_data_mode();
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
