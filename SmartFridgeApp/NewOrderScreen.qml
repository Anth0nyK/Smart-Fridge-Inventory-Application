import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import suppliermodel 1.0

Page {
    property string userID
    property string currentfridgeID
    //property StackView theStack: StackView.view

    width: 780
    height: 585

    function update(){
        thesuppliermodel.updatesupplierModel()
    }

    NewOrderItemsScreen{
        id: theNewOrderItemsScreen
    }

    Component.onCompleted: {
        update()
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
                text: qsTr("Orders > Select supplier")
                font.pixelSize: 25
            }

            Text {
                id: text3
                x: 25
                y: 79
                text: qsTr("Suppliers")
                font.pixelSize: 22
            }

            Text {
                id: text4
                x: 257
                y: 75
                font.pixelSize: 25
            }

        }

        GridView {
            id: gridView
            y: 116
            anchors.leftMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right
            contentWidth: 0
            anchors.rightMargin: 20
            clip: true
            height: 423
            cellWidth: 185
            cellHeight: 200
            delegate: ItemDelegate {
                onClicked: {
                        //console.info("model.itemID = " + model.itemID)
                        thestackView.push(theNewOrderItemsScreen, {currentfridgeID: currentfridgeID, currentsupplierName: model.supplierName, currentsupplierEmail: model.supplierEmail})
                        //thestackView.clear()
                        //thestackView.push("qrc:/chat2.qml", { chatroomHeader: model.GPName, topicID: model.TopicID, senderID: currentUserID})
                }
                x: 5
                width: 150
                height: 200
                Column {

                    Rectangle {
                        width: 150
                        height: 150
                        //color: colorCode
                        radius: 10
                        border.width: 1
                        anchors.horizontalCenter: parent.horizontalCenter

                        Text {
                            x: 5
                            y: 70
                            id: itemText
                            //text: name
                            //text: model.itemName
                            text: qsTr(model.supplierName)
                            font.bold: true
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            x: 5
                            y: 150
                            id: itemText2
                            //text: name
                            //text: model.itemName
                            text: qsTr(model.supplierEmail)
                            font.bold: true
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                }
            }
            model: SupplierModel{
                id: thesuppliermodel;
                thefridgeID: currentfridgeID
            }




        }
/*
        Button {
            id: backbutton
            x: 726
            y: 81
            text: qsTr("Back")
            font.pointSize: 13
            font.bold: true
            onClicked: {
                thestackView.pop()
                thesuppliermodel.updatesupplierModel()
            }
        }




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
