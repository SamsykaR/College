import QtQuick
import QtQuick.Controls

Window {
    width: 360
    height: 720
    visible: true
    title: qsTr("Task-Master")

    StackView{
        id: contentFrame
        anchors.fill: parent
        initialItem: "./pages/Load_Page.qml"
    }
    Component.onCompleted: {
        contentFrame.replace("./pages/Main_Page.qml")
    }
}
