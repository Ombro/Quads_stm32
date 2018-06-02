import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick 2.7

Item {
    id: item1
    width: 480
    height: 640
    property alias left_button_core: left_button_core
    visible: false
    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.top: parent.top
        anchors.topMargin: 40
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        Rectangle {
            id: rectangle1
            color: "#ffffff"
            anchors.bottomMargin: 130
            anchors.topMargin: 130
            anchors.fill: parent

            Rectangle {
                id: left_joystick
                x: 8
                y: 125
                width: 200
                height: 200
                color: "#ffffff"
                anchors.horizontalCenterOffset: -132
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenterOffset: 0
                anchors.verticalCenter: parent.verticalCenter

                MouseArea {
                    id: left_mouse_area
                    anchors.fill: parent
                    enabled: true
                    drag.target: left_button_core
                    drag.axis: Drag.XandYAxis
                    drag.minimumX: 0
                    drag.maximumX: parent.width - left_button_core.width
                    drag.minimumY: left_button_shell.height / 2 - Math.sqrt(
                                       Math.pow(left_button_shell.width / 2, 2)
                                       - Math.pow(Math.abs(
                                                      left_button_core.x + left_button_core.width
                                                      / 2 - parent.width / 2), 2))
                    drag.maximumY: left_button_shell.height / 2 + Math.sqrt(
                                       Math.pow(left_button_shell.width / 2, 2)
                                       - Math.pow(Math.abs(
                                                      left_button_core.x + left_button_core.width
                                                      / 2 - parent.width / 2), 2))
                }

                Connections {
                    target: left_mouse_area
                    onReleased: {
                        left_button_core.x = 75
                        left_button_core.y = 75
                    }
                }

                RoundButton {
                    id: left_button_shell
                    x: 25
                    y: 25
                    width: 150
                    height: 150
                    text: "+"
                    highlighted: false
                    checkable: false
                    checked: false
                    enabled: false
                }

                RoundButton {
                    id: left_button_core
                    x: 75
                    y: 75
                    width: 50
                    height: 50
                    text: "+"
                    highlighted: true
                    enabled: false
                    wheelEnabled: false
                }
            }

            Rectangle {
                id: right_joystick
                x: 272
                y: 115
                width: 200
                height: 200
                color: "#ffffff"
                anchors.horizontalCenterOffset: 132
                anchors.horizontalCenter: parent.horizontalCenter
                MouseArea {
                    id: right_mouse_area
                    drag.maximumY: right_button_shell.height / 2 + Math.sqrt(
                                       Math.pow(right_button_shell.width / 2, 2)
                                       - Math.pow(Math.abs(
                                                      right_button_core.x + right_button_core.width
                                                      / 2 - parent.width / 2), 2))
                    anchors.fill: parent
                    drag.axis: Drag.XandYAxis
                    enabled: true
                    drag.minimumY: right_button_shell.height / 2 - Math.sqrt(
                                       Math.pow(right_button_shell.width / 2, 2)
                                       - Math.pow(Math.abs(
                                                      right_button_core.x + right_button_core.width
                                                      / 2 - parent.width / 2), 2))
                    drag.minimumX: 0
                    drag.maximumX: parent.width - right_button_core.width
                    drag.target: right_button_core
                }

                Connections {
                    target: right_mouse_area
                    onReleased: {
                        right_button_core.x = 75
                        right_button_core.y = 75
                    }
                }

                RoundButton {
                    id: right_button_shell
                    x: 25
                    y: 25
                    width: 150
                    height: 150
                    text: "+"
                    enabled: false
                }

                RoundButton {
                    id: right_button_core
                    x: 75
                    y: 75
                    width: 50
                    height: 50
                    text: "+"
                    highlighted: true
                    enabled: false
                    wheelEnabled: false
                }
                anchors.verticalCenterOffset: 0
                anchors.verticalCenter: parent.verticalCenter
            }

            Slider {
                id: accelerograph
                x: 56
                y: left_joystick.y + 204
                width: 326
                height: 40
                anchors.horizontalCenterOffset: 44
                anchors.horizontalCenter: parent.horizontalCenter
                value: 0.5
            }

            Button {
                id: power
                x: 190
                y: 105
                width: 70
                height: 40

                text: qsTr("OFF")
                anchors.verticalCenterOffset: -40
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Button {
                id: homing
                x: 197
                y: 151
                width: 70
                height: 40
                text: qsTr("HOME")
                anchors.verticalCenterOffset: 40
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Label {
                id: label_acce
                x: 15
                y: left_joystick.y + 200
                text: qsTr("acce:")
                anchors.horizontalCenterOffset: -175
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
                font.pointSize: 24
            }

            Label {
                id: title
                x: 115
                y: left_joystick.y - 50
                text: qsTr("Controller")
                anchors.horizontalCenter: parent.horizontalCenter
                font.underline: false
                font.bold: true
                font.pointSize: 30
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }
}
