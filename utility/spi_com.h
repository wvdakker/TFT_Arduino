/*
 * Copyright (c) 2016 Frederic Pillon <frederic.pillon@st.com> for
 * STMicroelectronics. All right reserved.
 * Header utility of the spi module for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_COM_H
#define __SPI_COM_H

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/

struct spi_s {
  SPI_TypeDef *spi;
};

typedef struct spi_s spi_t;

// Defines a default timeout delay in milliseconds for the SPI transfer
#ifndef SPI_TRANSFER_TIMEOUT
#define SPI_TRANSFER_TIMEOUT 1000
#elif SPI_TRANSFER_TIMEOUT <= 0
#error "SPI_TRANSFER_TIMEOUT cannot be less or equal to 0!"
#endif

///@brief SPI errors
typedef enum {
  SPI_OK = 0,
  SPI_TIMEOUT = 1,
  SPI_ERROR = 2
} spi_status_e;

/* Exported functions ------------------------------------------------------- */

spi_status_e spi_transfer(spi_t *obj, const uint8_t *tx_buffer, uint8_t *rx_buffer, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif /* __SPI_COM_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
