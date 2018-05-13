import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    width: 480
    height: 640
    property alias d_core: d_core
    //visible: false
    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.topMargin: 40
        anchors.fill: parent

        Rectangle {
            id: rectangle1
            x: 40
            width: 350
            height: 500
            color: "#ffffff"
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                id: pid_x
                x: 90
                y: 452
                text: qsTr("X")
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.horizontalCenterOffset: -80
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Button {
                id: pid_y
                x: 239
                y: 519
                text: qsTr("Y")
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.horizontalCenterOffset: 80
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Item {
                id: item1
                x: 40
                y: 40
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 120
                anchors.top: parent.top
                anchors.topMargin: 0

                Item {
                    id: item_sehll
                    y: 0
                    height: 212
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0

                    Label {
                        id: title
                        x: 92
                        y: 0
                        text: qsTr("PID PARM")
                        anchors.horizontalCenter: parent.horizontalCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        anchors.top: parent.top
                        anchors.topMargin: 0
                        font.pointSize: 26
                    }

                    Label {
                        id: tilte_shell
                        x: 138
                        y: 50
                        text: qsTr("SHELL")
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.bold: true
                        anchors.top: parent.top
                        anchors.topMargin: 60
                        font.pointSize: 20
                    }

                    Label {
                        id: i_shell
                        y: 143
                        width: 12
                        height: 23
                        text: qsTr("I:")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 20
                        font.pointSize: 14
                    }

                    Label {
                        id: p_shell
                        y: 97
                        text: qsTr("P:")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 80
                        font.pointSize: 14
                    }

                    Slider {
                        id: slider_p_shell
                        x: 30
                        y: 101
                        width: 260
                        height: 40
                        anchors.horizontalCenter: parent.horizontalCenter
                        value: 0.5
                        onValueChanged: data_p_shell.text = value
                    }

                    Slider {
                        id: slider_i_shell
                        x: 23
                        y: 161
                        width: 260
                        height: 40
                        anchors.horizontalCenter: parent.horizontalCenter
                        value: 0.5
                        onValueChanged: data_i_shell.text = value
                    }

                    Label {
                        id: data_p_shell
                        x: 323
                        y: 111
                        width: 30
                        height: 19
                        text: qsTr("0")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        font.bold: true
                        font.pointSize: 14
                    }

                    Label {
                        id: data_i_shell
                        x: 323
                        y: 171
                        width: 30
                        height: 19
                        text: qsTr("0")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        font.pointSize: 14
                        font.bold: true
                    }
                }

                Item {
                    id: item_core
                    y: 218
                    height: 242
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0

                    Label {
                        id: title_core
                        x: 146
                        text: qsTr("CORE")
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.bold: true
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        font.pointSize: 20
                    }

                    Label {
                        id: i_core
                        y: 87
                        text: qsTr("I:")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 90
                        font.pointSize: 14
                    }

                    Label {
                        id: p_core
                        y: 27
                        text: qsTr("P:")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 150
                        font.pointSize: 14
                    }

                    Label {
                        id: d_core
                        y: 147
                        text: qsTr("D:")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        font.bold: true
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 30
                        font.pointSize: 14
                    }

                    Slider {
                        id: slider_p_core
                        x: 30
                        y: 61
                        width: 260
                        height: 40
                        anchors.horizontalCenter: parent.horizontalCenter
                        value: 0.5
                        anchors.horizontalCenterOffset: 0
                        onValueChanged: data_p_core.text = value
                    }

                    Slider {
                        id: slider_i_core
                        x: 38
                        y: 121
                        width: 260
                        height: 40
                        anchors.horizontalCenter: parent.horizontalCenter
                        value: 0.5
                        anchors.horizontalCenterOffset: 0
                        onValueChanged: data_i_core.text = value
                    }

                    Slider {
                        id: slider_d_core
                        x: 32
                        y: 181
                        width: 260
                        height: 40
                        anchors.horizontalCenter: parent.horizontalCenter
                        value: 0.5
                        anchors.horizontalCenterOffset: 0
                        onValueChanged: data_d_core.text = value
                    }

                    Label {
                        id: data_p_core
                        x: 328
                        y: 71
                        width: 30
                        height: 19
                        text: qsTr("0")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        font.pointSize: 14
                        font.bold: true
                    }

                    Label {
                        id: data_i_core
                        x: 338
                        y: 131
                        width: 30
                        height: 19
                        text: qsTr("0")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        font.pointSize: 14
                        font.bold: true
                    }

                    Label {
                        id: data_d_core
                        x: 338
                        y: 189
                        width: 30
                        height: 19
                        text: qsTr("0")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        font.pointSize: 14
                        font.bold: true
                    }
                }
            }
        }
    }
}
