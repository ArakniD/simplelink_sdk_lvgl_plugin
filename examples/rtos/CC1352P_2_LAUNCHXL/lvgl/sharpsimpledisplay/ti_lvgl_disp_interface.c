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
 * ti_lvgl_disp_interface.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <ti_lvgl_disp_interface.h>
#include <lv_drv_conf.h>

/* SPI driver handle */
SPI_Handle masterSpi;

/*********************
 *      FUNCTIONS
 *********************/

/**
 * Initialize the software spi port
 */
void spi_init(void)
{
    SPI_Params      spiParams;

    /* Open SPI as master (default) and initialize to default parameters.
     * Set frame format to use freescale SPI mode and bit rate to 15 MHz */
    SPI_init();

    SPI_Params_init(&spiParams);
    spiParams.frameFormat = SPI_POL0_PHA0;
    spiParams.bitRate = LV_DRV_DISP_SPI_BITRATE;

    masterSpi = SPI_open(Board_SPI0, &spiParams);

    if (masterSpi == NULL) {
        /*Error initializing master SPI*/
        while (1);
    }
}

/**
 * Write byte to the spi port
 * @param b a byte to write
 */
void spi_wr_byte(uint8_t b)
{
    uint8_t pui8Data[1];
    SPI_Transaction transaction;
    bool            transferOK;

    /* Write the data byte to the bus. */
    pui8Data[0] = b;

    transaction.count = 1;
    transaction.txBuf = (void *)pui8Data;
    transaction.rxBuf = NULL;
    transferOK = SPI_transfer(masterSpi, &transaction);
    if (!transferOK) {
        while(1) {}
    }
}

/**
 * Write word to the spi port
 * @param w a word to write
 */
void spi_wr_word(uint16_t w)
{
    uint8_t pui8Data[2];
    SPI_Transaction transaction;
    bool            transferOK;

    /* Write the most significant byte of the data to the bus. */
    pui8Data[0] = (w >> 8);

    /* Write the least significant byte of the data to the bus. */
    pui8Data[1] = w;

    transaction.count = 2;
    transaction.txBuf = (void *)pui8Data;
    transaction.rxBuf = NULL;
    transferOK = SPI_transfer(masterSpi, &transaction);
    if (!transferOK) {
        while(1) {}
    }
}

/**
 * Write an array to the spi port
 * @param array pointer to a memory block to write
 * @param length number of bytes to write
 */
void spi_wr_array(uint8_t * array, uint32_t length)
{
    SPI_Transaction transaction;
    bool            transferOK;
    transaction.count = length;
    transaction.txBuf = array;
    transaction.rxBuf = NULL;
    transferOK = SPI_transfer(masterSpi, &transaction);
    if (!transferOK) {
        while(1) {}
    }
}
