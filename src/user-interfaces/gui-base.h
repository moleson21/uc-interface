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

#ifndef GUI_BASE_H
#define GUI_BASE_H

#include <QWidget>
#include <QMap>
#include <QVariant>

#include "gui-base-major-keys.h"
#include "../gui-helpers/gui-helper.h"
#include <QDebug>

class GUI_BASE : public QWidget
{
    Q_OBJECT

public:
    GUI_BASE(QWidget *parent = 0);
    ~GUI_BASE();

    virtual uint8_t get_GUI_key();
    virtual void parseConfigMap(QMap<QString, QVariant>* configMap);

signals:
    // Read updates
    void readyRead(QByteArray data);

    // File transmit
    void transmit_file(uint8_t major_key, uint8_t minor_key, QString filePath);
    void transmit_file_chunked(uint8_t major_key, uint8_t minor_key, QString filePath, char sep);

    // Chunk transmit
    void transmit_chunk(uint8_t major_key, uint8_t minor_key, QByteArray chunk = QByteArray(), bool force_envelope = false);

    // Send progress bar updates
    void progress_update_recv(int progress, QString label);
    void progress_update_send(int progress, QString label);

public slots:
    void reset_remote();
    virtual void reset_gui();       // Must not call reset_remote()

protected slots:
    // Receive and parse data
    virtual void receive_gui(QByteArray recvData);

    // Reset the gui and connected device
    virtual void on_ResetGUI_Button_clicked();

    // Set progress bar updates
    virtual void set_progress_update_recv(int progress, QString label);
    virtual void set_progress_update_send(int progress, QString label);

    // File sending
    void send_file(uint8_t major_key, uint8_t minor_key, QString filePath);
    void send_file_chunked(uint8_t major_key, uint8_t minor_key, QString filePath, char sep);

    // Chunk sending
    void send_chunk(uint8_t major_key, uint8_t minor_key, QByteArray chunk = QByteArray(), bool force_envelope = false);
    void send_chunk(uint8_t major_key, uint8_t minor_key, std::initializer_list<uint8_t> chunk, bool force_envelope = false);

protected:
    // Local variables
    uint8_t gui_key;

    // Receive arrays & variables
    QByteArray rcvd_formatted;
    uint32_t current_recv_length;
    uint32_t expected_recv_length;
    bool start_data;

    // Returns if send is a data request
    virtual bool isDataRequest(uint8_t minorKey);

    // Save to file
    void save_rcvd_formatted();

    // Other functions
    void set_expected_recv_length(QByteArray recv_length);
    void update_current_recv_length(QByteArray recvData);
};

#endif // GUI_BASE_H
