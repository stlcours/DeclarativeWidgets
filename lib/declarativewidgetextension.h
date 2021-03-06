/*
  declarativewidgetextension.h

  This file is part of DeclarativeWidgets, library and tools for creating QtWidget UIs with QML.

  Copyright (C) 2013-2017 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
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

#ifndef DECLARATIVEWIDGETEXTENSION_H
#define DECLARATIVEWIDGETEXTENSION_H

#include "declarativewidgets_export.h"
#include "declarativeobjectextension.h"

#include <QRect>

class WidgetContainerInterface;

QT_BEGIN_NAMESPACE
class QAction;
class QLayout;
class QWidget;
QT_END_NAMESPACE

class DECLARATIVEWIDGETS_EXPORT DeclarativeWidgetExtension : public DeclarativeObjectExtension
{
  Q_OBJECT

  // repeat property declarations, qmlRegisterExtendedType doesn't see the ones from base class
  Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)

  Q_PROPERTY(int x READ x WRITE setX NOTIFY posChanged)
  Q_PROPERTY(int y READ y WRITE setY NOTIFY posChanged)
  Q_PROPERTY(int width READ width WRITE setWidth NOTIFY sizeChanged)
  Q_PROPERTY(int height READ height WRITE setHeight NOTIFY sizeChanged)
  Q_PROPERTY(QRect geometry READ geometry WRITE setGeometry NOTIFY geometryChanged)
  Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)

  Q_CLASSINFO("DefaultProperty", "data")

  public:
    explicit DeclarativeWidgetExtension(QObject *parent = 0);

    QWidget *extendedWidget() const;

    int x() const;
    void setX(int value);

    int y() const;
    void setY(int value);

    int width() const;
    void setWidth(int value);

    int height() const;
    void setHeight(int value);

    QRect geometry() const;
    void setGeometry(const QRect &rect);

    bool isVisible() const;
    void setVisible(bool visible);

    bool eventFilter(QObject *watched, QEvent *event);

  protected:
    explicit DeclarativeWidgetExtension(WidgetContainerInterface *widgetContainer, QObject *parent = 0);

  Q_SIGNALS:
    void posChanged();
    void sizeChanged();
    void geometryChanged();
    void visibleChanged(bool visible);
};

#endif // DECLARATIVEWIDGETEXTENSION_H
