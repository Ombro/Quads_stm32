import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    id: item2
    width: 480
    height: 640

    Item {
        id: item1
        anchors.topMargin: 40
        anchors.fill: parent

        Rectangle {
            id: rectangle
            color: "#ffffff"
            anchors.topMargin: 0
            anchors.fill: parent

            Rectangle {
                id: rectangle1
                x: 139
                y: 56
                width: 300
                height: 500
                color: "#ffffff"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                Label {
                    id: label_title
                    x: 143
                    y: 8
                    width: 301
                    height: 37
                    text: qsTr("WIFI CONNECTING")
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.bold: true
                    font.pointSize: 22
                    textFormat: Text.AutoText
                    verticalAlignment: Text.AlignTop
                    horizontalAlignment: Text.AlignHCenter
                }

                Label {
                    id: label_state
                    x: 50
                    y: 62
                    text: TCP.Connect_State
                    font.bold: true
                    anchors.verticalCenterOffset: 60
                    anchors.horizontalCenterOffset: 0
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 20
                    anchors.horizontalCenter: parent.horizontalCenter
                }

//                Connections {
//                    target: label_state
//                    TCP.onConnected: {
//                        label_state.text = qsTr("connected!!!")
//                    }
//                    TCP.onHostFound: {
//                        label_state.text = qsTr("connecting...")
//                    }
//                }

                Label {
                    id: label_port
                    x: -65
                    y: 200
                    text: qsTr("PORT:")
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 18
                    anchors.horizontalCenterOffset: -112
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Label {
                    id: label_ip
                    x: 64
                    y: 110
                    width: 75
                    text: qsTr("IP:")
                    anchors.horizontalCenterOffset: -113
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.bold: true
                    horizontalAlignment: Text.AlignRight
                    font.pointSize: 18
                }

                Button {
                    id: button_connect
                    x: -80
                    y: 368
                    text: qsTr("Connect")
                    anchors.horizontalCenterOffset: -80
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Connections {
                    target: button_connect
                    onClicked: {
                        TCP.connecting(TCP.Address, TCP.Port)
                    }
                }

                Button {
                    id: button_disconnect
                    x: 167
                    y: 368
                    text: qsTr("Disconnect")
                    anchors.horizontalCenterOffset: 80
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Connections {
                    target: button_disconnect
                    onClicked: {
                        TCP.disconnect()
                    }
                }

                TextField {
                    id: text_address
                    x: 110
                    y: 105
                    width: 182
                    height: 40
                    font.pointSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    color: "white"
                    text: qsTr("192.168.4.1")
                    placeholderText: qsTr("")
                    selectByMouse: true
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        color: "#333"
                        radius: 5
                        border.color: "gray"
                        border.width: 2
                    }
                }

                Connections {
                    target: text_address
                    onEditingFinished: {
                        TCP.Address = text_address.text
                    }
                }

                TextField {
                    id: text_port
                    x: 110
                    y: 197
                    width: 182
                    height: 36
                    text: qsTr("6666")
                    font.pointSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    color: "white"
                    selectByMouse: true
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        color: "#333"
                        radius: 5
                        border.color: "gray"
                        border.width: 2
                    }
                }

                Connections {
                    target: text_port
                    onEditingFinished: {
                        TCP.Port = text_port.text
                    }
                }
            }
        }
    }
}
