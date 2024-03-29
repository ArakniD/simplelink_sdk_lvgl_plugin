/*
 * Copyright (c) 2018-2019, Texas Instruments Incorporated
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
 *  ======== CC3235SF_LAUNCHXL.c ========
 *  This file is responsible for setting up the board specific items for the
 *  CC3235SF_LAUNCHXL board.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <ti/devices/cc32xx/inc/hw_ints.h>
#include <ti/devices/cc32xx/inc/hw_memmap.h>
#include <ti/devices/cc32xx/inc/hw_types.h>

#include <ti/devices/cc32xx/driverlib/rom.h>
#include <ti/devices/cc32xx/driverlib/rom_map.h>
#include <ti/devices/cc32xx/driverlib/adc.h>
#include <ti/devices/cc32xx/driverlib/gpio.h>
#include <ti/devices/cc32xx/driverlib/pin.h>
#include <ti/devices/cc32xx/driverlib/prcm.h>
#include <ti/devices/cc32xx/driverlib/spi.h>
#include <ti/devices/cc32xx/driverlib/sdhost.h>
#include <ti/devices/cc32xx/driverlib/timer.h>
#include <ti/devices/cc32xx/driverlib/uart.h>
#include <ti/devices/cc32xx/driverlib/udma.h>
#include <ti/devices/cc32xx/driverlib/wdt.h>

#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC32XX.h>

#include "CC3235SF_LAUNCHXL.h"

/*
 *  This define determines whether to use the UARTCC32XXDMA driver
 *  or the UARTCC32XX (no DMA) driver.  Set to 1 to use the UARTCC32XXDMA
 *  driver.
 */
#ifndef TI_DRIVERS_UART_DMA
#define TI_DRIVERS_UART_DMA 0
#endif

/*
 *  =============================== ADC ===============================
 */
#include <ti/drivers/ADC.h>
#include <ti/drivers/adc/ADCCC32XX.h>

ADCCC32XX_Object adcCC3235SObjects[CC3235SF_LAUNCHXL_ADCCOUNT];

const ADCCC32XX_HWAttrsV1 adcCC3235SHWAttrs[CC3235SF_LAUNCHXL_ADCCOUNT] = {
    {
        .adcPin = ADCCC32XX_PIN_57_CH_0
    },
    {
        .adcPin = ADCCC32XX_PIN_60_CH_3
    }
};

const ADC_Config ADC_config[CC3235SF_LAUNCHXL_ADCCOUNT] = {
    {
        .fxnTablePtr = &ADCCC32XX_fxnTable,
        .object = &adcCC3235SObjects[CC3235SF_LAUNCHXL_ADC0],
        .hwAttrs = &adcCC3235SHWAttrs[CC3235SF_LAUNCHXL_ADC0]
    },
    {
        .fxnTablePtr = &ADCCC32XX_fxnTable,
        .object = &adcCC3235SObjects[CC3235SF_LAUNCHXL_ADC1],
        .hwAttrs = &adcCC3235SHWAttrs[CC3235SF_LAUNCHXL_ADC1]
    }
};

const uint_least8_t ADC_count = CC3235SF_LAUNCHXL_ADCCOUNT;

/*
 *  =============================== Capture ===============================
 */
#include <ti/drivers/Capture.h>
#include <ti/drivers/capture/CaptureCC32XX.h>

CaptureCC32XX_Object captureCC3235SFObjects[CC3235SF_LAUNCHXL_CAPTURECOUNT];

const CaptureCC32XX_HWAttrs captureCC3235SFHWAttrs[CC3235SF_LAUNCHXL_CAPTURECOUNT] =
{
      {
         .capturePin = CaptureCC32XX_PIN_04,
         .intPriority = ~0
      },
      {
          .capturePin = CaptureCC32XX_PIN_05,
          .intPriority = ~0
      },
};

const Capture_Config Capture_config[CC3235SF_LAUNCHXL_CAPTURECOUNT] = {
    {
        .fxnTablePtr = &CaptureCC32XX_fxnTable,
        .object = &captureCC3235SFObjects[CC3235SF_LAUNCHXL_CAPTURE0],
        .hwAttrs = &captureCC3235SFHWAttrs[CC3235SF_LAUNCHXL_CAPTURE0]
    },
    {
        .fxnTablePtr = &CaptureCC32XX_fxnTable,
        .object = &captureCC3235SFObjects[CC3235SF_LAUNCHXL_CAPTURE1],
        .hwAttrs = &captureCC3235SFHWAttrs[CC3235SF_LAUNCHXL_CAPTURE1]
    }
};

const uint_least8_t Capture_count = CC3235SF_LAUNCHXL_CAPTURECOUNT;

/*
 *  =============================== Crypto ===============================
 */
#include <ti/drivers/crypto/CryptoCC32XX.h>

CryptoCC32XX_Object cryptoCC3235SObjects[CC3235SF_LAUNCHXL_CRYPTOCOUNT];

