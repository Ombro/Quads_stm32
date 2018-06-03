import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtGraphicalEffects.private 1.0

Item {
    id: item1
    width: 480
    height: 640
    property alias left_hand: left_hand
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
                y: 125
                width: 240
                height: 240
                color: "#ffffff"
                anchors.left: parent.left
                anchors.leftMargin: 0
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
                    drag.minimumY: parent.height / 2 - left_button_core.height / 2 - Math.sqrt(
                                       Math.pow(left_button_shell.width / 2, 2)
                                       - Math.pow(Math.abs(
                                                      left_button_core.x + left_button_core.width
                                                      / 2 - parent.width / 2), 2))
                    drag.maximumY: parent.height / 2 - left_button_core.height / 2 + Math.sqrt(
                                       Math.pow(left_button_shell.width / 2, 2)
                                       - Math.pow(Math.abs(
                                                      left_button_core.x + left_button_core.width
                                                      / 2 - parent.width / 2), 2))
                }

                Connections {
                    target: left_mouse_area
                    onPositionChanged: {
                        TCP.x_dir = ((left_button_core.x - 80) * 25 / 80).toLocaleString()
                        TCP.y_dir = (-(left_button_core.y - 80) * 25 / 80).toLocaleString()
                        TCP.send_control_parm()
                    }

                    onReleased: {
                        left_button_core.x = 80
                        left_button_core.y = 80
                        TCP.x_dir = 0
                        TCP.y_dir = 0
                        TCP.send_control_parm()
                    }
                }

                RoundButton {
                    id: left_button_shell
                    x: 29
                    y: 37
                    width: 160
                    height: 160
                    text: "+"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    highlighted: false
                    checkable: false
                    checked: false
                    enabled: false
                }

                Label {
                    id: title
                    x: 115
                    y: -title.height
                    text: qsTr("Controller")
                    anchors.horizontalCenterOffset: 131
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.underline: false
                    font.bold: true
                    font.pointSize: 30
                    horizontalAlignment: Text.AlignHCenter
                }

                RoundButton {
                    id: left_button_core
                    x: 80
                    y: 80
                    width: 80
                    height: 80
                    text: "+"
                    highlighted: true
                    enabled: false
                    wheelEnabled: false
                }
            }

            Rectangle {
                id: right_control
                x: left_joystick.width
                y: left_joystick.y
                width: parent.width - left_joystick.width
                height: left_joystick.height
                color: "#ffffff"

                Slider {
                    id: slider_throttle
                    value: 0.5
                    x: 160
                    y: 0
                    width: 40
                    height: 270
                    stepSize: 0.01
                    anchors.right: parent.right
                    anchors.rightMargin: 30
                    orientation: Qt.Vertical
                    font.pointSize: 6

                    Connections {
                        target: slider_throttle
                        onValueChanged: {
                            throttle_value.text = slider_throttle.value.toLocaleString()
                            TCP.throttle = slider_throttle.value.toLocaleString(
                                        )
                            TCP.throttle = slider_throttle.value.toLocaleString(
                                        )
                            TCP.send_control_parm()
                        }
                    }

                    Label {
                        id: throttle
                        x: -197
                        y: 8
                        text: qsTr("throttle:")
                        font.bold: true
                        anchors.right: parent.right
                        anchors.rightMargin: 80
                        horizontalAlignment: Text.AlignLeft
                        font.pointSize: 15

                        Label {
                            id: throttle_value
                            x: 123
                            text: qsTr("value")
                            anchors.top: parent.top
                            anchors.topMargin: 20
                            anchors.horizontalCenterOffset: 0
                            anchors.horizontalCenter: parent.horizontalCenter
                            font.pointSize: 15
                        }
                    }

                    SwitchDelegate {
                        id: power
                        x: -140
                        y: 220
                        text: qsTr("OFF")
                        spacing: 12
                        font.pointSize: 20
                        anchors.right: parent.right
                        anchors.rightMargin: 100

                        Button {
                            id: right_hand
                            x: 54
                            width: 60
                            height: 60
                            text: qsTr(">")
                            anchors.top: parent.top
                            anchors.topMargin: -150
                            anchors.horizontalCenterOffset: 60
                            anchors.horizontalCenter: parent.horizontalCenter
                            font.bold: true
                            font.pointSize: 40
                        }

                        Connections {
                            target: right_hand
                            onClicked: {
                                TCP.turn = 1
                                TCP.send_control_parm()
                            }
                            onReleased: {
                                TCP.turn = 0
                            }
                        }

                        Button {
                            id: left_hand
                            x: -32
                            width: 60
                            height: 60
                            text: qsTr("<")
                            anchors.top: parent.top
                            anchors.topMargin: -150
                            anchors.horizontalCenterOffset: -60
                            anchors.horizontalCenter: parent.horizontalCenter
                            font.bold: true
                            font.pointSize: 40
                        }

                        Connections {
                            target: left_hand
                            onClicked: {
                                TCP.turn = -1
                                TCP.send_control_parm()
                            }
                            onReleased: {
                                TCP.turn = 0
                            }
                        }

                        Button {
                            id: homing
                            x: 11
                            y: -68
                            width: 95
                            height: 50
                            text: qsTr("HOME")
                            font.pointSize: 20
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.bottom: parent.bottom
                            anchors.bottomMargin: 70
                        }
                    }
                }
            }
        }
    }
}
