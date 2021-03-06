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

#include "raid.h"
#include "raidcomponent.h"
#include "filesystem.h"

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

BlockDevice::BlockDevice(const QString &device)
    : d(new Private())
{
    OrgFreedesktopDeviceKitDisksInterface disks("org.freedesktop.DeviceKit.Disks", "/org/freedesktop/DeviceKit/Disks", QDBusConnection::systemBus());

    kDebug() << "Connected to DevKit-disks version: " << disks.daemonVersion();

    d->m_deviceInterface = new OrgFreedesktopDeviceKitDisksDeviceInterface("org.freedesktop.DeviceKit.Disks", device, QDBusConnection::systemBus(), this);
    connect(d->m_deviceInterface, SIGNAL(JobChanged(bool, bool, const QString &, uint, double)), this, SLOT(jobChanged(bool, bool, const QString &, uint, double)));    
}

BlockDevice::~BlockDevice()
{
}


bool BlockDevice::is(BlockDeviceType t)
{
    switch(t){
        case RaidDevice:
            return d->m_deviceInterface->deviceIsLinuxMd();
            
        case RaidComponentDevice:
            return d->m_deviceInterface->deviceIsLinuxMdComponent();

        case DriveDevice:
            return false;

        case FilesystemDevice:
            return d->m_deviceInterface->idUsage() == "filesystem";

        default:
            return false;
    }
}

QObject *BlockDevice::as(BlockDeviceType t)
{
    switch(t){
        case RaidDevice:
            return new Raid(this);
            
        case RaidComponentDevice:
            return new RaidComponent(this);
            
        case DriveDevice:
            return 0;

        case FilesystemDevice:
            return new Filesystem(this);
            
        default:
            return 0;
    }
}

void BlockDevice::format(const QString &filesystem, const QStringList& params)
{
    QDBusPendingReply<> reply = d->m_deviceInterface->FilesystemCreate(filesystem, params);
    reply.waitForFinished();
     
    if (reply.isError()){
       kDebug() << reply.error().message() << "\n";
       
       if (reply.error().message() == "Not Authorized"){
            emit formatCompleted(PermissionsError);
       }
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

void BlockDevice::jobChanged(bool, bool, const QString &, uint, double)
{
}

#include "blockdevice.moc"