const CryptoCC32XX_Config CryptoCC32XX_config[CC3235SF_LAUNCHXL_CRYPTOCOUNT] = {
    {
        .object = &cryptoCC3235SObjects[CC3235SF_LAUNCHXL_CRYPTO0]
    }
};

const uint_least8_t CryptoCC32XX_count = CC3235SF_LAUNCHXL_CRYPTOCOUNT;

/*
 *  =============================== DMA ===============================
 */
#include <ti/drivers/dma/UDMACC32XX.h>

static tDMAControlTable dmaControlTable[64] __attribute__ ((aligned (1024)));

/*
 *  ======== dmaErrorFxn ========
 *  This is the handler for the uDMA error interrupt.
 */
static void dmaErrorFxn(uintptr_t arg)
{
    int status = MAP_uDMAErrorStatusGet();
    MAP_uDMAErrorStatusClear();

    /* Suppress unused variable warning */
    (void)status;

    while (1);
}

UDMACC32XX_Object udmaCC3235SObject;

const UDMACC32XX_HWAttrs udmaCC3235SHWAttrs = {
    .controlBaseAddr = (void *)dmaControlTable,
    .dmaErrorFxn = (UDMACC32XX_ErrorFxn)dmaErrorFxn,
    .intNum = INT_UDMAERR,
    .intPriority = (~0)
};

const UDMACC32XX_Config UDMACC32XX_config = {
    .object = &udmaCC3235SObject,
    .hwAttrs = &udmaCC3235SHWAttrs
};

/*
 *  =============================== General ===============================
 */
/*
 *  ======== CC3235SF_LAUNCHXL_initGeneral ========
 */
void CC3235SF_LAUNCHXL_initGeneral(void)
{
    PRCMCC3200MCUInit();
    Power_init();
}

/*
 *  ======== Board_init ========
 */
void Board_init(void)
{
    CC3235SF_LAUNCHXL_initGeneral();
}

/*
 *  =============================== GPIO ===============================
 */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOCC32XX.h>

/*
 * Array of Pin configurations
 * NOTE: The order of the pin configurations must coincide with what was
 *       defined in CC3235SF_LAUNCHXL.h
 * NOTE: Pins not used for interrupts should be placed at the end of the
 *       array.  Callback entries can be omitted from callbacks array to
 *       reduce memory usage.
 */
GPIO_PinConfig gpioPinConfigs[] = {
    /* input pins with callbacks */
    /* CC3235SF_LAUNCHXL_GPIO_SW2 */
    GPIOCC32XX_GPIO_13 | GPIO_CFG_INPUT | GPIO_CFG_IN_INT_RISING,
    /* CC3235SF_LAUNCHXL_GPIO_SW3 */
    GPIOCC32XX_GPIO_22 | GPIO_CFG_INPUT | GPIO_CFG_IN_INT_RISING,

    /* CC3235SF_LAUNCHXL_SPI_MASTER_READY */
    GPIOCC32XX_GPIO_28 | GPIO_DO_NOT_CONFIG,
    /* CC3235SF_LAUNCHXL_SPI_SLAVE_READY */
    GPIOCC32XX_GPIO_12 | GPIO_DO_NOT_CONFIG,

    /* output pins */
    /* CC3235SF_LAUNCHXL_GPIO_LED_BLUE */
    GPIOCC32XX_GPIO_09 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW,

    /*
     *  CC3235SF_LAUNCHXL_GPIO_LED_RED and CC3235SF_LAUNCHXL_GPIO_LED_GREEN are shared with the
     *  I2C and PWM peripherals. In order for those examples to work, these
     *  LEDs are taken out of gpioPinConfig[]
     */
    /* CC3235SF_LAUNCHXL_GPIO_LED_RED */
    /* GPIOCC32XX_GPIO_10 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW, */
    /* CC3235SF_LAUNCHXL_GPIO_LED_GREEN */
    /* GPIOCC32XX_GPIO_11 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_HIGH | GPIO_CFG_OUT_LOW, */

    /* Board_GPIO_SHARP_LCD_ENABLE : LCD Enable */
    GPIOCC32XX_GPIO_06 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_SHARP_LCD_POWER : LCD Power */
    GPIOCC32XX_GPIO_03 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_SHARP_LCD_CS : LCD SPI Slave Select */
    GPIOCC32XX_GPIO_12 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,

    /* Board_GPIO_KENTEC_LCD_BACKLIGHT : LCD Backlight */
    GPIOCC32XX_GPIO_11 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_KENTEC_LCD_RESET : LCD Reset */
    GPIOCC32XX_GPIO_23 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_KENTEC_LCD_DC : LCD Data/Command */
    GPIOCC32XX_GPIO_07 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_KENTEC_LCD_CS : LCD SPI Slave Select */
    GPIOCC32XX_GPIO_25 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_KENTEC_TS_YP : Touchscreen Y+ */
    GPIOCC32XX_GPIO_02 | GPIO_DO_NOT_CONFIG,
    /* Board_GPIO_KENTEC_TS_XP : Touchscreen X+ */
    GPIOCC32XX_GPIO_05 | GPIO_DO_NOT_CONFIG,
    /* Board_GPIO_KENTEC_TS_YN : Touchscreen Y- */
    GPIOCC32XX_GPIO_22 | GPIO_DO_NOT_CONFIG,
    /* Board_GPIO_KENTEC_TS_XN : Touchscreen X- */
    GPIOCC32XX_GPIO_24 | GPIO_DO_NOT_CONFIG,
};

