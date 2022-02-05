import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import ordermodel 1.0
//import inventorymodel 1.0
import usersmodel 1.0
import permissionHelper 1.0

Page {
    property string userID
    property string currentfridgeID

    width: 780
    height: 585

    NewOrderScreen{
        id:theNewOrderScreen
    }

    CreateAccountScreen{
        id: theCreateAccountScreen
    }

    UsersManagementInfoScreen{
        id: theUsersManagementScreen
    }

    PermissionScreen{
        id: thePermissionScreen
    }

    PermissionHelper{
        id: thePermissionHelper
    }



    function openPermissionScreen(){
        let x = 0
        x = thePermissionHelper.checkIfAdmin(userID)
        if(x == 1){
            thestackView.push(thePermissionScreen, {currentfridgeID: currentfridgeID, userID: userID})
        }
    }

    function checkPermission(){
        let x = 0
        x = thePermissionHelper.checkViewPermission(userID)
        if(x == 1){
            return true
        }else{
            text4.text = "You don't have permission to view the inventory"
            return false
        }
    }

    function checkIfAdmin(){
        let x = 0
        x = thePermissionHelper.checkIfAdmin(userID)
        if (x == 1){
            return true
        }else{
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

            Image {
                id: peopleButton
                x: 520
                y: 21
                width: 65
                height: 34
                source: "images/people.png"
                visible: checkIfAdmin()
                fillMode: Image.PreserveAspectFit
                MouseArea {
                    anchors.fill: parent
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    onClicked: {
                        //console.info("image clicked!2")
                        //thestackView.push(thePermissionScreen, {currentfridgeID: currentfridgeID, userID: currentUserID})
                        openPermissionScreen()
                    }
                }
                Text {
                    id: permissionButtonRxr
                    x: 1
                    y: 27
                    text: qsTr("Permissions")
                    font.pixelSize: 12
                }

            }

            Text {
                id: text1
                x: 25
                y: 21
                text: qsTr("Management > Users")
                font.pixelSize: 25
            }

            Text {
                id: text2
                x: 25
                y: 82
                text: qsTr("Users")
                font.pixelSize: 22
                font.bold: true
            }

            Text {
                id: text3
                x: 25
                y: 113
                text: qsTr("UserID")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text4
                x: 230
                y: 113
                text: qsTr("name")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text5
                x: 391
                y: 113
                text: qsTr("Email")
                font.pixelSize: 17
                font.bold: false
            }

            Text {
                id: text6
                x: 599
                y: 113
                text: "tel"
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
            x: 26
            y: 156
            width: 732
            height: 410
            cellWidth: 653
            delegate: ItemDelegate {
                x: 5
                width: 739
                height: 50
                onClicked: {
                        //console.info("model.itemID = " + model.itemID)
                        thestackView.push(theUsersManagementScreen, {thatUserID: model.UserID, currentUserID: userID, currentfridgeID: currentfridgeID})
                        theusermodel.updateusersmodel()
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
                            id: theUserID
                            x: 0
                            width:100
                            text: model.UserID
                            font.bold: true
                            //anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Column {

                        Text {
                            id: theUsername
                            x: 100
                            width:10
                            text: model.Username
                        }
                    }


                    Column {
                        Text {
                            id: theEmail
                            x: 250
                            width:100
                            text: model.email
                        }
                    }


                    Column {
                        Text {
                            id: theTel
                            x: 350
                            text: model.tel
                        }
                    }

                }
            }
            cellHeight: 50

            model: UsersModel{
                id: theusermodel
                fridgeID: currentfridgeID
            }

            /*
            model: InventoryModel{
                id: theInventoryModel
                fridgeID: currentfridgeID
            }*/
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
                thestackView.push(theCreateAccountScreen, {currentfridgeID: currentfridgeID, currentUserID: userID})

            }
        }

        Text {
            id: buttonText
            x: 688
            y: 549
            width: 86
            height: 17
            color: "#43b05c"
            text: qsTr("Create account")
            font.pixelSize: 12
            font.bold: true
        }

    }



}

