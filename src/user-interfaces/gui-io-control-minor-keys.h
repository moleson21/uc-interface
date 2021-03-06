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

#ifndef GUI_PIN_IO_MINOR_KEYS_H
#define GUI_PIN_IO_MINOR_KEYS_H

#ifdef __cplusplus
extern "C"
{
#endif

// IO Control Minor Keys enum
typedef enum {
    // Error and reset
    MINOR_KEY_IO_ERROR = 0,

    // AIO Keys
    MINOR_KEY_IO_AIO,
    MINOR_KEY_IO_AIO_SET,
    MINOR_KEY_IO_AIO_WRITE,
    MINOR_KEY_IO_AIO_READ,
    MINOR_KEY_IO_AIO_READ_ALL,

    // DIO Keys
    MINOR_KEY_IO_DIO,
    MINOR_KEY_IO_DIO_SET,
    MINOR_KEY_IO_DIO_WRITE,
    MINOR_KEY_IO_DIO_READ,
    MINOR_KEY_IO_DIO_READ_ALL,

    // Remote Communications
    MINOR_KEY_IO_REMOTE_CONN,
    MINOR_KEY_IO_REMOTE_CONN_SET,
    MINOR_KEY_IO_REMOTE_CONN_READ,
    MINOR_KEY_IO_REMOTE_CONN_SEND,
    MINOR_KEY_IO_REMOTE_CONN_CONNECTED
} MINOR_KEYS_IO;

/* Stage #2 (s2) io set key positions enum */
typedef enum {
    s2_io_pin_num_loc = 0,
    s2_io_value_high_loc,
    s2_io_value_low_loc,
    s2_io_combo_loc,
    s2_io_set_end,
    s2_io_read_end = s2_io_value_high_loc,
    s2_io_write_end = s2_io_combo_loc
} S2_IO_Settings;

#ifdef __cplusplus
}
#endif

#endif // GUI_PIN_IO_MINOR_KEYS_H
