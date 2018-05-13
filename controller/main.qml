import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 480
    height: 640
    title: qsTr("Hello World")

    ConnectForm {
        id: connectForm
        width: 480
        height: 640
        anchors.fill: parent
    }

    DebugForm {
        id: debugForm
        anchors.fill: parent
    }
    TabForm {
        id: tabForm
        anchors.fill: parent
    }
}
