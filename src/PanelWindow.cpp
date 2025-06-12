#include "PanelWindow.h"
#include "SettingsManager.h"
#include <QGuiApplication>
#include <QScreen>

static PanelWindow *s_instance = nullptr;

PanelWindow *PanelWindow::instance()
{
    if (!s_instance)
        s_instance = new PanelWindow;
    return s_instance;
}

PanelWindow::PanelWindow()
{
    // load our Panel.qml
    setResizeMode(QQuickView::SizeRootObjectToView);
    setSource(QUrl("qrc:/Panel.qml"));

    // always-on-top, frameless
    setFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setVisible(false);

    updateGeometry();
}

void PanelWindow::updateGeometry()
{
    auto &s = SettingsManager::instance();
    const QRect screen = QGuiApplication::primaryScreen()->geometry();
    int inset = s.property("inset").toInt();
    double share = s.property("share").toDouble();
    QString edge = s.property("edge").toString();

    QRect geo = screen;
    if (edge == "left" || edge == "right")
        geo.setWidth(int(screen.width() * share));
    else
        geo.setHeight(int(screen.height() * share));

    if (edge == "right")
        geo.moveLeft(screen.width() - geo.width());
    if (edge == "bottom")
        geo.moveTop(screen.height() - geo.height());

    geo.adjust(inset, inset, -inset, -inset);
    setGeometry(geo);
}

void PanelWindow::toggle()
{
    m_visible = !m_visible;
    setVisible(m_visible);
    if (m_visible)
        requestActivate();
}
