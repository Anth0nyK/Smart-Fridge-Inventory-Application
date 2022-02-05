import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import orderdetailmodel 1.0

Page {
    property string currentorderID

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
                text: qsTr("Orders > " + currentorderID)
                font.pixelSize: 25
            }

            Text {
                id: text2
                x: 25
                y: 82
                text: qsTr("Order details")
                font.pixelSize: 22
                font.bold: true
            }

            Text {
                id: text3
                x: 25
                y: 113
                text: qsTr("Item name")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text4
                x: 300
                y: 113
                text: qsTr("Quantity")
                font.pixelSize: 17
                font.bold: false
            }
        }


        GridView {
            id: gridView
            x: 22
            y: 156
            width: 736
            height: 410
            model: OrderdetailModel{
                id: theorderdetailmodel
                theorderID: currentorderID
            }
            cellWidth: 653
            delegate: ItemDelegate {
                x: 5
                width: 739
                height: 50
                onClicked:{

                }

                Row {
                    spacing: 5
                    /*
                    Rectangle {
                        width: 653
                        height: 40
                        color: colorCode
                        //anchors.horizontalCenter: parent.horizontalCenter
                    }
                    */
                    Column {
                        Text {
                            id: theItemName
                            x: 5
                            width:100
                            text: model.itemName
                            font.bold: true
                            //anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Column {

                        Text {
                            id: theItemCount
                            x: 180
                            width:10
                            font.bold: true
                            text: model.itemCount
                        }
                    }

                    /*
                    Column {
                        Text {
                            id: theSupplierEmail
                            x: 250
                            width:100
                            text: model.supplierEmail
                        }
                    }


                    Column {
                        Text {
                            id: theOrderDate
                            x: 350
                            text: model.dateTime
                        }
                    }
                    */
                }
            }
            cellHeight: 50
        }


        RoundButton {
            id: roundButton
            x: 701
            y: 489
            width: 60
            height: 60
            text: "+"
            checked: false
            checkable: true
            flat: true
            highlighted: true
            font.pointSize: 15
            font.bold: true
            background: Rectangle {
                radius: roundButton.radius
                color: "#43b05c"
            }
            onClicked: {
                thestackView.push(theNewOrderScreen, {currentfridgeID: currentfridgeID})

            }
        }

        Text {
            id: buttonText
            x: 705
            y: 549
            width: 53
            height: 17
            color: "#43b05c"
            text: qsTr("New order")
            font.pixelSize: 12
            font.bold: true
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
                theordermodel.updateorderModel()

            }
        }

    }



}
