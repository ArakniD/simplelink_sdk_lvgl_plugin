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
 * @file lv_drv_conf.h
 *
 */


#ifndef LV_DRV_CONF_H
#define LV_DRV_CONF_H

#include "lv_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

#define USE_SSD2119     1

/*********************
 * DELAY INTERFACE
 *********************/
#define LV_DRV_DELAY_INCLUDE  <unistd.h>
#define LV_DRV_DELAY_US(us)  usleep(us)       /*Delay the given number of microseconds*/
#define LV_DRV_DELAY_MS(ms)  usleep(1000*ms)       /*Delay the given number of milliseconds*/

/*********************
 * DISPLAY INTERFACE
 *********************/

/*------------
 *  Common
 *------------*/
#define LV_DRV_DISP_INCLUDE         <ti_lvgl_disp_interface.h>
#define LV_DRV_DISP_CMD_DATA(val)  GPIO_write(Board_GPIO_KENTEC_LCD_DC, val)    /*Set the command/data pin to 'val'*/
#define LV_DRV_DISP_RST(val)       GPIO_write(Board_GPIO_KENTEC_LCD_RESET, val)    /*Set the reset pin to 'val'*/
#define LV_DRV_DISP_BACKLIGHT(val) GPIO_write(Board_GPIO_KENTEC_LCD_BACKLIGHT, val)    /*Set the backlight pin to 'val'*/

/*---------
 *  SPI
 *---------*/
#define LV_DRV_DISP_SPI_BITRATE          24000000
#define LV_DRV_DISP_SPI_CS(val)          GPIO_write(Board_GPIO_KENTEC_LCD_CS, val);     /*Set the SPI's Chip select to 'val'*/
#define LV_DRV_DISP_SPI_WR_BYTE(data)    spi_wr_byte(data)        /*Write a byte the SPI bus*/
#define LV_DRV_DISP_SPI_WR_WORD(data)    spi_wr_word(data)        /*Write a word the SPI bus*/
#define LV_DRV_DISP_SPI_WR_ARRAY(adr, n) spi_wr_array(adr, n)     /*Write 'n' bytes to SPI bus from 'adr'*/

/*------------------
 *  Parallel port
 *-----------------*/
#define LV_DRV_DISP_PAR_CS(val)          /*par_cs_set(val)*/   /*Set the Parallel port's Chip select to 'val'*/
#define LV_DRV_DISP_PAR_SLOW             /*par_slow()*/        /*Set low speed on the parallel port*/
#define LV_DRV_DISP_PAR_FAST             /*par_fast()*/        /*Set high speed on the parallel port*/
#define LV_DRV_DISP_PAR_WR_WORD(data)    /*par_wr(data)*/      /*Write a word to the parallel port*/
#define LV_DRV_DISP_PAR_WR_ARRAY(adr, n) /*par_wr_mem(adr,n)*/ /*Write 'n' bytes to Parallel ports from 'adr'*/

/***************************
 * INPUT DEVICE INTERFACE
 ***************************/

/*----------
 *  Common
 *----------*/
#define LV_DRV_INDEV_INCLUDE     <stdint.h>             /*Dummy include by default*/
#define LV_DRV_INDEV_RST(val)    /*pin_x_set(val)*/     /*Set the reset pin to 'val'*/
#define LV_DRV_INDEV_IRQ_READ    0 /*pn_x_read()*/      /*Read the IRQ pin*/

/*---------
 *  SPI
 *---------*/
#define LV_DRV_INDEV_SPI_CS(val)            /*spi_cs_set(val)*/     /*Set the SPI's Chip select to 'val'*/
#define LV_DRV_INDEV_SPI_XCHG_BYTE(data)    0 /*spi_xchg(val)*/     /*Write 'val' to SPI and give the read value*/

/*---------
 *  I2C
 *---------*/
#define LV_DRV_INDEV_I2C_START              /*i2c_start()*/       /*Make an I2C start*/
#define LV_DRV_INDEV_I2C_STOP               /*i2c_stop()*/        /*Make an I2C stop*/
#define LV_DRV_INDEV_I2C_RESTART            /*i2c_restart()*/     /*Make an I2C restart*/
#define LV_DRV_INDEV_I2C_WR(data)           /*i2c_wr(data)*/      /*Write a byte to the I1C bus*/
#define LV_DRV_INDEV_I2C_READ(last_read)    0 /*i2c_rd()*/        /*Read a byte from the I2C bud*/

/*********************
 *  DISPLAY DRIVERS
 *********************/

