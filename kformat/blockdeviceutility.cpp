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

 #include "blockdeviceutility.h"
 
 
#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusObjectPath>

#include <Solid/Block>
#include <Solid/Device>
#include <Solid/DeviceInterface>

#include <KDebug>

BlockDeviceUtility::BlockDeviceUtility(const Solid::Device &dev)
{
    QDBusInterface deviceKitInterface("org.freedesktop.DeviceKit.Disks", "/", "", QDBusConnection::systemBus());
    
    QDBusReply<QDBusObjectPath> deviceKitReply = deviceKitInterface.call("FindDeviceByDeviceFile", dev.as<Solid::Block>()->device());
    if (!deviceKitReply.isValid()){
        kDebug() << "Cannot enumerate devices" << "\n";
    }

    m_deviceInterface = new QDBusInterface("org.freedesktop.DeviceKit.Disks", deviceKitReply.value().path(), "", QDBusConnection::systemBus());
    connect(m_deviceInterface, SIGNAL(JobChanged(bool, QString, uint, bool, int, int, QString, double)), this, SLOT(jobChanged(bool, QString, uint, bool, int, int, QString, double)));
}


BlockDeviceUtility::~BlockDeviceUtility()
{
    delete m_deviceInterface;
}

void BlockDeviceUtility::format(const QString &filesystem, const QStringList& params)
{
    m_deviceInterface->asyncCall("FilesystemCreate", filesystem, params);
}

void BlockDeviceUtility::setLabel(const QString& label)
{
    m_deviceInterface->asyncCall("FilesystemSetLabel", label);
}

void BlockDeviceUtility::filesystemCheck(const QStringList& options)
{
    m_deviceInterface->asyncCall("FilesystemCheck", options);
}

void BlockDeviceUtility::jobChanged(bool inProgress, QString, uint, bool, int, int, QString, double d)
{
    if (!inProgress)
        emit jobCompleted(true);

    kDebug() << "inProgess: " << inProgress << " Percent: " << d << "\n";
}

#include "blockdeviceutility.moc"
