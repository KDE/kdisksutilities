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

#include "diskmanager.h"

#include "raidwidget.h"
#include "raidcomponentwidget.h"

#include <Solid/Block>
#include <Solid/Device>
#include <Solid/DeviceInterface>
#include <Solid/StorageDrive>
#include <Solid/StorageVolume>

#include <KDebug>
#include <KMessageBox>
#include <KLocale>

#include "kdiskmanager/blockdevice.h"

DiskManager::DiskManager()
{
    m_util = 0;
    m_tmpWidget = 0;
    QWidget *mainWidget = new QWidget(this);
    ui.setupUi(mainWidget);
    setCentralWidget(mainWidget);

    m_devices = Solid::Device::listFromType(Solid::DeviceInterface::Block, QString());
    foreach (const Solid::Device &dev, m_devices){
        ui.deviceComboBox->addItem(dev.as<Solid::Block>()->device());
    }
    selectedDeviceChanged(ui.deviceComboBox->currentText());
    
    connect(ui.changeLabelButton, SIGNAL(clicked(bool)), this, SLOT(changeLabel()));
    connect(ui.deviceComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(selectedDeviceChanged(const QString &)));
    connect(ui.closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void DiskManager::selectedDeviceChanged(const QString &device)
{
   foreach (const Solid::Device &dev, m_devices){
        if (dev.as<Solid::Block>()->device() == device){
            if (dev.isDeviceInterface(Solid::DeviceInterface::StorageVolume)){
                ui.deviceInfo->setText(i18nc("Size and usage of a volume (46,6 GiB filesystem)", "%1 %2.", KGlobal::locale()->formatByteSize(dev.as<Solid::StorageVolume>()->size()), usageToString(dev.as<Solid::StorageVolume>()->usage())));
                
            }else if (dev.isDeviceInterface(Solid::DeviceInterface::StorageDrive)){
                ui.deviceInfo->setText(i18nc("product bus driveType (KDE KDEHD42 SCSI hard disk)", "%1 %2 %3.", dev.product(), busToString(dev.as<Solid::StorageDrive>()->bus()), driveTypeToString(dev.as<Solid::StorageDrive>()->driveType())));
            }
            
            ui.deviceIcon->setPixmap(KIcon(dev.icon()).pixmap(64, 64));
            
            BlockDevice *blkDev = new BlockDevice(dev);
            QWidget *wdg;
            if (blkDev->isRaidComponent()){
                wdg = new RaidComponentWidget(blkDev);
            }else if (blkDev->isRaid()){
                wdg = new RaidWidget(blkDev);
            }else{
                wdg = new QWidget();
            }
            
            if (m_tmpWidget){
                ui.widget->layout()->removeWidget(m_tmpWidget);
                delete m_tmpWidget;
            }
            m_tmpWidget = wdg;
            ui.widget->layout()->addWidget(wdg);
        }
    }
}

void DiskManager::changeLabel()
{   
    foreach (const Solid::Device &dev, m_devices){
      if (dev.as<Solid::Block>()->device() == ui.deviceComboBox->currentText()){
          delete m_util;
          m_util = new BlockDevice(dev);
          connect(m_util, SIGNAL(jobCompleted(bool)), this, SLOT(jobCompleted(bool)));
          setWidgetsEnabled(false);
          m_util->setLabel(ui.labelLineEdit->text());

          return;
      }
    }
}

void DiskManager::setWidgetsEnabled(bool enabled)
{
    centralWidget()->setEnabled(enabled);
}

void DiskManager::jobChanged(bool inProgress, QString, uint, bool, int, int, QString, double d)
{
    if (centralWidget()->isEnabled() != !inProgress){
        setWidgetsEnabled(!inProgress);
    }

    kDebug() << "inProgess: " << inProgress << " Percent: " << d << "\n";
}

QString DiskManager::usageToString(Solid::StorageVolume::UsageType usage)
{
    switch (usage){
        case Solid::StorageVolume::Other:
            return i18n("other usage");
                      
            break;
            
        case Solid::StorageVolume::Unused:
            return i18n("unused volume");
                      
            break;
            
        case Solid::StorageVolume::FileSystem:
            return i18n("filesystem");
                      
            break;
            
        case Solid::StorageVolume::PartitionTable:
            return i18n("partition table");
                      
            break;
            
        case Solid::StorageVolume::Raid:
            return i18n("raid volume");  
                      
            break;
            
        case Solid::StorageVolume::Encrypted:
            return i18n("encrypted volume");
                      
            break;
        }
        
        return i18n("unknown");
}

QString DiskManager::busToString(Solid::StorageDrive::Bus bus)
{
    switch (bus){
        case Solid::StorageDrive::Ide:
            return i18n("IDE");

            break;
                        
        case Solid::StorageDrive::Usb:
            return i18n("USB");
            
            break;
                        
        case Solid::StorageDrive::Ieee1394:
            return i18n("IEEE 1394");
                        
            break;
                        
        case Solid::StorageDrive::Scsi:
            return i18n("SCSI");
                        
            break;
                        
        case Solid::StorageDrive::Sata:
            return i18n("SATA");
                        
            break;
                        
        case Solid::StorageDrive::Platform:
            return i18n("platform");
                        
            break;
    }
    
    return i18n("unknown");
}

QString DiskManager::driveTypeToString(Solid::StorageDrive::DriveType driveType)
{
    switch (driveType){
        case Solid::StorageDrive::HardDisk:
            return i18n("hard disk");
            
            break;
                        
        case Solid::StorageDrive::CdromDrive:
            return i18n("cdrom drive");
                        
            break;
                        
        case Solid::StorageDrive::Floppy:
            return i18n("floppy disk");
                        
            break;
                        
        case Solid::StorageDrive::Tape:
            return i18n("tape");
                        
            break;
                        
        case Solid::StorageDrive::CompactFlash:
            return i18n("compact flash");
                        
            break;

        case Solid::StorageDrive::MemoryStick:
            return i18n("memory stick");
                        
            break;

        case Solid::StorageDrive::SmartMedia:
            return i18n("smart media");
                        
            break;

        case Solid::StorageDrive::SdMmc:
            return i18n("sd mmc");
                        
            break;

        case Solid::StorageDrive::Xd:
            return i18n("xd");
                        
            break;
        }
        
        return i18n("unknown");
}

#include "diskmanager.moc"
