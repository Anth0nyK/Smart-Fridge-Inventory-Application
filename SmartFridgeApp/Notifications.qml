import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import activitylogmodel 1.0
import permissionHelper 1.0
import noticeModel 1.0

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

    PermissionHelper {
        id: thePermissionHelper
    }

    function checkHistoryPermission(){
        let x = 0
        x = thePermissionHelper.checkHistoryPermission(userID)
        if(x == 1){
            return true
        }else{
            message.text = "You don't have permission"
            return false
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
                text: qsTr("Notifications")
                font.pixelSize: 25
            }

            Text {
                id: text3
                x: 25
                y: 87
                visible: checkHistoryPermission()
                text: qsTr("Notifications")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text6
                x: 524
                y: 88
                visible: checkHistoryPermission()
                text: "Date Time"
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: message
                x: 290
                y: 311
                width: 200
                height: 34
                font.pixelSize: 25
                horizontalAlignment: Text.AlignHCenter
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
            x: 25
            y: 119
            width: 733
            height: 447
            clip: true
            cellWidth: 653
            visible: checkHistoryPermission()
            delegate: Item {
                x: 5
                width: 739
                height: 50
                /*
                Text{
                    text: model.orderID
                    font.bold: true
                }*/

                Row {
                    spacing: 5

                    Column {
                        Text {
                            id: theAction
                            x: 0
                            width:100
                            text: model.message
                            font.bold: true
                            //anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    /*
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
                            id: theBy
                            x: 250
                            width:100
                            text: model.by
                        }
                    }
                    */

                    Column {
                        Text {
                            id: theDateTime
                            x: 350
                            text: model.dateTime
                        }
                    }

                }
            }
            cellHeight: 50
            model: NoticeModel{
                id: theNoticeModel
                fridgeID: currentfridgeID
            }

            /*
            model: Activitylogmodel{
                id: theActivitylogmodel
                fridgeID: currentfridgeID
            }


            model: InventoryModel{
                id: theInventoryModel
                fridgeID: currentfridgeID
            }*/


        }


    }



}
