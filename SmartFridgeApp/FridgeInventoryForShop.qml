import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import permissionHelper 1.0
import inventorymodel 1.0
import orderHelper 1.0

Page {
    property string userID
    property string userImage
    property string currentfridgeID
    //property StackView theStack: StackView.view
    property int counter

    //width: 780
    width: 780
    height: 585



    OrderHelper{
        id: theOrderHelper
    }

    /*
    NewItemScreen{
        id: theNewItemScreen
    }

    ItemScreen{
        id: theItemScreen
    }

    OpenDoorScreen{
        id: theoOpenDoorScreen
    }

    PermissionScreen{
        id: thePermissionScreen
    }


    */

    PermissionHelper {
        id: thePermissionHelper
    }

    UnlockedScreenForShop{
        id:theUnlockedScreenForShop
        visible: false
    }



    function testing(){
        text3.text = gridView.getDelegateInstanceAt(1).itemName
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
        text3.text = counter
    }

    function openPermissionScreen(){
        let x = 0
        x = thePermissionHelper.checkIfAdmin(userID)
        if(x == 1){
            thestackView.push(thePermissionScreen, {currentfridgeID: currentfridgeID, userID: currentUserID})
        }
    }

    function checkPermission(){
        let x = 0
        x = thePermissionHelper.checkViewPermission(userID)
        if(x == 1){
            return true
        }else{
            message.text = "You don't have permission to view the inventory"
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

    function checkIfcanOK(){
        let x = ""
        x = theOrderHelper.findOrder(orderIDField.text)
        //message.text = x
        if(x == fridgeIDField.text){
            //message.text = "can open"
            theUnlockedScreenForShop.visible = true
            thestackView.push(theUnlockedScreenForShop, {currentorderID: orderIDField.text,fridgeID: fridgeIDField.text, userID: currentUserID})

        }else{
            message.text = "Order ID or fridgeID not valid"
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
                text: qsTr("Fridge")
                font.pixelSize: 25
            }

            Rectangle {
            id: rectangle5
            x: 329
            y: 334
            width: 250
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2

            TextInput {
            id: fridgeIDField
            x: 6
            y: 7
            width: 238
            height: 20
            text: ""
            font.pixelSize: 12
            horizontalAlignment: Text.AlignLeft
            }
            }
/*
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
*/
            Button {
            id: button
            x: 325
            y: 456
            width: 130
            height: 26
            text: qsTr("Unlock door")
            background: Rectangle {
                color: "#43b05c"
            }
            hoverEnabled: false
            enabled: true
            flat: false
            font.bold: true
            onClicked: {
                checkIfcanOK()
            }
            }

            Text {
                id: text3
                x: 25
                y: 61
                text: ""
                font.pixelSize: 25
            }

            Text {
                id: text2
                x: 217
                y: 334
                text: qsTr("Fridge ID:")
                font.pixelSize: 25
            }

            Text {
                id: text5
                x: 217
                y: 390
                text: qsTr("Order ID:")
                font.pixelSize: 25
            }

            Rectangle {
                id: rectangle6
                x: 329
                y: 390
                width: 250
                height: 34
                color: "#ffffff"
                radius: 5
                border.width: 2
                TextInput {
                    id: orderIDField
                    x: 6
                    y: 7
                    width: 238
                    height: 20
                    text: ""
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignLeft
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
        Text {
            id: message
            x: 298
            y: 501
            width: 185
            height: 34
            font.pixelSize: 25
            horizontalAlignment: Text.AlignHCenter
        }

        Image {
            id: image
            x: 300
            y: 145
            width: 180
            height: 162
            source: "images/lockBig.png"
            fillMode: Image.PreserveAspectFit
        }
    }



}
