#pragma once
#include <QObject>
#include <QSettings>

class SettingsManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString aiBackend MEMBER m_aiBackend NOTIFY changed)
    Q_PROPERTY(QString edge MEMBER m_edge NOTIFY changed)  // "left"|"right"|"top"|"bottom"
    Q_PROPERTY(double share MEMBER m_share NOTIFY changed) // e.g. 0.4
    Q_PROPERTY(bool rounded MEMBER m_rounded NOTIFY changed)
    Q_PROPERTY(int inset MEMBER m_inset NOTIFY changed)
    Q_PROPERTY(QString shortcut MEMBER m_shortcut NOTIFY changed) // "Meta+C"
public:
    static SettingsManager &instance()
    {
        static SettingsManager s;
        return s;
    }
    Q_INVOKABLE void save();
signals:
    void changed();

private:
    SettingsManager();
    void load();
    QSettings m_cfg;
    QString m_aiBackend{"ChatGPT-Web"};
    QString m_edge{"right"};
    double m_share{0.4};
    bool m_rounded{true};
    int m_inset{0};
    QString m_shortcut{"Meta+C"};
};