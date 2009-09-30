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

#include "filesystem.h"

class Filesystem::Private
{
    public:
        BlockDevice *parent;
        
        Private(BlockDevice *p)
        {
            parent = p;
        }
};

Filesystem::Filesystem(BlockDevice *dev)
    : QObject(dev), d(new Private(dev))
{
    
}

BlockDevice::BlockDeviceType Filesystem::blockDeviceType()
{
    return BlockDevice::FilesystemDevice;
}

QString Filesystem::type()
{
    return "";
}

void Filesystem::setLabel(const QString& label)
{
    d->parent->setLabel(label);
}

void Filesystem::filesystemCheck(const QStringList& options)
{
    d->parent->filesystemCheck(options);
}

#include "filesystem.moc"
