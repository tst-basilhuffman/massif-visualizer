/*
   This file is part of Massif Visualizer

   Copyright 2010 Milian Wolff <mail@milianw.de>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License or (at your option) version 3 or any later version
   accepted by the membership of KDE e.V. (or its successor approved
   by the membership of KDE e.V.), which shall act as a proxy
   defined in Section 14 of version 3 of the license.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <KLocalizedString>
#include <KAboutData>
#include <KCmdLineArgs>
#include <KCmdLineOptions>

#include <QApplication>
#include <QUrl>

#include <QtCore/QDebug>

#include "mainwindow.h"

int main( int argc, char *argv[] )
{
    QApplication app(argc, argv);

    KAboutData aboutData(QStringLiteral("massif-visualizer"), i18n("Massif Visualizer"), QStringLiteral("0.5"),
                         i18n("A visualizer for output generated by Valgrind's massif tool."), KAboutLicense::LGPL,
                         i18n("Copyright 2010-2014, Milian Wolff <mail@milianw.de>"), QString(), QStringLiteral("massif-visualizer@kde.org"));

    aboutData.addAuthor(i18n("Milian Wolff"), i18n("Original author, maintainer"),
                        QStringLiteral("mail@milianw.de"), QStringLiteral("http://milianw.de"));

    aboutData.addAuthor(i18n("Arnold Dumas"), i18n("Multiple document interface, bug fixes"),
                        QStringLiteral("contact@arnolddumas.fr"), QStringLiteral("http://arnolddumas.fr"));

    aboutData.setOrganizationDomain("kde.org");
    KAboutData::setApplicationData(aboutData);

    app.setApplicationName(aboutData.componentName());
    app.setApplicationDisplayName(aboutData.displayName());
    app.setOrganizationDomain(aboutData.organizationDomain());
    app.setWindowIcon(QIcon::fromTheme("office-chart-area"));
    app.setApplicationVersion(aboutData.version());

// TODO: KF5
#if 0
    KCmdLineArgs::init( argc, argv, &aboutData, KCmdLineArgs::CmdLineArgNone );
    KCmdLineOptions options;
    options.add("+file(s)", ki18n("Opens given output file(s) and visualize it."));

    KCmdLineArgs::addCmdLineOptions( options );
    KCmdLineArgs* args = KCmdLineArgs::parsedArgs();
    KApplication app;
#endif

    Massif::MainWindow* window = new Massif::MainWindow;

// TODO: KF5
#if 0
    for (int i = 0; i < args->count(); ++i) {
        window->openFile(args->url(i));
    }
#endif

    window->show();
    return app.exec();
}
