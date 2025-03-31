import QtQuick
import QtQuick.Controls

Window {
    width: 320
    height: 240
    visible: true
    color: "#736d77"
    title: qsTr("Lesson_2")

    TextInput {
           id: input1
           x: 8; y: 8
           width: 96; height: 20
           color: "#000000"
           focus: true
           text: "0"
           font.pointSize: 10
           font.underline: true


    }

    TextInput {
           id: input2
           x: 8; y: 36
           width: 96; height: 20
           text: "0"
           font.pointSize: 10
           font.underline: true
    }

    Item{
        anchors.centerIn: parent
        height: parent.height/3
        anchors.verticalCenterOffset: 45
        anchors.horizontalCenterOffset: 38
        width: parent.width/3
        Button {
            id: sumBut
            width: 70
            height: 29
            anchors.top: parent.top
            anchors.topMargin: -43
            anchors.verticalCenterOffset: -43
            anchors.horizontalCenterOffset: 6
            anchors.centerIn: parent
            background: Rectangle {color: "#d6d6d6"}
            //anchors.margins: 100
            text: qsTr("Сумма")

            onClicked: {
                buttonClicks.text = parseInt(input2.text) + parseInt(input1.text);
            }
        }

        Button {
            id: minBut
            width: 70
            height: 23
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -6
            anchors.verticalCenterOffset: 6
            anchors.horizontalCenterOffset: 81
            anchors.centerIn: parent
            background: Rectangle {color: "#d6d6d6"}
            //anchors.margins: 100
            text: qsTr("Разность")

            onClicked: {
                buttonClicks.text = parseInt(input1.text) - parseInt(input2.text);
            }
        }

        Button {
            id: mulBut
            width: 91
            height: 27
            anchors.right: parent.right
            anchors.rightMargin: 47
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: -53
            anchors.centerIn: parent
            background: Rectangle {color: "#d6d6d6"}
            //anchors.margins: 100
            text: qsTr("Произведение")

            onClicked: {
                buttonClicks.text = parseInt(input2.text) * parseInt(input1.text);
            }
        }

        Button {
            id: delBut
            width: 67
            height: 31
            anchors.left: parent.left
            anchors.leftMargin: -9
            anchors.verticalCenterOffset: 47
            anchors.horizontalCenterOffset: 2
            anchors.centerIn: parent
            background: Rectangle {color: "#d6d6d6"}
           //anchors.margins: 100
            text: qsTr("Деление")

            onClicked: {
                buttonClicks.text = parseFloat(input1.text) / parseFloat(input2.text);
            }
        }
    }

    Text {
        id: buttonClicks
        y: 78
        width: 46
        height: 22
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: sumBut.bottom
        anchors.topMargin: 10
        font.pointSize: 12
        font.bold: true
        anchors.horizontalCenterOffset: -129
        text: qsTr("0")
    }
}
