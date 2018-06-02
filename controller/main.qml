import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    id: window
    visible: true
    width: 480
    height: 640
    title: qsTr("Hello World")

    DebugForm {
        id: debugForm
        anchors.fill: parent
    }
    TabForm {
        id: tabForm
        anchors.fill: parent
    }

    ControlForm {
        id: controlForm
        anchors.fill: parent
    }

    ConnectForm {
        id: connectForm
        anchors.fill: parent
    }


}
