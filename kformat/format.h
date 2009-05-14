/***************************************************************************
 *   Copyright 2009 by Davide Bettio <davide.bettio@kdemail.net>           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef FORMAT_H
#define FORMAT_H

#include <QDBusInterface>

#include <KMainWindow>
#include "ui_format.h"

class Format : public KMainWindow
{
    Q_OBJECT
        
    public:
        Format();
        
    private slots:
        void updateDescription(const QString &filesystem);
        void formatDisk();
        void jobChanged(bool, QString, uint, bool, int, int, QString, double);
        
    private:
        Ui::Format ui;
        QDBusInterface *m_deviceKitInterface;
        QDBusInterface *m_fs;
        QHash<QString, QString> m_filesystemDescriptions;
        
        void setWidgetsEnabled(bool enabled);
};

#endif
