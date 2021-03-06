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

#ifndef GUI_WELCOME_H
#define GUI_WELCOME_H

#include "gui-base.hpp"

namespace Ui {
class GUI_WELCOME;
}

class GUI_WELCOME : public GUI_BASE
{
    Q_OBJECT

public:
    explicit GUI_WELCOME(QWidget *parent = 0);
    ~GUI_WELCOME();

    void set_header(QString text);
    QString get_header();

    void set_msg(QString text);
    QString get_msg();

    void set_buttons_enabled(bool enabled);
    bool get_buttons_enabled();

    virtual void parseConfigMap(QMap<QString, QVariant> *configMap);

protected:
    /** Declare ui accessor for testing **/
    Ui::GUI_WELCOME *get_ui();

private:
    Ui::GUI_WELCOME *ui;
};

#endif // GUI_WELCOME_H
