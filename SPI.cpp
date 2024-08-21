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

#include "SPI.h"

SPIClass SPI;

/**
  * @brief  Default constructor. All done in CubeMX
  */
SPIClass::SPIClass()
{
}

/**
  * @brief  Initialize the SPI instance.
  */
void SPIClass::begin(SPI_TypeDef *SPI_TFT)
{
  _spi.spi = SPI_TFT;
  SET_BIT(_spi.spi->CR1, SPI_CR1_SPE);
}


/**
  * @brief  Deinitialize the SPI instance and stop it.
  */
void SPIClass::end(void)
{
  CLEAR_BIT(_spi.spi->CR1, SPI_CR1_SPE);
}

/**
  * @brief  Transfer one byte on the SPI bus.
  *         begin() or beginTransaction() must be called at least once before.
  * @param  data: byte to send.
  * @param  skipReceive: skip receiving data after transmit or not.
  *         SPI_TRANSMITRECEIVE or SPI_TRANSMITONLY.
  *         Optional, default: SPI_TRANSMITRECEIVE.
  * @return byte received from the slave.
  */
uint8_t SPIClass::transfer(uint8_t data, bool skipReceive)
{
  spi_transfer(&_spi, &data, (!skipReceive) ? &data : NULL, sizeof(uint8_t));
  return data;
}

/**
  * @brief  Transfer two bytes on the SPI bus in 16 bits format.
  *         begin() or beginTransaction() must be called at least once before.
  * @param  data: bytes to send.
  * @param  skipReceive: skip receiving data after transmit or not.
  *         SPI_TRANSMITRECEIVE or SPI_TRANSMITONLY.
  *         Optional, default: SPI_TRANSMITRECEIVE.
  * @return bytes received from the slave in 16 bits format.
  */
uint16_t SPIClass::transfer16(uint16_t data, bool skipReceive)
{
  uint16_t tmp;

  spi_transfer(&_spi, (uint8_t *)&data, (!skipReceive) ? (uint8_t *)&data : NULL, sizeof(uint16_t));

  return data;
}

/**
  * @brief  Transfer several bytes. Only one buffer used to send and receive data.
  *         begin() or beginTransaction() must be called at least once before.
  * @param  buf: pointer to the bytes to send. The bytes received are copy in
  *         this buffer.
  * @param  count: number of bytes to send/receive.
  * @param  skipReceive: skip receiving data after transmit or not.
  *         SPI_TRANSMITRECEIVE or SPI_TRANSMITONLY.
  *         Optional, default: SPI_TRANSMITRECEIVE.
  */
void SPIClass::transfer(void *buf, size_t count, bool skipReceive)
{
  spi_transfer(&_spi, (uint8_t *)buf, (!skipReceive) ? (uint8_t *)buf : NULL, count);

}

/**
  * @brief  Transfer several bytes. One constant buffer used to send and
  *         one to receive data.
  *         begin() or beginTransaction() must be called at least once before.
  * @param  tx_buf: array of Tx bytes that is filled by the user before starting
  *                 the SPI transfer. If NULL, default dummy 0xFF bytes will be
  *                 clocked out.
  * @param  rx_buf: array of Rx bytes that will be filled by the slave during
  *                 the SPI transfer. If NULL, the received data will be discarded.
  * @param  count: number of bytes to send/receive.
  */
void SPIClass::transfer(const void *tx_buf, void *rx_buf, size_t count)
{
  spi_transfer(&_spi, ((const uint8_t *)tx_buf), ((uint8_t *)rx_buf), count);
}

/**
  * @brief  Not implemented.
  */
void SPIClass::attachInterrupt(void)
{
  // Should be enableInterrupt()
}

/**
  * @brief  Not implemented.
  */
void SPIClass::detachInterrupt(void)
{
  // Should be disableInterrupt()
}

