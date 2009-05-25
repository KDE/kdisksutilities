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

#include <KAboutData>
#include <KApplication>
#include <KCmdLineArgs>

#include "diskmanager.h"

static const char *version = "v0.0.1";
static const char description[] = I18N_NOOP("KDE Disk Format Utility");
static const char text[] = I18N_NOOP("");
static const char homepageUrl[] = "http://www.kde.org/";

int main(int argc, char **argv)
{
    KAboutData aboutData("kdiskmanager", 0, ki18n("Disk Manager"), version, ki18n(description), KAboutData::License_GPL, KLocalizedString(), ki18n(text), homepageUrl);
    KCmdLineArgs::init(argc, argv, &aboutData);
    KApplication app;
  
    (new DiskManager())->show();

    return app.exec();
}
