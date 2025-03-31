import QtQuick 2.15
import QtQuick.Controls 2.12
Item {
    width: parent.width
    height: parent.height
    Rectangle{
        id: bgRec
        anchors.fill: parent
        color: "#2C3E50"
        BusyIndicator {
            id: busyIndicator
            anchors.centerIn: parent
        }
    }
}
