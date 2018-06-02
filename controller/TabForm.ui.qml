import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    width: 400
    height: 400
    TabBar {
        x: 0
        y: 0
        width: parent.width
        height: 40
        TabButton {
            id: connect
            text: qsTr("connect")
        }

        TabButton {
            id: debug
            x: 138
            y: 0
            text: qsTr("debug")
        }

        TabButton {
            id: control
            x: 268
            y: 0
            text: qsTr("control")
        }

        Connections {
            target: connect
            onClicked: {
                connectForm.visible = true
                debugForm.visible = false
                controlForm.visible = false
            }
        }

        Connections {
            target: control
            onClicked: {
                connectForm.visible = false
                debugForm.visible = false
                controlForm.visible = true
            }
        }

        Connections {
            target: debug
            onClicked: {
                connectForm.visible = false
                debugForm.visible = true
                controlForm.visible = false
            }
        }
    }
}
