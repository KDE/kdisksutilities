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

#include "filesystemwidget.h"

#include <Solid/Block>
#include <Solid/Device>
#include <Solid/DeviceInterface>
#include <Solid/StorageDrive>
#include <Solid/StorageVolume>

#include <KDebug>
#include <KMessageBox>
#include <KLocale>

#include <kdiskmanager/blockdevice.h>
#include <kdiskmanager/filesystem.h>

FilesystemWidget::FilesystemWidget(BlockDevice *device, QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    blkDev = device;
    
    connect(ui.changeLabelButton, SIGNAL(clicked(bool)), this, SLOT(changeLabel()));
}

void FilesystemWidget::changeLabel()
{   
    connect(blkDev, SIGNAL(jobCompleted(bool)), this, SLOT(jobCompleted(bool)));
    //setWidgetsEnabled(false);
    blkDev->as<Filesystem>()->setLabel(ui.labelLineEdit->text());
}

#include "filesystemwidget.moc"
