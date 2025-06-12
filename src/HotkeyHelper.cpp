#include "HotkeyHelper.h"
#include "SettingsManager.h"

#ifdef Q_OS_LINUX
#include <KGlobalAccel>
#include <QAction>
#else
#include <QHotkey>
#endif

HotkeyHelper::HotkeyHelper(QObject *parent)
    : QObject(parent)
{
    // read the user’s shortcut string
    QKeySequence seq(SettingsManager::instance().property("shortcut").toString());

#ifdef Q_OS_LINUX
    // KDE Plasma global shortcut
    auto *act = new QAction(this);
    act->setObjectName("kgpt_toggle");
    act->setText("Toggle KGPT panel");
    QList<QKeySequence> seqs;
    seqs << seq;
    KGlobalAccel::self()->setShortcut(act, seqs);
    connect(act, &QAction::triggered, this, &HotkeyHelper::toggleRequested);
#else
    // Fallback QHotkey on X11
    auto *hk = new QHotkey(seq, true, this);
    connect(hk, &QHotkey::activated, this, &HotkeyHelper::toggleRequested);
#endif
}