/*-------------------
 *  Monitor of PC
 *-------------------*/
#ifndef USE_MONITOR
#  define USE_MONITOR         0
#endif

#if USE_MONITOR
#  define MONITOR_HOR_RES     LV_HOR_RES
#  define MONITOR_VER_RES     LV_VER_RES

/* Scale window by this factor (useful when simulating small screens) */
#  define MONITOR_ZOOM        1

/* Used to test true double buffering with only address changing.
 * Set LV_VDB_SIZE = (LV_HOR_RES * LV_VER_RES) and  LV_VDB_DOUBLE = 1 and LV_COLOR_DEPTH = 32" */
#  define MONITOR_DOUBLE_BUFFERED 0

/*Eclipse: <SDL2/SDL.h>    Visual Studio: <SDL.h>*/
#  define MONITOR_SDL_INCLUDE_PATH    <SDL2/SDL.h>

/*Different rendering might be used if running in a Virtual machine*/
#  define MONITOR_VIRTUAL_MACHINE 0
#endif

/*-----------------------------------
 *  Native Windows (including mouse)
 *----------------------------------*/
#ifndef USE_WINDOWS
#  define USE_WINDOWS       0
#endif

#define USE_WINDOWS         0
#if USE_WINDOWS
#  define WINDOW_HOR_RES      LV_HOR_RES
#  define WINDOW_VER_RES      LV_VER_RES
#endif

/*----------------
 *    LS013B7DH03
 *--------------*/
#ifndef USE_LS013B7DH03
#  define USE_LS013B7DH03         0
#endif

#if USE_LS013B7DH03
#define SHARP_SEND_TOGGLE_VCOM_COMMAND      0x01
#define SHARP_SKIP_TOGGLE_VCOM_COMMAND      0x00

#define SHARP_LCD_TRAILER_BYTE              0x00

#define SHARP_VCOM_TOGGLE_BIT               0x40

#define SHARP_LCD_CMD_CHANGE_VCOM           0x00
#define SHARP_LCD_CMD_CLEAR_SCREEN          0x20
#define SHARP_LCD_CMD_WRITE_LINE            0x80
#endif

/*----------------
 *    SSD2119
 *--------------*/
#ifndef USE_SSD2119
#  define USE_SSD2119         0
#endif

#if USE_SSD2119
// If no screen orientation is selected, "landscape" mode will be used.
#if ! defined(PORTRAIT) && ! defined(PORTRAIT_FLIP) && \
   ! defined(LANDSCAPE) && ! defined(LANDSCAPE_FLIP)
#define LANDSCAPE
#endif

#ifdef PORTRAIT
#define HORIZ_DIRECTION 0x28
#define VERT_DIRECTION 0x20
#define MAPPED_X(x, y) (LV_HOR_RES - 1 - (y))
#define MAPPED_Y(x, y) (x)
#endif
#ifdef LANDSCAPE
#define HORIZ_DIRECTION 0x00
#define VERT_DIRECTION  0x08
#define MAPPED_X(x, y) (LV_HOR_RES - 1 - (x))
#define MAPPED_Y(x, y) (LV_VER_RES - 1 - (y))
#endif
#ifdef PORTRAIT_FLIP
#define HORIZ_DIRECTION 0x18
#define VERT_DIRECTION 0x10
#define MAPPED_X(x, y) (y)
#define MAPPED_Y(x, y) (LV_VER_RES - 1 - (x))
#endif
#ifdef LANDSCAPE_FLIP
#define HORIZ_DIRECTION 0x30
#define VERT_DIRECTION  0x38
#define MAPPED_X(x, y) (x)
#define MAPPED_Y(x, y) (y)
#endif