/*
 * Array of callback function pointers
 * NOTE: The order of the pin configurations must coincide with what was
 *       defined in CC3235SF_LAUNCHXL.h
 * NOTE: Pins not used for interrupts can be omitted from callbacks array to
 *       reduce memory usage (if placed at end of gpioPinConfigs array).
 */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,  /* CC3235SF_LAUNCHXL_GPIO_SW2 */
    NULL,  /* CC3235SF_LAUNCHXL_GPIO_SW3 */
    NULL,  /* CC3235SF_LAUNCHXL_SPI_MASTER_READY */
    NULL   /* CC3235SF_LAUNCHXL_SPI_SLAVE_READY */
};

/* The device-specific GPIO_config structure */
const GPIOCC32XX_Config GPIOCC32XX_config = {
    .pinConfigs = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .numberOfPinConfigs = sizeof(gpioPinConfigs)/sizeof(GPIO_PinConfig),
    .numberOfCallbacks = sizeof(gpioCallbackFunctions)/sizeof(GPIO_CallbackFxn),
    .intPriority = (~0)
};

/*
 *  ============================= Display =============================
 */
#include <ti/display/Display.h>
#include <ti/display/DisplayUart.h>
#include <ti/display/DisplaySharp.h>
#define MAXPRINTLEN 1024

/* This value can be changed to 96 for use with the 430BOOST-SHARP96 BoosterPack. */
#define BOARD_DISPLAY_SHARP_SIZE    128

DisplayUart_Object displayUartObject;
DisplaySharp_Object displaySharpObject;

static char displayBuf[MAXPRINTLEN];
static uint_least8_t sharpDisplayBuf[BOARD_DISPLAY_SHARP_SIZE * BOARD_DISPLAY_SHARP_SIZE / 8];

const DisplayUart_HWAttrs displayUartHWAttrs = {
    .uartIdx = 0,
    .baudRate = 115200,
    .mutexTimeout = (unsigned int)(-1),
    .strBuf = displayBuf,
    .strBufLen = MAXPRINTLEN
};

const DisplaySharp_HWAttrsV1 displaySharpHWattrs = {
    .spiIndex    = CC3235SF_LAUNCHXL_SPI1,
    .csPin       = CC3235SF_LAUNCHXL_SHARP_LCD_CS,
    .powerPin    = CC3235SF_LAUNCHXL_SHARP_LCD_POWER,
    .enablePin   = CC3235SF_LAUNCHXL_SHARP_LCD_ENABLE,
    .pixelWidth  = BOARD_DISPLAY_SHARP_SIZE,
    .pixelHeight = BOARD_DISPLAY_SHARP_SIZE,
    .displayBuf  = sharpDisplayBuf,
};

#ifndef BOARD_DISPLAY_USE_UART
#define BOARD_DISPLAY_USE_UART 1
#endif
#ifndef BOARD_DISPLAY_USE_UART_ANSI
#define BOARD_DISPLAY_USE_UART_ANSI 0
#endif
#ifndef BOARD_DISPLAY_USE_LCD
#define BOARD_DISPLAY_USE_LCD 0
#endif

const Display_Config Display_config[] = {
    {
#  if (BOARD_DISPLAY_USE_UART_ANSI)
        .fxnTablePtr = &DisplayUartAnsi_fxnTable,
#  else /* Default to minimal UART with no cursor placement */
        .fxnTablePtr = &DisplayUartMin_fxnTable,
#  endif
        .object = &displayUartObject,
        .hwAttrs = &displayUartHWAttrs
    },
#if (BOARD_DISPLAY_USE_LCD)
    {
        .fxnTablePtr = &DisplaySharp_fxnTable,
        .object      = &displaySharpObject,
        .hwAttrs     = &displaySharpHWattrs
    },
#endif
};

const uint_least8_t Display_count = sizeof(Display_config) / sizeof(Display_Config);



/*
 *  =============================== I2C ===============================
 */
#include <ti/drivers/I2C.h>
#include <ti/drivers/i2c/I2CCC32XX.h>

I2CCC32XX_Object i2cCC3235SObjects[CC3235SF_LAUNCHXL_I2CCOUNT];

const I2CCC32XX_HWAttrsV1 i2cCC3235SHWAttrs[CC3235SF_LAUNCHXL_I2CCOUNT] = {
    {
        .baseAddr = I2CA0_BASE,
        .intNum = INT_I2CA0,
        .intPriority = (~0),
        .clkPin = I2CCC32XX_PIN_01_I2C_SCL,
        .dataPin = I2CCC32XX_PIN_02_I2C_SDA
    }
};

