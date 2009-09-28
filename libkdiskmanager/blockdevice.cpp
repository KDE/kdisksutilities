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

#include "blockdevice.h"

#include "OrgFreedesktopDeviceKitDisks.h"
#include "OrgFreedesktopDeviceKitDisksDevice.h"

#include <QDBusInterface>
#include <QDBusConnection>
#include <QDBusObjectPath>
#include <QDBusPendingReply>
#include <QDBusPendingCallWatcher>
#include <QDBusReply>

#include <Solid/Block>
#include <Solid/Device>
#include <Solid/DeviceInterface>

#include <KDebug>

class BlockDevice::Private
{
    public:
        OrgFreedesktopDeviceKitDisksDeviceInterface *m_deviceInterface;
};

BlockDevice::BlockDevice(const Solid::Device &dev)
    : d(new Private())
{
    OrgFreedesktopDeviceKitDisksInterface disks("org.freedesktop.DeviceKit.Disks", "/org/freedesktop/DeviceKit/Disks", QDBusConnection::systemBus(), this);

    kDebug() << "Connected to DevKit-disks version: " << disks.daemonVersion();

    QDBusPendingReply<QDBusObjectPath> deviceKitReply = disks.FindDeviceByDeviceFile(dev.as<Solid::Block>()->device());
    deviceKitReply.waitForFinished();
    if (deviceKitReply.isError()){
        kDebug() << "Cannot enumerate devices" << "\n";
        return;
    }
    
    d->m_deviceInterface = new OrgFreedesktopDeviceKitDisksDeviceInterface("org.freedesktop.DeviceKit.Disks", deviceKitReply.value().path(), QDBusConnection::systemBus(), this);
    connect(d->m_deviceInterface, SIGNAL(JobChanged(bool, bool, const QString &, uint, double)), this, SLOT(jobChanged(bool, bool, const QString &, uint, double)));
}

BlockDevice::BlockDevice(const QString &device)
    : d(new Private())
{
    OrgFreedesktopDeviceKitDisksInterface disks("org.freedesktop.DeviceKit.Disks", "/org/freedesktop/DeviceKit/Disks", QDBusConnection::systemBus(), this);

    kDebug() << "Connected to DevKit-disks version: " << disks.daemonVersion();

    d->m_deviceInterface = new OrgFreedesktopDeviceKitDisksDeviceInterface("org.freedesktop.DeviceKit.Disks", device, QDBusConnection::systemBus(), this);
    connect(d->m_deviceInterface, SIGNAL(JobChanged(bool, bool, const QString &, uint, double)), this, SLOT(jobChanged(bool, bool, const QString &, uint, double)));    
}

BlockDevice::~BlockDevice()
{
}


void BlockDevice::format(const QString &filesystem, const QStringList& params)
{
    QDBusPendingReply<> reply = d->m_deviceInterface->FilesystemCreate(filesystem, params);
    reply.waitForFinished();
     
    if (reply.isError()){
       kDebug() << reply.error().message() << "\n";
    }
}

void BlockDevice::setLabel(const QString& label)
{
    QDBusPendingReply<> reply = d->m_deviceInterface->FilesystemSetLabel(label);
    reply.waitForFinished();

    if (reply.isError()){
        kDebug() << reply.error().message() << "\n";
    }
}

void BlockDevice::filesystemCheck(const QStringList& options)
{
    QDBusPendingReply<> reply = d->m_deviceInterface->FilesystemCheck(options);
    reply.waitForFinished();
     
    if (reply.isError()){
       kDebug() << reply.error().message() << "\n";
    }
}


bool BlockDevice::raidIsDegraded()
{
    return d->m_deviceInterface->linuxMdIsDegraded();
}

QString BlockDevice::device()
{
    return d->m_deviceInterface->deviceFile();
}

bool BlockDevice::isRaid()
{
    return d->m_deviceInterface->deviceIsLinuxMd(); 
}

bool BlockDevice::isRaidComponent()
{
    return d->m_deviceInterface->deviceIsLinuxMdComponent(); 
}

QString BlockDevice::raidLevel()
{
    if (d->m_deviceInterface->deviceIsLinuxMdComponent()){
        return d->m_deviceInterface->linuxMdComponentLevel();
    }else{
        return d->m_deviceInterface->linuxMdLevel(); 
    }
}


QString BlockDevice::raidStatus()
{
    if (d->m_deviceInterface->deviceIsLinuxMdComponent()){
        return d->m_deviceInterface->linuxMdComponentState().at(0); //UNCLEAR
    }else{
        return d->m_deviceInterface->linuxMdState(); 
    }
}

QString BlockDevice::parentRaid()
{
    return d->m_deviceInterface->linuxMdComponentHolder().path(); 
}

#include "blockdevice.moc"
