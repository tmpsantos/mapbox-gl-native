#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMapboxGL>

#include <QOpenGLWidget>
#include <QScopedPointer>
#include <QtGlobal>

class MapWindow : public QOpenGLWidget
{
    Q_OBJECT

public:
    MapWindow(const QMapboxGLSettings &);
    ~MapWindow();

protected slots:
    void staticRenderFinished(QString);

private:
    // Q{,Open}GLWidget implementation.
    void initializeGL() final;
    void paintGL() final;

    QMapboxGLSettings m_settings;
    QScopedPointer<QMapboxGL> m_map;
};

#endif
