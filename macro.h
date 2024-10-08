/*
  Copyright (c) 2016 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Macro_h
#define Marco_h

///////////////////////////////////////////////////////////////////////////////////////
// Macros to support Arduino functions
////////////////////////////////////////////////////////////////////////////////////////

#define pgm_read_byte(addr) (*(uint8_t *)(addr))
#define pgm_read_word(addr) (*(unsigned short *)(addr))
#define pgm_read_dword(addr) (*(unsigned long *)(addr))
#define pgm_read_float(addr) (*(float *)(addr))

#define delay(x)  HAL_Delay(x)
#define millis()  HAL_GetTick()
#define random(x) random()*x
#define yield()

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

#endif // Macro_h