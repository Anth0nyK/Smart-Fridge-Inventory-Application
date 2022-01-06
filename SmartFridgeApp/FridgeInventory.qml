import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3


Page {
    property string userID
    property string userImage

    width: 780
    height: 585

    Rectangle {
        id: rectangle1

        anchors.fill: parent

        color: "#ffffff"
        anchors.rightMargin: -1
        anchors.leftMargin: 1
        anchors.topMargin: 0
        //anchors.bottomMargin: -54

        Rectangle {
            id: rectangle
            x: 0
            y: 0
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            //width: 781
            height: 50
            color: "#eeeeee"
            border.color: "#bababa"
        }

        GridView {
            id: gridView
            y: 68
            anchors.leftMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right
            contentWidth: 0
            anchors.rightMargin: 20

            height: 450
            cellWidth: 185
            cellHeight: 200
            delegate: ItemDelegate {
                onClicked: {
                        thestackView.clear()
                        //thestackView.push("qrc:/chat2.qml", { chatroomHeader: model.GPName, topicID: model.TopicID, senderID: currentUserID})
                }
                x: 5
                width: 150
                height: 200
                Column {


                    Rectangle {
                        width: 150
                        height: 150
                        color: colorCode
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Text {
                        x: 5
                        text: name
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                }
            }
            model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }

        }







/*
            Button {
                id: backbutton
                x: 8
                y: 8
                text: qsTr("back")
                onClicked: {
                    thestackView.pop()
                }
            }


            Button {
                id: button
                x: 76
                y: 101
                text: qsTr("test")
                onClicked:{
                    thestackView.push("qrc:/EditProfile.qml", { userID: "currentUserID222"})
                }
            }

*/

    }



}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}D{i:2}D{i:3}D{i:1}
}
##^##*/
