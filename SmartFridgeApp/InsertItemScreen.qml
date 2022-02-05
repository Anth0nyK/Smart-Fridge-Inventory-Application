import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import inventorymodel 1.0

Page {
    property string userID
    property string currentfridgeID

    width: 780
    height: 585

    InsertItemInfoScreen {
        id: theInsertItemInfoScreen
    }


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
            anchors.topMargin: 0
            anchors.leftMargin: 0
            anchors.left: parent.left
            anchors.right: parent.right
            //width: 781
            height: 75
            color: "#eeeeee"
            border.color: "#bababa"

            Text {
                id: text1
                x: 25
                y: 21
                text: qsTr("Fridge > Open door > Unlocked > Insert item")
                font.pixelSize: 25
            }

            Text {
                id: text2
                x: 25
                y: 82
                text: qsTr("What did you put in?")
                font.pixelSize: 22
                font.bold: true
            }
        }

        Button {
            id: backbutton
            x: 726
            y: 81
            text: qsTr("Back")
            font.pointSize: 13
            font.bold: true
            onClicked: {
                thestackView.pop()
                theinventorymodel.updateinventoryModel()
                theinventorymodel2.updateinventoryModel()
            }
        }

        GridView {
            id: gridView
            y: 122
            anchors.leftMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right
            contentWidth: 0
            anchors.rightMargin: 20
            clip: true
            height: 410
            cellWidth: 185
            cellHeight: 200
            delegate: ItemDelegate {
                onClicked: {
                        //console.info("model.itemID = " + model.itemID)
                        thestackView.push(theInsertItemInfoScreen, {itemID: model.itemID, itemPic: model.itemPic, currentfridgeID: currentfridgeID, userID: userID})
                        //thestackView.clear()
                        //thestackView.push("qrc:/chat2.qml", { chatroomHeader: model.GPName, topicID: model.TopicID, senderID: currentUserID})
                }
                x: 5
                width: 150
                height: 200
                Column {

                    Image{
                        id: itemImage
                        width: 150
                        height: 150
                        source: model.itemPic
                        fillMode: Image.PreserveAspectFit
                    }
                    /*
                    Rectangle {
                        width: 150
                        height: 150
                        //color: colorCode
                        radius: 10
                        border.width: 1
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    */
                    Text {
                        x: 5
                        //text: name
                        //text: model.itemName
                        text: qsTr(model.itemName)
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                }
            }
            model: InventoryModel{
                id: theinventorymodel2;
                fridgeID: currentfridgeID
            }


        }


    }



}
