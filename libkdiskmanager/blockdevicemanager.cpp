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

#include "blockdevicemanager.h"

#include "OrgFreedesktopDeviceKitDisks.h"
#include "OrgFreedesktopDeviceKitDisksDevice.h"

#include <QDBusConnection>
#include <QDBusObjectPath>
#include <QDBusPendingReply>
#include <QDBusPendingCallWatcher>
#include <QDBusReply>

#include <Solid/Block>
#include <Solid/Device>
#include <Solid/DeviceInterface>

#include <KDebug>

BlockDeviceManager::BlockDeviceManager(QObject *parent)
    : QObject(parent)
{
    m_disks = new OrgFreedesktopDeviceKitDisksInterface("org.freedesktop.DeviceKit.Disks", "/org/freedesktop/DeviceKit/Disks", QDBusConnection::systemBus(), this);
    connect(m_disks, SIGNAL(DeviceChanged(const QDBusObjectPath &)), this, SLOT(deviceChanged(const QDBusObjectPath &)));
}


BlockDeviceManager::~BlockDeviceManager()
{
}

void BlockDeviceManager::deviceChanged(const QDBusObjectPath &path)
{
    emit deviceEvent(new BlockDevice(path.path()));
}

BlockDevice *BlockDeviceManager::blockDevice(const Solid::Device &dev)
{
    OrgFreedesktopDeviceKitDisksInterface disks("org.freedesktop.DeviceKit.Disks", "/org/freedesktop/DeviceKit/Disks", QDBusConnection::systemBus());

    kDebug() << "Connected to DevKit-disks version: " << disks.daemonVersion();

    QDBusPendingReply<QDBusObjectPath> deviceKitReply = disks.FindDeviceByDeviceFile(dev.as<Solid::Block>()->device());
    deviceKitReply.waitForFinished();
    if (deviceKitReply.isError()){
        kDebug() << "Cannot enumerate devices" << "\n";
        return 0;
    }
    
    return new BlockDevice(deviceKitReply.value().path());
}

#include "blockdevicemanager.moc"
