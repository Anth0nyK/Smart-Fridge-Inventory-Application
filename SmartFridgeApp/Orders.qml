import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import ordermodel 1.0
import order2model 1.0
import inventorymodel 1.0
import permissionHelper 1.0

Page {
    property string userID
    property string currentfridgeID

    width: 780
    height: 585

    NewOrderScreen{
        id:theNewOrderScreen
    }

    OrderDetail{
        id: theOrderDetailScreen
    }

    PermissionHelper{
        id: thePermissionHelper
    }

    function checkOrderPermission(){
        let x = 0
        x = thePermissionHelper.checkOrderPermission(userID)
        if(x == 1){
            return true
        }else{
            message.text = "You don't have permission"
            return false
        }
    }

    function completedOrNot(number){
        if(number === 1){
            return "Yes"
        }else{
            return "No"
        }
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
                id: text3
                x: 25
                y: 90
                text: qsTr("Order ID")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text4
                x: 276
                y: 90
                text: qsTr("Supplier ")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text5
                x: 413
                y: 90
                text: qsTr("Supplier email")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text6
                x: 570
                y: 90
                text: "Order date"
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: message
                x: 301
                y: 312
                width: 178
                height: 34
                font.pixelSize: 25
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: text7
                x: 689
                y: 90
                text: "Completed"
                font.pixelSize: 17
                font.bold: false
            }
        }

        /*
        ListView {
            id: listView
            x: 12
            y: 154
            width: 756
            height: 375
            clip: true
            delegate: ItemDelegate {
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
*/

        GridView {
            id: gridView
            x: 19
            y: 123
            width: 739
            height: 434
            cellWidth: 653
            visible: checkOrderPermission()
            clip: true
            delegate: ItemDelegate {
                x: 5
                width: 739
                height: 50
                onClicked: {
                        //console.info("model.itemID = " + model.itemID)
                        thestackView.push(theOrderDetailScreen, {currentorderID: model.orderID})
                        theordermodel.updateorderModel()
                        //thestackView.clear()
                        //thestackView.push("qrc:/chat2.qml", { chatroomHeader: model.GPName, topicID: model.TopicID, senderID: currentUserID})
                }
                /*
                Text{
                    text: model.orderID
                    font.bold: true
                }*/

                Row {
                    spacing: 5

                    Column {
                        Text {
                            id: theOrderID
                            x: 0
                            width:100
                            text: model.orderID
                            font.bold: true
                            //anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Column {

                        Text {
                            id: theSupplierName
                            x: 150
                            width:10
                            text: model.supplierName
                        }
                    }


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
                            x: 300
                            text: model.dateTime
                        }
                    }

                    Column {
                        Text {
                            id: theCompleted
                            x: 350
                            text: completedOrNot(model.completed)
                        }
                    }

                }
            }
            cellHeight: 50

            model: OrderModel{
                id: theordermodel
                theorderID: currentfridgeID
            }

            /*
            model: InventoryModel{
                id: theInventoryModel
                fridgeID: currentfridgeID
            }*/
        }

        RoundButton {
            id: roundButton
            x: 698
            y: 497
            width: 60
            height: 60
            text: "+"
            Text {
                id: buttonText
                x: 1
                y: 59
                width: 59
                height: 17
                color: "#43b05c"
                text: qsTr("New order")
                font.pixelSize: 12
                font.bold: true
            }
            highlighted: true
            background: Rectangle {
                color: "#43b05c"
                radius: roundButton.radius
            }
            flat: true
            checked: false
            font.bold: true
            checkable: true
            font.pointSize: 15
            onClicked: {
                thestackView.push(theNewOrderScreen, {currentfridgeID: currentfridgeID, userID: userID})
            }
        }




    }



}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:2}D{i:3}D{i:6}D{i:7}D{i:8}D{i:9}D{i:10}D{i:11}
D{i:12}D{i:5}D{i:13}D{i:28}D{i:27}D{i:4}
}
##^##*/
