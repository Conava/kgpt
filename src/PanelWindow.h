#pragma once

#include <QQuickView>

class PanelWindow : public QQuickView
{
    Q_OBJECT
public:
    static PanelWindow *instance();
    void toggle();

private:
    PanelWindow();
    void updateGeometry();
    bool m_visible = false;
};
