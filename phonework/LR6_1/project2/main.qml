import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Lesson_3")


    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        Rectangle {
                anchors.fill: parent
                color: "#DBE2EF"
            }

            ToolButton {
                id: toolButton
                text: stackView.depth > 1 ? "<" : "v"
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                onClicked: {
                    if (stackView.depth > 1) {
                        stackView.pop()
                    } else {
                        drawer.open()
                    }
                }
            }

            Label {
                text: stackView.currentItem.title
                anchors.centerIn: parent
            }
        }

    Drawer {
        id: drawer
        width: root.width
        height: root.height

        Column {
            anchors.fill: parent


            ItemDelegate {
                Text {
                    text: qsTr("Profile")
                    wrapMode: Text.WrapAnywhere
                    font.family: "Verdana"
                    font.bold: true
                    font.pixelSize: 18
                    leftPadding: 20
                    font.underline: true
                }
                width: parent.width
                onClicked: {
                    stackView.push("./pages/profile.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                Text {
                    text: qsTr("About")
                    wrapMode: Text.WrapAnywhere
                    font.family: "Verdana"
                    font.bold: true
                    font.pixelSize: 18
                    leftPadding: 20
                    font.underline: true
                }
                width: parent.width
                onClicked: {
                    stackView.push("./pages/about.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: "./pages/home.qml"
    }
}
