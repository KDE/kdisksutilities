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

#include "solidstrings.h"
 
#include <KLocale>

QString usageToString(Solid::StorageVolume::UsageType usage)
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

QString busToString(Solid::StorageDrive::Bus bus)
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

QString driveTypeToString(Solid::StorageDrive::DriveType driveType)
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
