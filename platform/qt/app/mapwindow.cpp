#include "mapwindow.hpp"

#include <QApplication>
#include <QDebug>
#include <QIcon>
#include <QString>

MapWindow::MapWindow(const QMapboxGLSettings &settings)
    : m_settings(settings)
{
    setWindowIcon(QIcon(":icon.png"));
}

MapWindow::~MapWindow()
{
    // Make sure we have a valid context so we
    // can delete the QMapboxGL.
    makeCurrent();
}

void MapWindow::initializeGL()
{
    m_map.reset(new QMapboxGL(nullptr, m_settings, size(), devicePixelRatioF()));

    connect(m_map.data(), SIGNAL(needsRendering()), this, SLOT(update()));
    connect(m_map.data(), SIGNAL(staticRenderFinished(QString)), this, SLOT(staticRenderFinished(QString)));

    // Set default location to Helsinki.
    m_map->setCoordinateZoom(QMapbox::Coordinate(60.170448, 24.942046), 14);
    m_map->setStyleUrl(QMapbox::defaultStyles()[0].first);
    m_map->startStaticRender();

}

void MapWindow::paintGL()
{
    m_map->setFramebufferObject(defaultFramebufferObject(), size() * devicePixelRatioF());
    m_map->render();
}

void MapWindow::staticRenderFinished(QString msg)
{
    qDebug() << "Finished:" << msg;
}
