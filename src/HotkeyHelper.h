#pragma once

#include <QObject>
#include <QKeySequence>
#include "SettingsManager.h"

#ifdef Q_OS_LINUX
#include <KGlobalAccel>
#include <QAction>
#else
#include <QHotkey>
#endif

class HotkeyHelper : public QObject
{
    Q_OBJECT
public:
    explicit HotkeyHelper(QObject *parent = nullptr);

signals:
    void toggleRequested();
};
