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

#include <QDBusConnection>
#include <QDBusReply>
#include <QDBusObjectPath>
#include <QList>

#include <KDebug>
#include <KMessageBox>

typedef QList<QDBusObjectPath> ObjectPathList;

Format::Format()
{
    QWidget *mainWidget = new QWidget(this);
    ui.setupUi(mainWidget);
    setCentralWidget(mainWidget);

    m_deviceKitInterface = new QDBusInterface("org.freedesktop.DeviceKit.Disks", "/", "", QDBusConnection::systemBus());
    if (!m_deviceKitInterface->isValid()){
        KMessageBox::error(this, i18n("DeviceKit isn't running"));
    }
        
    QDBusReply<ObjectPathList> deviceKitReplyReply = m_deviceKitInterface->call("EnumerateDevices");
    if (!deviceKitReplyReply.isValid()){
        KMessageBox::error(this, i18n("Cannot enumerate devices"));
    }
        
    for (int i = 0; i < deviceKitReplyReply.value().size(); i++){
        ui.deviceComboBox->addItem(deviceKitReplyReply.value().at(i).path());
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
    m_fs = new QDBusInterface("org.freedesktop.DeviceKit.Disks", ui.deviceComboBox->currentText(), "", QDBusConnection::systemBus());
    connect(m_fs, SIGNAL(JobChanged(bool, QString, uint, bool, int, int, QString, double)), this, SLOT(jobChanged(bool, QString, uint, bool, int, int, QString, double)));
    if (!m_fs->isValid()){
        KMessageBox::error(this, i18n("DeviceKit isn't running"));
    }
    m_fs->asyncCall("FilesystemCreate", ui.filesystemComboBox->currentText(), QStringList() << "label=" + ui.labelLineEdit->text());
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
