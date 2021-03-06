/*
 * uC Interface - A GUI for Programming & Interfacing with Microcontrollers
 * Copyright (C) 2018  Mitchell Oleson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef UC_GENERIC_FSM_H
#define UC_GENERIC_FSM_H

/*
 * Create a file that inplements main() to start the program
 * and defines the externs matching descriptions below.
 *
*/


#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "uc-generic-def.h"
#include "gui-base-major-keys.h"

/* FSM Public Functions */
void fsm_setup(uint32_t buffer_len);
void fsm_destroy();
void fsm_poll();
bool fsm_isr();
void fsm_run();
void fsm_send(uint8_t s_major_key, uint8_t s_minor_key, const uint8_t* data, uint32_t data_len);
void fsm_send_ready();

// Acts as a general flag variable for:
//   1) malloc or realloc failures (gets set to 1)
//   2) Force an exit of internal loop (gets set to 2)
static uint8_t fsm_error;


/*** Following extern functions must be defined on a per uC basis ***/

/* Resets all the data and pins on the uc */
extern void uc_reset();
/* Resets receive buffer on the uc */
extern void uc_reset_buffers();
/* Removes & returns one byte from received */
extern uint8_t uc_getch();
/* Waits for timeout microseconds (args: timeout) */
extern void uc_delay_us(uint32_t us);
/* Waits for timeout milliseconds (args: timeout) */
extern void uc_delay_ms(uint32_t ms);
/* Returns number of bytes available */
extern uint32_t uc_bytes_available();
/* Sends data across the connection, returns number of bytes sent */
extern uint8_t uc_send(uint8_t* data, uint32_t data_len);

/* Recomend including the predefined FSM for each of the below
 * and writing a main() with definitions for each extern defined in the
 * FSM as opposed to reimplimenting the key parsing included (unless
 * space efficiency, speed, or not implementing (stub it))
*/
#ifdef UC_IO
/* Parses IO minor key and acts */
extern void uc_io(uint8_t major_key, uint8_t minor_key, const uint8_t* buffer, uint32_t buffer_len);
#endif

#ifdef UC_DATA_TRANSMIT
/* Parses Data Transmit minor key and acts */
extern void uc_data_transmit(uint8_t major_key, uint8_t minor_key, const uint8_t* buffer, uint32_t buffer_len);
#endif

#ifdef UC_PROGRAMMER
/* Parses Programmer minor key and acts */
extern void uc_programmer(uint8_t major_key, uint8_t minor_key, const uint8_t* buffer, uint32_t buffer_len);
#endif

#ifdef UC_CUSTOM_CMD
/* Parses Custom CMD minor key and acts */
extern void uc_custom_cmd(uint8_t major_key, uint8_t minor_key, const uint8_t* buffer, uint32_t buffer_len);
#endif

#ifdef __cplusplus
}
#endif

#endif // UC_GENERIC_FSM_H
