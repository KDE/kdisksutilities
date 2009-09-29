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

#include "disksdaemon.h"

#include <kdiskmanager/blockdevicemanager.h>
#include <kdiskmanager/blockdevice.h>

#include <kpluginfactory.h>
#include <KLocale>
#include <KAboutData>
#include <KNotification>
#include <KDebug>


extern "C" {
    int __kde_do_not_unload = 1;
}


K_PLUGIN_FACTORY(DisksDaemonFactory,
                 registerPlugin<DisksDaemon>();)
K_EXPORT_PLUGIN(DisksDaemonFactory("disksdaemon"))


DisksDaemon::DisksDaemon(QObject *parent, const QList<QVariant>&)
        : KDEDModule(parent)
{
    KGlobal::locale()->insertCatalog("disksdaemon");

    KAboutData aboutData("disksdaemon", "disksdaemon", ki18n("DisksDaemon"),
                         "0.1", ki18n("Disks daemon"),
                         KAboutData::License_GPL, ki18n("(c) 2009 Davide Bettio"),
                         KLocalizedString(), "http://www.kde.org");

    aboutData.addAuthor(ki18n("Dario Bettio"), ki18n("Maintainer"), "davide.bettio@kdemail.net",
                        "http://www.uninstall.it/");

    BlockDeviceManager *manager = new BlockDeviceManager(this);
    connect(manager, SIGNAL(deviceEvent(BlockDeviceUtility *)), this, SLOT(diskChanged(BlockDeviceUtility *)));
}

DisksDaemon::~DisksDaemon()
{
}

void DisksDaemon::diskChanged(BlockDevice *device)
{
    if (device->is(BlockDevice::RaidDevice)){
        if (device->raidIsDegraded()){
            KNotification::event(KNotification::Catastrophe, "RAID Disk Failure", i18n("Disk failure in %1 RAID.\n"
                                                                                        "Please replace the faulty device as soon as possible.",
                                                                                        device->device()));
        }
    }
}

#include "disksdaemon.moc"
