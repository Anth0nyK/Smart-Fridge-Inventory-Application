import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import permissionModel 1.0

import activityLogHelper 1.0
import profileinfo 1.0

import permissionHelper 1.0

Page {
    property string userID
    property string currentfridgeID
    //property StackView theStack: StackView.view
    //property string currentsupplierName
    //property string currentsupplierEmail

    property int counter
    property int done: 0

    width: 780
    height: 585



    OrderConfirmScreen{
        id: theOrderConfirmScreen
    }

    ActivityLogHelper{
        id: theActivityHelper
    }

    ProfileHelper{
        id: theProfileHelper
    }

    PermissionHelper {
        id: thePermissionHelper
    }

    function countItems(){
        counter = 0

        while(true){
            if(gridView.getDelegateInstanceAt(counter) != undefined){
                counter = counter + 1
            }
            else{
                break
            }
        }
        //text3.text = counter
    }


    function updatePermission(){
        countItems()
        let x = 0;
        for (let i = 0; i < counter; i++) {
            //x = x + theOrderHelper.addItemToOrder(uUID, gridView.getDelegateInstanceAt(i).itemName, gridView.getDelegateInstanceAt(i).itemCount)
            let succeed = 0
            succeed = thePermissionHelper.update(gridView.getDelegateInstanceAt(i).canView, gridView.getDelegateInstanceAt(i).canOpen, gridView.getDelegateInstanceAt(i).canHistory, gridView.getDelegateInstanceAt(i).canOrder, gridView.getDelegateInstanceAt(i).userID)
            if(succeed == 1){

                let thatUser
                thatUser = theProfileHelper.getUsername(gridView.getDelegateInstanceAt(i).userID)

                let action = "Permission of user: "+ thatUser +" was updated"
                theActivityHelper.createLog(action, theProfileHelper.getUsername(userID),currentfridgeID)
                x = x + 1

            }


        }
        done = x
    }


    function checkIfDone(){
        if(done != 0){

            //theActivityHelper.createLog(action, theProfileHelper.getUsername(userID),currentfridgeID)
            //thestackView.push(theOrderConfirmScreen, {uuid: uUID, supplierName: currentsupplierName})
            message.text = "Updated " + done + " user(s) permissions"
        }
        else{

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

        Text {
            id: message
            x: 263
            y: 551
            width: 257
            height: 28
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 21
            font.bold: false
        }

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
                text: "Fridge > Permissions"
                font.pixelSize: 25
            }

            Text {
                id: text3
                x: 25
                y: 79
                text: qsTr("Name")
                font.pixelSize: 22
            }

            Text {
                id: text4
                x: 373
                y: 79
                text: qsTr("Permissions")
                font.pixelSize: 22


            }

        }


        GridView {
            id: gridView
            y: 117
            anchors.leftMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right
            contentWidth: 0
            anchors.rightMargin: 20
            clip: true
            height: 400
            width: 739
            cellWidth: 653
            cellHeight: 40
            delegate: Item {
                objectName: "summaryDelegate2"
                property int index: model.index
                //property string itemCount: amountInput.value
                property bool canView: checkBoxCanView.checked
                property bool canOpen: checkBoxCanOpen.checked
                property bool canHistory: checkBoxCanHistory.checked
                property bool canOrder: checkBoxCanOrder.checked
                property string userID: model.userID
                /*
                onClicked: {
                        //console.info("model.itemID = " + model.itemID)
                        thestackView.push(theItemScreen, {itemID: model.itemID, itemPic: model.itemPic})
                        //thestackView.clear()
                        //thestackView.push("qrc:/chat2.qml", { chatroomHeader: model.GPName, topicID: model.TopicID, senderID: currentUserID})
                }*/
                x: 5
                width: 654
                height: 40
                Row {
                    spacing: 5

                    Column {
                        Text {
                            id: theName
                            x: 20
                            width:100
                            text: theProfileHelper.getUsername(model.userID)
                            font.bold: true
                            //anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Column {
                        /*
                        Text {
                            id: theCanView
                            x: 150
                            width:10
                            text: qsTr("State: " + checkBoxCanView.checked)
                        }
                        */


                        CheckBox {
                            id: checkBoxCanView
                            x: 20
                            y: 29
                            text: qsTr("Can view inv")
                            font.pointSize: 11
                            checked: model.canView
                        }
                    }


                    Column {
                        /*
                        Text {
                            id: theCanOpen
                            x: 250
                            width:100
                            text: model.supplierEmail
                        }*/
                        CheckBox {
                            id: checkBoxCanOpen
                            x: 60
                            y: 29
                            font.pointSize: 11
                            text: qsTr("Can open door")

                            checked: model.canOpen
                        }
                    }

                    Column {
                        /*
                        Text {
                            id: theCanOpen
                            x: 250
                            width:100
                            text: model.supplierEmail
                        }*/
                        CheckBox {
                            id: checkBoxCanHistory
                            x: 100
                            y: 29
                            font.pointSize: 11
                            text: qsTr("Can view history")

                            checked: model.canHistory
                        }
                    }

                    Column {
                        /*
                        Text {
                            id: theCanOpen
                            x: 250
                            width:100
                            text: model.supplierEmail
                        }*/
                        CheckBox {
                            id: checkBoxCanOrder
                            x: 150
                            y: 29
                            font.pointSize: 11
                            text: qsTr("Can view orders")

                            checked: model.canOrder
                        }
                    }

                    /*
                    Column {
                        Text {
                            id: theOrderDate
                            x: 350
                            text: model.dateTime
                        }
                    }*/

                }

            }
            model: PermissionModel{
                id: thePermissionModel
                fridgeID: currentfridgeID
            }



            function getDelegateInstanceAt(index) {
                for(var i = 0; i < contentItem.children.length; ++i) {
                    var item = contentItem.children[i];
                    if (item.objectName == "summaryDelegate2" && item.index == index)
                        return item;
                }
                return undefined;
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
                //thesuppliermodel.updatesupplierModel()
                //theinventorymodel.updateinventoryModel()
                theusermodel.updateusersmodel()
            }
        }


        Button {
            id: button1
            x: 340
            y: 521
            width: 100
            height: 26
            text: qsTr("CONFIRM")

            hoverEnabled: false
            background: Rectangle {
                color: "#43b05c"
                //radius: roundButton.radius
            }
            flat: false
            font.bold: true
            onClicked: {
                updatePermission()
                checkIfDone()
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
    D{i:0;formeditorZoom:0.9}D{i:1}D{i:2}D{i:3}D{i:4}D{i:6}D{i:8}D{i:9}D{i:10}D{i:7}D{i:11}
D{i:25}D{i:26}D{i:5}
}
##^##*/