const I2C_Config I2C_config[CC3235SF_LAUNCHXL_I2CCOUNT] = {
    {
        .fxnTablePtr = &I2CCC32XX_fxnTable,
        .object = &i2cCC3235SObjects[CC3235SF_LAUNCHXL_I2C0],
        .hwAttrs = &i2cCC3235SHWAttrs[CC3235SF_LAUNCHXL_I2C0]
    }
};

const uint_least8_t I2C_count = CC3235SF_LAUNCHXL_I2CCOUNT;

/*
 *  =============================== I2S ===============================
 */
#include <ti/drivers/I2S.h>
#include <ti/drivers/i2s/I2SCC32XX.h>

I2SCC32XX_Object i2sCC3235SFObjects[CC3235SF_LAUNCHXL_I2SCOUNT];

const I2SCC32XX_HWAttrs i2sCC3235SFHWAttrs[CC3235SF_LAUNCHXL_I2SCOUNT] = {
    {
      .pinSD1           =  I2SCC32XX_PIN_50_SD1,
      .pinSD0           =  I2SCC32XX_PIN_64_SD0,
      .pinSCK           =  I2SCC32XX_PIN_53_SCK,
      .pinSCKX          =  I2SCC32XX_PIN_UNUSED,
      .pinWS            =  I2SCC32XX_PIN_63_WS,
      .rxChannelIndex   =  UDMA_CH4_I2S_RX,
      .txChannelIndex   =  UDMA_CH5_I2S_TX,
      .intPriority      =  0x40,
    }
};

const I2S_Config I2S_config[CC3235SF_LAUNCHXL_I2SCOUNT] = {
    {
        .object = &i2sCC3235SFObjects[CC3235SF_LAUNCHXL_I2S0],
        .hwAttrs = &i2sCC3235SFHWAttrs[CC3235SF_LAUNCHXL_I2S0]
    }
};

const uint_least8_t I2S_count = CC3235SF_LAUNCHXL_I2SCOUNT;


/*
 *  =============================== Power ===============================
 */
/*
 * This table defines the parking state to be set for each parkable pin
 * during LPDS. (Device pins must be parked during LPDS to achieve maximum
 * power savings.)  If the pin should be left unparked, specify the state
 * PowerCC32XX_DONT_PARK.  For example, for a UART TX pin, the device
 * will automatically park the pin in a high state during transition to LPDS,
 * so the Power Manager does not need to explictly park the pin.  So the
 * corresponding entries in this table should indicate PowerCC32XX_DONT_PARK.
 */
