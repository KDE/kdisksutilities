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

#include <KDebug>
#include <KMessageBox>

#include "blockdeviceutility.h"

Format::Format()
{
    QWidget *mainWidget = new QWidget(this);
    ui.setupUi(mainWidget);
    setCentralWidget(mainWidget);

    m_devices = Solid::Device::listFromType(Solid::DeviceInterface::Block, QString());
    foreach (const Solid::Device &dev, m_devices){
        ui.deviceComboBox->addItem(dev.as<Solid::Block>()->device());
    }
    
    ui.deviceIcon->setPixmap(KIcon("drive-harddisk").pixmap(64, 64));
    ui.deviceInfo->setText(i18n("Device"));
    
    ui.filesystemComboBox->addItem("ext3");
    ui.filesystemComboBox->addItem("FAT");
    m_filesystemDescriptions.insert("ext3", i18n("ext3 filesystem is a Linux filesystem."));
    m_filesystemDescriptions.insert("FAT", i18n("FAT filesystem is used on Windows/DOS and it is the most common on devices like media players, cameras etc..."));
    updateDescription(ui.filesystemComboBox->currentText());
    
    connect(ui.filesystemComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(updateDescription(const QString &)));
    connect(ui.formatButton, SIGNAL(clicked(bool)), this, SLOT(formatDisk()));
    connect(ui.closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void Format::updateDescription(const QString &filesystem)
{    
    ui.filesystemDescription->setText(m_filesystemDescriptions[filesystem]);
}

void Format::formatDisk()
{
   foreach (const Solid::Device &dev, m_devices){
        if (dev.as<Solid::Block>()->device() == ui.deviceComboBox->currentText()){
            BlockDeviceUtility util(dev);
            util.format(ui.filesystemComboBox->currentText(), QStringList() << "label=" + ui.labelLineEdit->text());

            return;
        }
    }
}

void Format::setWidgetsEnabled(bool enabled)
{
    centralWidget()->setEnabled(enabled);
    ui.progressBar->setEnabled(!enabled);
}

void Format::jobChanged(bool inProgress, QString, uint, bool, int, int, QString, double d)
{
    if (centralWidget()->isEnabled() != !inProgress){
        setWidgetsEnabled(!inProgress);
    }
    
    if (d >= 0);
        ui.progressBar->setValue((int) d);

    kDebug() << "inProgess: " << inProgress << " Percent: " << d << "\n";
}

#include "format.moc"
