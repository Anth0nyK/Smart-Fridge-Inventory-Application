import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import ordermodel 1.0

Page {
    property string userID
    property string currentfridgeID

    width: 780
    height: 585

    NewOrderScreen{
        id:theNewOrderScreen
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
                text: qsTr("Orders")
                font.pixelSize: 25
            }

            Text {
                id: text2
                x: 25
                y: 82
                text: qsTr("Pending orders")
                font.pixelSize: 22
                font.bold: true
            }

            Text {
                id: text3
                x: 25
                y: 113
                text: qsTr("Order ID")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text4
                x: 300
                y: 113
                text: qsTr("Supplier ")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text5
                x: 407
                y: 113
                text: qsTr("Supplier email")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text6
                x: 573
                y: 113
                text: "Order date"
                font.pixelSize: 17
                font.bold: false
            }
        }

        ListView {
            id: listView
            x: 12
            y: 154
            width: 756
            height: 375
            clip: true
            delegate: Item {
                id: item1
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    z: 0
                    anchors.topMargin: 0

                    spacing: 50

                    Text {
                        text: orderID
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }

                    Text {
                        text: supplierName
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }

                    Text {
                        text: supplierEmail
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }

                    Text {
                        text: dateTime
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                }
            }
            model: OrderModel{
                id: theordermodel
                theorderID: currentfridgeID

            }
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

    }



}
