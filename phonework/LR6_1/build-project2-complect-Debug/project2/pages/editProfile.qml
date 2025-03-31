import QtQuick
import QtQuick.Controls

Page {
    title: qsTr("Edit Profile")
    Rectangle {
            anchors.fill: parent
            gradient: Gradient {
                GradientStop { position: 0.0; color: "#004ff9" }
                GradientStop { position: 1.0; color: "#000000" }
            }
        }

    Column {
        anchors.centerIn: parent
        spacing: 10
        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 20
            text: qsTr("Name")
            color: "#F85F73"
            font.bold: true
            font.underline: true
        }
        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 20
            text: qsTr("LastName")
            color: "#F85F73"
            font.bold: true
            font.underline: true
        }
        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("OK");
            font.pointSize: 16
        }
    }
}
