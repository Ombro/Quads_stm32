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

        Connections {
            target: connect
            onClicked: {
                connectForm.visible = true
                debugForm.visible = false
            }
        }

        TabButton {
            id: control
            text: qsTr("control")
        }

        Connections {
            target: control
            onClicked: {
                connectForm.visible = false
                debugForm.visible = false
            }
        }

        TabButton {
            id: debug
            text: qsTr("debug")
        }

        Connections {
            target: debug
            onClicked: {
                connectForm.visible = false
                debugForm.visible = true
            }
        }
    }
}