// Various internal SD2119 registers name labels
#define SSD2119_DEVICE_CODE_READ_REG  0x00
#define SSD2119_OSC_START_REG         0x00
#define SSD2119_OUTPUT_CTRL_REG       0x01
#define SSD2119_LCD_DRIVE_AC_CTRL_REG 0x02
#define SSD2119_PWR_CTRL_1_REG        0x03
#define SSD2119_DISPLAY_CTRL_REG      0x07
#define SSD2119_FRAME_CYCLE_CTRL_REG  0x0B
#define SSD2119_PWR_CTRL_2_REG        0x0C
#define SSD2119_PWR_CTRL_3_REG        0x0D
#define SSD2119_PWR_CTRL_4_REG        0x0E
#define SSD2119_GATE_SCAN_START_REG   0x0F
#define SSD2119_SLEEP_MODE_1_REG      0x10
#define SSD2119_ENTRY_MODE_REG        0x11
#define SSD2119_SLEEP_MODE_2_REG      0x12
#define SSD2119_GEN_IF_CTRL_REG       0x15
#define SSD2119_PWR_CTRL_5_REG        0x1E
#define SSD2119_RAM_DATA_REG          0x22
#define SSD2119_FRAME_FREQ_REG        0x25
#define SSD2119_ANALOG_SET_REG        0x26
#define SSD2119_VCOM_OTP_1_REG        0x28
#define SSD2119_VCOM_OTP_2_REG        0x29
#define SSD2119_GAMMA_CTRL_1_REG      0x30
#define SSD2119_GAMMA_CTRL_2_REG      0x31
#define SSD2119_GAMMA_CTRL_3_REG      0x32
#define SSD2119_GAMMA_CTRL_4_REG      0x33
#define SSD2119_GAMMA_CTRL_5_REG      0x34
#define SSD2119_GAMMA_CTRL_6_REG      0x35
#define SSD2119_GAMMA_CTRL_7_REG      0x36
#define SSD2119_GAMMA_CTRL_8_REG      0x37
#define SSD2119_GAMMA_CTRL_9_REG      0x3A
#define SSD2119_GAMMA_CTRL_10_REG     0x3B
#define SSD2119_V_RAM_POS_REG         0x44
#define SSD2119_H_RAM_START_REG       0x45
#define SSD2119_H_RAM_END_REG         0x46
#define SSD2119_X_RAM_ADDR_REG        0x4E
#define SSD2119_Y_RAM_ADDR_REG        0x4F

#define ENTRY_MODE_DEFAULT 0x6830
#define MAKE_ENTRY_MODE(x) ((ENTRY_MODE_DEFAULT & 0xFF00) | (x))

#define SSD2119_CMD_MODE     0
#define SSD2119_DATA_MODE    1
#endif

/*----------------
 *    SSD1963
 *--------------*/
#ifndef USE_SSD1963
#  define USE_SSD1963         0
#endif

#if USE_SSD1963
#  define SSD1963_HOR_RES     LV_HOR_RES
#  define SSD1963_VER_RES     LV_VER_RES
#  define SSD1963_HT          531
#  define SSD1963_HPS         43
#  define SSD1963_LPS         8
#  define SSD1963_HPW         10
#  define SSD1963_VT          288
#  define SSD1963_VPS         12
#  define SSD1963_FPS         4
#  define SSD1963_VPW         10
#  define SSD1963_HS_NEG      0   /*Negative hsync*/
#  define SSD1963_VS_NEG      0   /*Negative vsync*/
#  define SSD1963_ORI         0   /*0, 90, 180, 270*/
#  define SSD1963_COLOR_DEPTH 16
#endif

/*----------------
 *    R61581
 *--------------*/
#ifndef USE_R61581
#  define USE_R61581          0
#endif

#if USE_R61581
#  define R61581_HOR_RES      LV_HOR_RES
#  define R61581_VER_RES      LV_VER_RES
#  define R61581_HSPL         0       /*HSYNC signal polarity*/
#  define R61581_HSL          10      /*HSYNC length (Not Implemented)*/
#  define R61581_HFP          10      /*Horitontal Front poarch (Not Implemented)*/
#  define R61581_HBP          10      /*Horitontal Back poarch (Not Implemented */
#  define R61581_VSPL         0       /*VSYNC signal polarity*/
#  define R61581_VSL          10      /*VSYNC length (Not Implemented)*/
#  define R61581_VFP          8       /*Vertical Front poarch*/
#  define R61581_VBP          8       /*Vertical Back poarch */
#  define R61581_DPL          0       /*DCLK signal polarity*/
#  define R61581_EPL          1       /*ENABLE signal polarity*/
#  define R61581_ORI          0       /*0, 180*/
#  define R61581_LV_COLOR_DEPTH 16    /*Fix 16 bit*/
#endif

/*------------------------------
 *  ST7565 (Monochrome, low res.)
 *-----------------------------*/
#ifndef USE_ST7565
#  define USE_ST7565          0
#endif

#if USE_ST7565
/*No settings*/
#endif  /*USE_ST7565*/

/*------------------------------------------
 *  UC1610 (4 gray 160*[104|128])
 *  (EA DOGXL160 160x104 tested)
 *-----------------------------------------*/
#ifndef USE_UC1610
#  define USE_UC1610          0
#endif

