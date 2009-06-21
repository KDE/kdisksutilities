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

#include "format.h"

#include <Solid/Block>
#include <Solid/Device>
#include <Solid/DeviceInterface>
#include <Solid/StorageDrive>
#include <Solid/StorageVolume>

#include <KDebug>
#include <KMessageBox>
#include <KLocale>

Format::Format()
{
    m_util = 0;
    
    QWidget *mainWidget = new QWidget(this);
    ui.setupUi(mainWidget);
    setCentralWidget(mainWidget);

    m_devices = Solid::Device::listFromType(Solid::DeviceInterface::Block, QString());
    foreach (const Solid::Device &dev, m_devices){
        ui.deviceComboBox->addItem(dev.as<Solid::Block>()->device());
    }
    deviceChanged(ui.deviceComboBox->currentText());
    
    ui.filesystemComboBox->addItem("ext3");
    ui.filesystemComboBox->addItem("FAT");
    m_filesystemDescriptions.insert("ext3", i18n("ext3 filesystem is a Linux filesystem."));
    m_filesystemDescriptions.insert("FAT", i18n("FAT filesystem is used on Windows/DOS and it is the most common on devices like media players, cameras etc..."));
    updateDescription(ui.filesystemComboBox->currentText());
    
    connect(ui.deviceComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(deviceChanged(const QString &)));
    connect(ui.filesystemComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(updateDescription(const QString &)));
    connect(ui.formatButton, SIGNAL(clicked(bool)), this, SLOT(formatDisk()));
    connect(ui.closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void Format::deviceChanged(const QString &device)
{
   foreach (const Solid::Device &dev, m_devices){
        if (dev.as<Solid::Block>()->device() == device){
            if (dev.isDeviceInterface(Solid::DeviceInterface::StorageVolume)){
                ui.deviceInfo->setText(i18nc("Size and usage of a volume (46,6 GiB filesystem)", "%1 %2.", KGlobal::locale()->formatByteSize(dev.as<Solid::StorageVolume>()->size()), usageToString(dev.as<Solid::StorageVolume>()->usage())));
                const int fsIndex = ui.filesystemComboBox->findText(dev.as<Solid::StorageVolume>()->fsType());
                if (fsIndex >= 0){
                    ui.filesystemComboBox->setCurrentIndex(fsIndex);
                }
                
            }else if (dev.isDeviceInterface(Solid::DeviceInterface::StorageDrive)){
                ui.deviceInfo->setText(i18nc("product bus driveType (KDE KDEHD42 SCSI hard disk)", "%1 %2 %3.", dev.product(), busToString(dev.as<Solid::StorageDrive>()->bus()), driveTypeToString(dev.as<Solid::StorageDrive>()->driveType())));
            }
            
            ui.deviceIcon->setPixmap(KIcon(dev.icon()).pixmap(64, 64));
        }
    }
}

void Format::updateDescription(const QString &filesystem)
{    
    ui.filesystemDescription->setText(m_filesystemDescriptions[filesystem]);
}

void Format::formatDisk()
{
   foreach (const Solid::Device &dev, m_devices){
        if (dev.as<Solid::Block>()->device() == ui.deviceComboBox->currentText()){
            delete m_util;
            m_util = new BlockDeviceUtility(dev);
            connect(m_util, SIGNAL(jobCompleted(bool)), this, SLOT(jobCompleted(bool)));
            setWidgetsEnabled(false);
            m_util->format(ui.filesystemComboBox->currentText(), QStringList() << "label=" + ui.labelLineEdit->text());

            return;
        }
    }
}

void Format::setWidgetsEnabled(bool enabled)
{
    centralWidget()->setEnabled(enabled);
    ui.progressBar->setEnabled(!enabled);
}

void Format::jobCompleted(bool error)
{
    setWidgetsEnabled(true);
}

QString Format::usageToString(Solid::StorageVolume::UsageType usage) const
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

QString Format::busToString(Solid::StorageDrive::Bus bus) const
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

QString Format::driveTypeToString(Solid::StorageDrive::DriveType driveType) const
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

#include "format.moc"
