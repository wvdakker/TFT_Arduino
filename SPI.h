/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@arduino.cc>
 * Copyright (c) 2014 by Paul Stoffregen <paul@pjrc.com> (Transaction API)
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include <stdio.h>
extern "C" {
#include "utility/spi_com.h"
}

#define SPI_TRANSMITRECEIVE false
#define SPI_TRANSMITONLY true

class SPIClass {
  public:
    SPIClass();

    void begin(SPI_TypeDef *);
    void end(void);

    /* Transfer functions: must be called after initialization of the SPI
     * instance with begin() or beginTransaction().
     */
    uint8_t transfer(uint8_t data, bool skipReceive = SPI_TRANSMITRECEIVE);
    uint16_t transfer16(uint16_t data, bool skipReceive = SPI_TRANSMITRECEIVE);
    void transfer(void *buf, size_t count, bool skipReceive = SPI_TRANSMITRECEIVE);

    /* Expand SPI API
     * https://github.com/arduino/ArduinoCore-API/discussions/189
     */
    void transfer(const void *tx_buf, void *rx_buf, size_t count);

    // Not implemented functions. Kept for compatibility.
    void usingInterrupt(int interruptNumber);
    void notUsingInterrupt(int interruptNumber);
    void attachInterrupt(void);
    void detachInterrupt(void);

  protected:
    // spi instance
    spi_t         _spi;
};

extern SPIClass SPI;

#endif /* _SPI_H_INCLUDED */