#if USE_UC1610
#  define UC1610_HOR_RES         LV_HOR_RES
#  define UC1610_VER_RES         LV_VER_RES
#  define UC1610_INIT_CONTRAST   33   /* init contrast, values in [%] */
#  define UC1610_INIT_HARD_RST   0    /* 1 : hardware reset at init, 0 : software reset */
#  define UC1610_TOP_VIEW        0    /* 0 : Bottom View, 1 : Top View */
#endif  /*USE_UC1610*/

/*-----------------------------------------
 *  Linux frame buffer device (/dev/fbx)
 *-----------------------------------------*/
#ifndef USE_FBDEV
#  define USE_FBDEV           0
#endif

#if USE_FBDEV
#  define FBDEV_PATH          "/dev/fb0"
#endif

/*********************
 *  INPUT DEVICES
 *********************/

/*--------------
 *    XPT2046
 *--------------*/
#ifndef USE_XPT2046
#  define USE_XPT2046         0
#endif

#if USE_XPT2046
#  define XPT2046_HOR_RES     480
#  define XPT2046_VER_RES     320
#  define XPT2046_X_MIN       200
#  define XPT2046_Y_MIN       200
#  define XPT2046_X_MAX       3800
#  define XPT2046_Y_MAX       3800
#  define XPT2046_AVG         4
#  define XPT2046_INV         0
#endif

/*-----------------
 *    FT5406EE8
 *-----------------*/
#ifndef USE_FT5406EE8
#  define USE_FT5406EE8       0
#endif

#if USE_FT5406EE8
# define FT5406EE8_I2C_ADR   0x38                  /*7 bit address*/
#endif

/*---------------
 *  AD TOUCH
 *--------------*/
#ifndef USE_AD_TOUCH
#  define USE_AD_TOUCH        0
#endif

#if USE_AD_TOUCH
/*No settings*/
#endif


/*---------------------------------------
 * Mouse or touchpad on PC (using SDL)
 *-------------------------------------*/
#ifndef USE_MOUSE
#  define USE_MOUSE           0
#endif

#if USE_MOUSE
/*No settings*/
#endif

/*-------------------------------------------
 * Mousewheel as encoder on PC (using SDL)
 *------------------------------------------*/
#ifndef USE_MOUSEWHEEL
#  define USE_MOUSEWHEEL      0
#endif

#if USE_MOUSEWHEEL
/*No settings*/
#endif

/*-------------------------------------------------
 * Touchscreen as libinput interface (for Linux based systems)
 *------------------------------------------------*/
#ifndef USE_LIBINPUT
#  define USE_LIBINPUT           0
#endif

#if USE_LIBINPUT
#  define LIBINPUT_NAME   "/dev/input/event0"        /*You can use the "evtest" Linux tool to get the list of devices and test them*/
#endif  /*USE_LIBINPUT*/

/*-------------------------------------------------
 * Mouse or touchpad as evdev interface (for Linux based systems)
 *------------------------------------------------*/
#ifndef USE_EVDEV
#  define USE_EVDEV           0
#endif

#if USE_EVDEV
#  define EVDEV_NAME   "/dev/input/event0"        /*You can use the "evtest" Linux tool to get the list of devices and test them*/
#  define EVDEV_SWAP_AXES         0               /*Swap the x and y axes of the touchscreen*/

#  define EVDEV_SCALE             0               /* Scale input, e.g. if touchscreen resolution does not match display resolution */
#  if EVDEV_SCALE
#    define EVDEV_SCALE_HOR_RES     (4096)          /* Horizontal resolution of touchscreen */
#    define EVDEV_SCALE_VER_RES     (4096)          /* Vertical resolution of touchscreen */
#  endif  /*EVDEV_SCALE*/

#  define EVDEV_CALIBRATE         0               /*Scale and offset the touchscreen coordinates by using maximum and minimum values for each axis*/
#  if EVDEV_CALIBRATE
#    define EVDEV_HOR_MIN   3800                    /*If EVDEV_XXX_MIN > EVDEV_XXX_MAX the XXX axis is automatically inverted*/
#    define EVDEV_HOR_MAX   200
#    define EVDEV_VER_MIN   200
#    define EVDEV_VER_MAX   3800
#  endif  /*EVDEV_SCALE*/
#endif  /*USE_EVDEV*/

/*-------------------------------
 *   Keyboard of a PC (using SDL)
 *------------------------------*/
#ifndef USE_KEYBOARD
#  define USE_KEYBOARD        0
#endif

#if USE_KEYBOARD
/*No settings*/
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  /*LV_DRV_CONF_H*/
