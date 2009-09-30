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

#ifndef BLOCKDEVICE_H
#define BLOCKDEVICE_H

#include <kdemacros.h>

#include <QStringList>

namespace Solid
{
    class Device;
}

class BlockDeviceInterface;

class KDE_EXPORT BlockDevice : public QObject
{
    Q_OBJECT
        
    public:
        enum BlockDeviceType
        {
            RaidDevice,
            RaidComponentDevice,
            DriveDevice,
            FilesystemDevice
        };

        ~BlockDevice();
        
        bool is(BlockDeviceType t);
        QObject *as(BlockDeviceType t);
        
        template <class T> T *as()
        {
            BlockDeviceType type = T::blockDeviceType();

            return qobject_cast<T *>(as(type));
        }

        void format(const QString &filesystem, const QStringList& params);
        QString device();
        
        friend class BlockDeviceManager;
        friend class Raid;
        friend class RaidComponent;
        friend class Filesystem;
        
    signals:
        void jobCompleted(bool success);
        
    private:
        BlockDevice(const QString &device);
        
        void setLabel(const QString& label);
        void filesystemCheck(const QStringList& options);
        
        bool raidIsDegraded();
        QString raidStatus();
        QString raidLevel();
        QString parentRaid();

        class Private;
        Private *d;
};

#endif
