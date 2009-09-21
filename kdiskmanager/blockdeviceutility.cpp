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
#include <QDBusObjectPath>
#include <QDBusPendingReply>
#include <QDBusPendingCallWatcher>
#include <QDBusReply>

#include <Solid/Block>
#include <Solid/Device>
#include <Solid/DeviceInterface>

#include <KDebug>

BlockDeviceUtility::BlockDeviceUtility(const Solid::Device &dev)
{
    OrgFreedesktopDeviceKitDisksInterface disks("org.freedesktop.DeviceKit.Disks", "/org/freedesktop/DeviceKit/Disks", QDBusConnection::systemBus(), this);

    kDebug() << "Connected to DevKit-disks version: " << disks.daemonVersion();

    QDBusPendingReply<QDBusObjectPath> deviceKitReply = disks.FindDeviceByDeviceFile(dev.as<Solid::Block>()->device());
    deviceKitReply.waitForFinished();
    if (deviceKitReply.isError()){
        kDebug() << "Cannot enumerate devices" << "\n";
        return;
    }
    
    m_deviceInterface = new OrgFreedesktopDeviceKitDisksDeviceInterface("org.freedesktop.DeviceKit.Disks", deviceKitReply.value().path(), QDBusConnection::systemBus(), this);
    connect(m_deviceInterface, SIGNAL(JobChanged(bool, bool, const QString &, uint, double)), this, SLOT(jobChanged(bool, bool, const QString &, uint, double)));
}


BlockDeviceUtility::~BlockDeviceUtility()
{
}

void BlockDeviceUtility::format(const QString &filesystem, const QStringList& params)
{
    m_deviceInterface->FilesystemCreate(filesystem, params);
}

void BlockDeviceUtility::setLabel(const QString& label)
{
    kDebug() << "New label: " << label << "\n";
    QDBusPendingReply<> reply = m_deviceInterface->FilesystemSetLabel(label);
    reply.waitForFinished();
    kDebug() << "Errore: " << reply.isError() << "\n";
    kDebug() << reply.error().message() << "\n";
}

void BlockDeviceUtility::filesystemCheck(const QStringList& options)
{
#if 0
     delete watcher;
     QDBusPendingCall pcall = m_deviceInterface->asyncCall("FilesystemCheck", options);
     watcher = new QDBusPendingCallWatcher(pcall, this);
     
     QObject::connect(watcher, SIGNAL(finished(QDBusPendingCallWatcher*)), this, SLOT(callFinished(QDBusPendingCallWatcher*)));
#endif
}

void BlockDeviceUtility::jobChanged(bool jobinprogress, bool jobiscancellable, const QString &jobid, uint jobinitiatedbyuid, double jobpercentage)
{
/*
    if (!inProgress)
        emit jobCompleted(true);
*/

    kDebug() << "inProgess: " << jobinprogress << " Percent: " << jobpercentage << "\n";
}

void BlockDeviceUtility::callFinished(QDBusPendingCallWatcher *watcher)
{
#if 0 
    QDBusPendingReply<void> reply = *watcher;
    emit jobCompleted(reply.isError());
#endif
}

#include "blockdeviceutility.moc"
