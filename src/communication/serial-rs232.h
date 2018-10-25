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

#ifndef SERIAL_RS232_H
#define SERIAL_RS232_H

#include "comms-base.h"
#include <QSerialPort>
#include <QSerialPortInfo>

typedef struct {
    QString port;
    int32_t baudrate;
    int32_t dataBits;
    QString direction;
    QString flowControl;
    QString parity;
    float stopBits;
} Serial_RS232_Settings;
#define Serial_RS232_Settings_DEFAULT Serial_RS232_Settings{\
    .port="", .baudrate=9600, .dataBits=8, .direction="All",\
    .flowControl="No", .parity="No", .stopBits=1.0}

class Serial_RS232 : public COMMS_BASE
{
    Q_OBJECT

public:
    Serial_RS232(Serial_RS232_Settings* serial_settings, QObject *parent = NULL);
    ~Serial_RS232();

    virtual void open();
    virtual void close();
    virtual bool isConnected();

    static QStringList* getDevices();
    static QStringList Baudrate_Defaults;

public slots:
    virtual void write(QByteArray writeData);

private slots:
    virtual void read();
    void checkError(QSerialPort::SerialPortError);

private:
    QSerialPort *rs232;

    void parseSettings(Serial_RS232_Settings* serial_settings);
};

#endif // SERIAL_RS232_H
