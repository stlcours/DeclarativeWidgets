/*
  main.cpp

  This file is part of DeclarativeWidgets, library and tools for creating QtWidget UIs with QML.

  Copyright (C) 2012-2017 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Tobias Koenig <tobias.koenig@kdab.com>
  Author: Kevin Krammer <kevin.krammer@kdab.com>

  Licensees holding valid commercial KDAB DeclarativeWidgets licenses may use this file in
  accordance with DeclarativeWidgets Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "declarativewidgetsdocument.h"

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QQmlEngine>
#include <QWidget>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  const QStringList arguments = app.arguments();
  if (arguments.count() < 2) {
      qWarning("Missing QML file argument. Usage: declarativewidgets <qmlfile>");
      return -1;
  }

  const QFileInfo qmlFile(QDir::current(), arguments[1]);
  const QUrl documentUrl = QUrl::fromLocalFile(qmlFile.absoluteFilePath());

  DeclarativeWidgetsDocument document(documentUrl);
  QObject::connect(document.engine(), SIGNAL(quit()), &app, SLOT(quit()));

  QWidget *widget = document.create<QWidget>();
  if (widget) {
    widget->show();
    return app.exec();
  }

  return -1;
}
