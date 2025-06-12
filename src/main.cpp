#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "PanelWindow.h"
#include "HotkeyHelper.h"
#include "SettingsManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Register singletons for QML
    qmlRegisterSingletonInstance("kgpt", 1, 0, "SettingsMgr", &SettingsManager::instance());

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl)
                     {
                         if (!obj && url == objUrl) std::exit(-1); }, Qt::QueuedConnection);
    engine.load(url);

    // Global hotkey wiring (Wayland‑safe via KGlobalAccel)
    HotkeyHelper hotkey(&app);
    QObject::connect(&hotkey, &HotkeyHelper::toggleRequested, []()
                     { PanelWindow::instance()->toggle(); });

    return app.exec();
}