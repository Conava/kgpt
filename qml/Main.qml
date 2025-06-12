import QtQuick 2.15
import QtQuick.Controls 2.15
import org.kde.kirigami 2.20 as Kirigami
import kgpt 1.0

Kirigami.ApplicationWindow {
    id: root
    visible: false           // controlled by C++
    flags: Qt.Dialog         // <-- plural property
}
