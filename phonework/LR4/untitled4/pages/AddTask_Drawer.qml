import QtQuick
import QtQuick.Controls

Drawer {
    id: addTask_Drawer
    width: parent.width
    height: parent.height/2
    edge: Qt.BottomEdge
    background: Rectangle{
        anchors.fill: parent
        color: "#2C3E50"
    }
    Label {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 10
        text: "Добавить новую"
        font.pointSize: 15
        color: "white"
    }
    TextField {
        id: titelInput
        placeholderText: qsTr("Моя задача")
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 50
        width: parent.width/1.3
    }

    Item {
        width: titelInput.width
        height: 50
        anchors.horizontalCenter:parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 125

        TextField{
            id: dateInput
            height: parent.height/2
            width: parent.width/2.5
            anchors.left: parent.left
            placeholderText: "0000-00-00"
        }
        TextField{
            id: timeInput
            height: parent.height/2
            width: parent.width/3
            anchors.right: parent.right
            placeholderText: "00:00"
        }
    }

    RoundButton {
        id: submitButton
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 200
        text: "Вставить"
        width: 200
        background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: "#848685"
                    border.color: "#26282a"
                    border.width: 1
                    radius: 4
                }
        onClicked: {
        if(titelInput.text !== "" &&
            dateInput.text !== "" &&
            timeInput.text !== ""){
            myListModel.append({"titelText": titelInput.text,
                                "dateText": dateInput.text + " | " +
                                timeInput.text})
                titelInput.clear()
                dateInput.clear()
                timeInput.clear()
                addTaskDrawer.close()
            }
        }
    }
}
