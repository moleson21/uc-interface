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

#ifndef GUI_DATA_TRANSMIT_MINOR_KEYS_H
#define GUI_DATA_TRANSMIT_MINOR_KEYS_H

#ifdef __cplusplus
extern "C"
{
#endif

// Data Transmit Minor Keys enum
typedef enum {
    // Error and reset
    MINOR_KEY_DATA_TRANSMIT_ERROR = 0,

    // Set trasnmission size
    MINOR_KEY_DATA_TRANSMIT_SET_TRANS_SIZE,

    // Data Transmit Transfer
    MINOR_KEY_DATA_TRANSMIT_DATA
} MINOR_KEYS_DATA_TRANSMIT;

typedef enum {
    s2_data_transmit_settings_trans_end = 4
} S2_Data_Transmit_Settings;

#ifdef __cplusplus
}
#endif

#endif // GUI_DATA_TRANSMIT_MINOR_KEYS_H
