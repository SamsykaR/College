import QtQuick
import QtQuick.Controls

Page {
    title: qsTr("Home")
    Rectangle {
            anchors.fill: parent
            gradient: Gradient {
                GradientStop { position: 0.0; color: "#004ff9" }
                GradientStop { position: 1.0; color: "#000000" }
            }
        }

    Label {
        anchors.centerIn: parent
        font.pointSize: 20
        color: "#F85F73"
        font.bold: true
        text: qsTr("Home Screen")
    }
}