PowerCC32XX_ParkInfo parkInfo[] = {
/*          PIN                    PARK STATE              PIN ALIAS (FUNCTION)
     -----------------  ------------------------------     -------------------- */
    {PowerCC32XX_PIN01, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO10              */
    {PowerCC32XX_PIN02, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO11              */
    {PowerCC32XX_PIN03, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO12              */
    {PowerCC32XX_PIN04, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO13              */
    {PowerCC32XX_PIN05, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO14              */
    {PowerCC32XX_PIN06, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO15              */
    {PowerCC32XX_PIN07, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO16              */
    {PowerCC32XX_PIN08, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO17              */
    {PowerCC32XX_PIN13, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* FLASH_SPI_DIN       */
    {PowerCC32XX_PIN15, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO22              */
    {PowerCC32XX_PIN16, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* TDI (JTAG DEBUG)    */
    {PowerCC32XX_PIN17, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* TDO (JTAG DEBUG)    */
    {PowerCC32XX_PIN19, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* TCK (JTAG DEBUG)    */
    {PowerCC32XX_PIN20, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* TMS (JTAG DEBUG)    */
    {PowerCC32XX_PIN18, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO28              */
    {PowerCC32XX_PIN21, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* SOP2                */
    {PowerCC32XX_PIN29, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* ANTSEL1             */
    {PowerCC32XX_PIN30, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* ANTSEL2             */
    {PowerCC32XX_PIN45, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* DCDC_ANA2_SW_P      */
    {PowerCC32XX_PIN50, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO0               */
    {PowerCC32XX_PIN52, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* RTC_XTAL_N          */
    {PowerCC32XX_PIN53, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO30              */
    {PowerCC32XX_PIN55, PowerCC32XX_WEAK_PULL_UP_STD},   /* GPIO1 (XDS_UART_RX) */
    {PowerCC32XX_PIN57, PowerCC32XX_WEAK_PULL_UP_STD},   /* GPIO2 (XDS_UART_TX) */
    {PowerCC32XX_PIN58, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO3               */
    {PowerCC32XX_PIN59, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO4               */
    {PowerCC32XX_PIN60, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO5               */
    {PowerCC32XX_PIN61, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO6               */
    {PowerCC32XX_PIN62, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO7               */
    {PowerCC32XX_PIN63, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO8               */
    {PowerCC32XX_PIN64, PowerCC32XX_WEAK_PULL_DOWN_STD}, /* GPIO9               */
};

/*
 *  This structure defines the configuration for the Power Manager.
 *
 *  In this configuration the Power policy is disabled by default (because
 *  enablePolicy is set to false).  The Power policy can be enabled dynamically
 *  at runtime by calling Power_enablePolicy(), or at build time, by changing
 *  enablePolicy to true in this structure.
 */
const PowerCC32XX_ConfigV1 PowerCC32XX_config = {
    .policyInitFxn = &PowerCC32XX_initPolicy,
    .policyFxn = &PowerCC32XX_sleepPolicy,
    .enterLPDSHookFxn = NULL,
    .resumeLPDSHookFxn = NULL,
    .enablePolicy = false,
    .enableGPIOWakeupLPDS = true,
    .enableGPIOWakeupShutdown = true,
    .enableNetworkWakeupLPDS = true,
    .wakeupGPIOSourceLPDS = PRCM_LPDS_GPIO13,
    .wakeupGPIOTypeLPDS = PRCM_LPDS_FALL_EDGE,
    .wakeupGPIOFxnLPDS = NULL,
    .wakeupGPIOFxnLPDSArg = 0,
    .wakeupGPIOSourceShutdown = PRCM_HIB_GPIO13,
    .wakeupGPIOTypeShutdown = PRCM_HIB_RISE_EDGE,
    .ramRetentionMaskLPDS = PRCM_SRAM_COL_1 | PRCM_SRAM_COL_2 |
        PRCM_SRAM_COL_3 | PRCM_SRAM_COL_4,
    .keepDebugActiveDuringLPDS = false,
    .ioRetentionShutdown = PRCM_IO_RET_GRP_1,
    .pinParkDefs = parkInfo,
    .numPins = sizeof(parkInfo) / sizeof(PowerCC32XX_ParkInfo)
};

/*
 *  =============================== PWM ===============================
 */
#include <ti/drivers/PWM.h>
#include <ti/drivers/pwm/PWMTimerCC32XX.h>

PWMTimerCC32XX_Object pwmTimerCC3235SObjects[CC3235SF_LAUNCHXL_PWMCOUNT];

const PWMTimerCC32XX_HWAttrsV2 pwmTimerCC3235SHWAttrs[CC3235SF_LAUNCHXL_PWMCOUNT] = {
    {    /* CC3235SF_LAUNCHXL_PWM6 */
        .pwmPin = PWMTimerCC32XX_PIN_01
    },
    {    /* CC3235SF_LAUNCHXL_PWM7 */
        .pwmPin = PWMTimerCC32XX_PIN_02
    }
};

const PWM_Config PWM_config[CC3235SF_LAUNCHXL_PWMCOUNT] = {
    {
        .fxnTablePtr = &PWMTimerCC32XX_fxnTable,
        .object = &pwmTimerCC3235SObjects[CC3235SF_LAUNCHXL_PWM6],
        .hwAttrs = &pwmTimerCC3235SHWAttrs[CC3235SF_LAUNCHXL_PWM6]
    },
    {
        .fxnTablePtr = &PWMTimerCC32XX_fxnTable,
        .object = &pwmTimerCC3235SObjects[CC3235SF_LAUNCHXL_PWM7],
        .hwAttrs = &pwmTimerCC3235SHWAttrs[CC3235SF_LAUNCHXL_PWM7]
    }
};

const uint_least8_t PWM_count = CC3235SF_LAUNCHXL_PWMCOUNT;

/*
 *  =============================== SDFatFS ===============================
 */
#include <ti/drivers/SD.h>
#include <ti/drivers/SDFatFS.h>

/*
 * Note: The SDFatFS driver provides interface functions to enable FatFs
 * but relies on the SD driver to communicate with SD cards.  Opening a
 * SDFatFs driver instance will internally try to open a SD driver instance
 * reusing the same index number (opening SDFatFs driver at index 0 will try to
 * open SD driver at index 0).  This requires that all SDFatFs driver instances
 * have an accompanying SD driver instance defined with the same index.  It is
 * acceptable to have more SD driver instances than SDFatFs driver instances
 * but the opposite is not supported & the SDFatFs will fail to open.
 */
SDFatFS_Object sdfatfsObjects[CC3235SF_LAUNCHXL_SDFatFSCOUNT];

const SDFatFS_Config SDFatFS_config[CC3235SF_LAUNCHXL_SDFatFSCOUNT] = {
    {
        .object = &sdfatfsObjects[CC3235SF_LAUNCHXL_SDFatFS0]
    }
};

const uint_least8_t SDFatFS_count = CC3235SF_LAUNCHXL_SDFatFSCOUNT;

/*
 *  =============================== SD ===============================
 */
#include <ti/drivers/SD.h>
#include <ti/drivers/sd/SDHostCC32XX.h>

SDHostCC32XX_Object sdhostCC3235SObjects[CC3235SF_LAUNCHXL_SDCOUNT];

/* SDHost configuration structure, describing which pins are to be used */
const SDHostCC32XX_HWAttrsV1 sdhostCC3235SHWattrs[CC3235SF_LAUNCHXL_SDCOUNT] = {
    {
        .clkRate = 8000000,
        .intPriority = ~0,
        .baseAddr = SDHOST_BASE,
        .rxChIdx = UDMA_CH23_SDHOST_RX,
        .txChIdx = UDMA_CH24_SDHOST_TX,
        .dataPin = SDHostCC32XX_PIN_06_SDCARD_DATA,
        .cmdPin = SDHostCC32XX_PIN_08_SDCARD_CMD,
        .clkPin = SDHostCC32XX_PIN_07_SDCARD_CLK
    }
};

const SD_Config SD_config[CC3235SF_LAUNCHXL_SDCOUNT] = {
    {
        .fxnTablePtr = &sdHostCC32XX_fxnTable,
        .object = &sdhostCC3235SObjects[CC3235SF_LAUNCHXL_SD0],
        .hwAttrs = &sdhostCC3235SHWattrs[CC3235SF_LAUNCHXL_SD0]
    },
};

const uint_least8_t SD_count = CC3235SF_LAUNCHXL_SDCOUNT;

/*
 *  =============================== SPI ===============================
 */
#include <ti/drivers/SPI.h>
#include <ti/drivers/spi/SPICC32XXDMA.h>

SPICC32XXDMA_Object spiCC3235SDMAObjects[CC3235SF_LAUNCHXL_SPICOUNT];

uint32_t spiCC3235SDMAscratchBuf[CC3235SF_LAUNCHXL_SPICOUNT];

const SPICC32XXDMA_HWAttrsV1 spiCC3235SDMAHWAttrs[CC3235SF_LAUNCHXL_SPICOUNT] = {
    /* index 0 is reserved for LSPI that links to the NWP */
    {
        .baseAddr = LSPI_BASE,
        .intNum = INT_LSPI,
        .intPriority = (~0),
        .spiPRCM = PRCM_LSPI,
        .csControl = SPI_SW_CTRL_CS,
        .csPolarity = SPI_CS_ACTIVEHIGH,
        .pinMode = SPI_4PIN_MODE,
        .turboMode = SPI_TURBO_OFF,
        .scratchBufPtr = &spiCC3235SDMAscratchBuf[CC3235SF_LAUNCHXL_SPI0],
        .defaultTxBufValue = 0,
        .rxChannelIndex = UDMA_CH12_LSPI_RX,
        .txChannelIndex = UDMA_CH13_LSPI_TX,
        .minDmaTransferSize = 100,
        .mosiPin = SPICC32XXDMA_PIN_NO_CONFIG,
        .misoPin = SPICC32XXDMA_PIN_NO_CONFIG,
        .clkPin = SPICC32XXDMA_PIN_NO_CONFIG,
        .csPin = SPICC32XXDMA_PIN_NO_CONFIG
    },
    {
        .baseAddr = GSPI_BASE,
        .intNum = INT_GSPI,
        .intPriority = (~0),
        .spiPRCM = PRCM_GSPI,
        .csControl = SPI_HW_CTRL_CS,
        .csPolarity = SPI_CS_ACTIVELOW,
        .pinMode = SPI_4PIN_MODE,
        .turboMode = SPI_TURBO_OFF,
        .scratchBufPtr = &spiCC3235SDMAscratchBuf[CC3235SF_LAUNCHXL_SPI1],
        .defaultTxBufValue = 0,
        .rxChannelIndex = UDMA_CH6_GSPI_RX,
        .txChannelIndex = UDMA_CH7_GSPI_TX,
        .minDmaTransferSize = 10,
        .mosiPin = SPICC32XXDMA_PIN_07_MOSI,
        .misoPin = SPICC32XXDMA_PIN_06_MISO,
        .clkPin = SPICC32XXDMA_PIN_05_CLK,
        .csPin = SPICC32XXDMA_PIN_08_CS
    }
};

const SPI_Config SPI_config[CC3235SF_LAUNCHXL_SPICOUNT] = {
    {
        .fxnTablePtr = &SPICC32XXDMA_fxnTable,
        .object = &spiCC3235SDMAObjects[CC3235SF_LAUNCHXL_SPI0],
        .hwAttrs = &spiCC3235SDMAHWAttrs[CC3235SF_LAUNCHXL_SPI0]
    },
    {
        .fxnTablePtr = &SPICC32XXDMA_fxnTable,
        .object = &spiCC3235SDMAObjects[CC3235SF_LAUNCHXL_SPI1],
        .hwAttrs = &spiCC3235SDMAHWAttrs[CC3235SF_LAUNCHXL_SPI1]
    }
};

const uint_least8_t SPI_count = CC3235SF_LAUNCHXL_SPICOUNT;

/*
 *  =============================== Timer ===============================
 */
#include <ti/drivers/Timer.h>
#include <ti/drivers/timer/TimerCC32XX.h>

TimerCC32XX_Object timerCC3235SFObjects[CC3235SF_LAUNCHXL_TIMERCOUNT];

const TimerCC32XX_HWAttrs timerCC3235SFHWAttrs[CC3235SF_LAUNCHXL_TIMERCOUNT] = {
    {
        .baseAddress = TIMERA0_BASE,
        .subTimer = TimerCC32XX_timer32,
        .intNum = INT_TIMERA0A,
        .intPriority = ~0
    },
    {
        .baseAddress = TIMERA1_BASE,
        .subTimer = TimerCC32XX_timer16A,
        .intNum = INT_TIMERA1A,
        .intPriority = ~0
    },
    {
         .baseAddress = TIMERA1_BASE,
         .subTimer = TimerCC32XX_timer16B,
         .intNum = INT_TIMERA1B,
         .intPriority = ~0
    },
};

const Timer_Config Timer_config[CC3235SF_LAUNCHXL_TIMERCOUNT] = {
    {
        .fxnTablePtr = &TimerCC32XX_fxnTable,
        .object = &timerCC3235SFObjects[CC3235SF_LAUNCHXL_TIMER0],
        .hwAttrs = &timerCC3235SFHWAttrs[CC3235SF_LAUNCHXL_TIMER0]
    },
    {
        .fxnTablePtr = &TimerCC32XX_fxnTable,
        .object = &timerCC3235SFObjects[CC3235SF_LAUNCHXL_TIMER1],
        .hwAttrs = &timerCC3235SFHWAttrs[CC3235SF_LAUNCHXL_TIMER1]
    },
    {
        .fxnTablePtr = &TimerCC32XX_fxnTable,
        .object = &timerCC3235SFObjects[CC3235SF_LAUNCHXL_TIMER2],
        .hwAttrs = &timerCC3235SFHWAttrs[CC3235SF_LAUNCHXL_TIMER2]
    },
};

const uint_least8_t Timer_count = CC3235SF_LAUNCHXL_TIMERCOUNT;

/*
 *  =============================== UART ===============================
 */
#include <ti/drivers/UART.h>
#if TI_DRIVERS_UART_DMA
#include <ti/drivers/uart/UARTCC32XXDMA.h>

UARTCC32XXDMA_Object uartCC3235SDmaObjects[CC3235SF_LAUNCHXL_UARTCOUNT];

/* UART configuration structure */
const UARTCC32XXDMA_HWAttrsV1 uartCC3235SDmaHWAttrs[CC3235SF_LAUNCHXL_UARTCOUNT] = {
    {
        .baseAddr = UARTA0_BASE,
        .intNum = INT_UARTA0,
        .intPriority = (~0),
        .flowControl = UARTCC32XXDMA_FLOWCTRL_NONE,
        .rxChannelIndex = UDMA_CH8_UARTA0_RX,
        .txChannelIndex = UDMA_CH9_UARTA0_TX,
        .rxPin = UARTCC32XXDMA_PIN_57_UART0_RX,
        .txPin = UARTCC32XXDMA_PIN_55_UART0_TX,
        .ctsPin = UARTCC32XXDMA_PIN_UNASSIGNED,
        .rtsPin = UARTCC32XXDMA_PIN_UNASSIGNED,
        .errorFxn = NULL
    },
    {
        .baseAddr = UARTA1_BASE,
        .intNum = INT_UARTA1,
        .intPriority = (~0),
        .flowControl = UARTCC32XXDMA_FLOWCTRL_NONE,
        .rxChannelIndex = UDMA_CH10_UARTA1_RX,
        .txChannelIndex = UDMA_CH11_UARTA1_TX,
        .rxPin = UARTCC32XXDMA_PIN_08_UART1_RX,
        .txPin = UARTCC32XXDMA_PIN_07_UART1_TX,
        .ctsPin = UARTCC32XXDMA_PIN_UNASSIGNED,
        .rtsPin = UARTCC32XXDMA_PIN_UNASSIGNED,
        .errorFxn = NULL
    }
};

const UART_Config UART_config[CC3235SF_LAUNCHXL_UARTCOUNT] = {
    {
        .fxnTablePtr = &UARTCC32XXDMA_fxnTable,
        .object = &uartCC3235SDmaObjects[CC3235SF_LAUNCHXL_UART0],
        .hwAttrs = &uartCC3235SDmaHWAttrs[CC3235SF_LAUNCHXL_UART0]
    },
    {
        .fxnTablePtr = &UARTCC32XXDMA_fxnTable,
        .object = &uartCC3235SDmaObjects[CC3235SF_LAUNCHXL_UART1],
        .hwAttrs = &uartCC3235SDmaHWAttrs[CC3235SF_LAUNCHXL_UART1]
    }
};

#else
#include <ti/drivers/uart/UARTCC32XX.h>

UARTCC32XX_Object uartCC3235SObjects[CC3235SF_LAUNCHXL_UARTCOUNT];
unsigned char uartCC3235SRingBuffer[CC3235SF_LAUNCHXL_UARTCOUNT][32];

/* UART configuration structure */
const UARTCC32XX_HWAttrsV1 uartCC3235SHWAttrs[CC3235SF_LAUNCHXL_UARTCOUNT] = {
    {
        .baseAddr = UARTA0_BASE,
        .intNum = INT_UARTA0,
        .intPriority = (~0),
        .flowControl = UARTCC32XX_FLOWCTRL_NONE,
        .ringBufPtr  = uartCC3235SRingBuffer[CC3235SF_LAUNCHXL_UART0],
        .ringBufSize = sizeof(uartCC3235SRingBuffer[CC3235SF_LAUNCHXL_UART0]),
        .rxPin = UARTCC32XX_PIN_57_UART0_RX,
        .txPin = UARTCC32XX_PIN_55_UART0_TX,
        .ctsPin = UARTCC32XX_PIN_UNASSIGNED,
        .rtsPin = UARTCC32XX_PIN_UNASSIGNED,
        .errorFxn = NULL
    },
    {
        .baseAddr = UARTA1_BASE,
        .intNum = INT_UARTA1,
        .intPriority = (~0),
        .flowControl = UARTCC32XX_FLOWCTRL_NONE,
        .ringBufPtr  = uartCC3235SRingBuffer[CC3235SF_LAUNCHXL_UART1],
        .ringBufSize = sizeof(uartCC3235SRingBuffer[CC3235SF_LAUNCHXL_UART1]),
        .rxPin = UARTCC32XX_PIN_08_UART1_RX,
        .txPin = UARTCC32XX_PIN_07_UART1_TX,
        .ctsPin = UARTCC32XX_PIN_UNASSIGNED,
        .rtsPin = UARTCC32XX_PIN_UNASSIGNED,
        .errorFxn = NULL
    }
};

const UART_Config UART_config[CC3235SF_LAUNCHXL_UARTCOUNT] = {
    {
        .fxnTablePtr = &UARTCC32XX_fxnTable,
        .object = &uartCC3235SObjects[CC3235SF_LAUNCHXL_UART0],
        .hwAttrs = &uartCC3235SHWAttrs[CC3235SF_LAUNCHXL_UART0]
    },
    {
        .fxnTablePtr = &UARTCC32XX_fxnTable,
        .object = &uartCC3235SObjects[CC3235SF_LAUNCHXL_UART1],
        .hwAttrs = &uartCC3235SHWAttrs[CC3235SF_LAUNCHXL_UART1]
    }
};
#endif /* TI_DRIVERS_UART_DMA */

const uint_least8_t UART_count = CC3235SF_LAUNCHXL_UARTCOUNT;

/*
 *  =============================== Watchdog ===============================
 */
#include <ti/drivers/Watchdog.h>
#include <ti/drivers/watchdog/WatchdogCC32XX.h>

WatchdogCC32XX_Object watchdogCC3235SObjects[CC3235SF_LAUNCHXL_WATCHDOGCOUNT];

const WatchdogCC32XX_HWAttrs watchdogCC3235SHWAttrs[CC3235SF_LAUNCHXL_WATCHDOGCOUNT] = {
    {
        .baseAddr = WDT_BASE,
        .intNum = INT_WDT,
        .intPriority = (~0),
        .reloadValue = 80000000 /* 1 second period at default CPU clock freq */
    }
};

const Watchdog_Config Watchdog_config[CC3235SF_LAUNCHXL_WATCHDOGCOUNT] = {
    {
        .fxnTablePtr = &WatchdogCC32XX_fxnTable,
        .object = &watchdogCC3235SObjects[CC3235SF_LAUNCHXL_WATCHDOG0],
        .hwAttrs = &watchdogCC3235SHWAttrs[CC3235SF_LAUNCHXL_WATCHDOG0]
    }
};

const uint_least8_t Watchdog_count = CC3235SF_LAUNCHXL_WATCHDOGCOUNT;

/*
 *  ======== Board_debugHeader ========
 *  This structure prevents the CC32XXSF bootloader from overwriting the
 *  internal FLASH; this allows us to flash a program that will not be
 *  overwritten by the bootloader with the encrypted program saved in
 *  "secure/serial flash".
 *
 *  This structure must be placed at the beginning of internal FLASH (so
 *  the bootloader is able to recognize that it should not overwrite
 *  internal FLASH).
 */
#if defined (__SF_DEBUG__) || defined(__SF_NODEBUG__)
#if defined(__TI_COMPILER_VERSION__)
#pragma DATA_SECTION(Board_debugHeader, ".dbghdr")
#pragma RETAIN(Board_debugHeader)
#elif defined(__IAR_SYSTEMS_ICC__)
#pragma location=".dbghdr"
#elif defined(__GNUC__)
__attribute__ ((section (".dbghdr")))
#endif
#if defined(__SF_DEBUG__)
const uint32_t Board_debugHeader[] = {
    0x5AA5A55A,
    0x000FF800,
    0xEFA3247D
};
#elif defined (__SF_NODEBUG__)
const uint32_t Board_debugHeader[] = {
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF
};
#endif
#endif
