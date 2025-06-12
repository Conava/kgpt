import QtQuick
import QtQuick.Controls
import org.kde.kirigami 2.20 as Kirigami
import kgpt 1.0

Kirigami.Dialog {
    id: dlg
    modal: true
    title: "Settings"

    Column {
        spacing: Kirigami.Units.smallSpacing

        ComboBox {
            model: ["ChatGPT-Web"]
            currentIndex: 0
            onCurrentTextChanged: SettingsMgr.aiBackend = currentText
        }
        ComboBox {
            id: edgeBox
            model: ["left","right","top","bottom"]
            currentIndex: model.indexOf(SettingsMgr.edge)
            onActivated: SettingsMgr.edge = model[index]
        }
        Slider {
            from: 0.2; to: 0.8; value: SettingsMgr.share
            onMoved: SettingsMgr.share = value
            textOverlaid: true
        }
        CheckBox {
            text: "Rounded corners"
            checked: SettingsMgr.rounded
            onToggled: SettingsMgr.rounded = checked
        }
        SpinBox {
            from: 0; to: 50; value: SettingsMgr.inset
            onValueModified: SettingsMgr.inset = value
            suffix: " px inset"
        }
        TextField {
            text: SettingsMgr.shortcut
            placeholderText: "Global shortcut (e.g. Meta+C)"
            onAccepted: SettingsMgr.shortcut = text
        }
        Button { text: "Save"; onClicked: { SettingsMgr.save(); dlg.close(); } }
    }
}