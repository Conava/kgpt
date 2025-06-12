import QtQuick
import QtQuick.Controls
import QtWebEngine
import org.kde.kirigami 2.20 as Kirigami
import kgpt 1.0

Rectangle {
    id: panel
    color: Kirigami.Theme.backgroundColor
    radius: SettingsMgr.rounded ? 12 : 0

    WebEngineView {
        anchors.fill: parent
        url: "https://chat.openai.com/chat"
    }
}