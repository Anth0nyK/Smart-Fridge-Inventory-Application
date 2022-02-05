import QtQuick 2.14
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import permissionHelper 1.0

Page {
    id: page
    property string currentfridgeID
    property string userID
    width: 780
    height: 585

    PermissionHelper {
        id: thePermissionHelper
    }

    InsertItemScreen{
        id: theInsertItemScreen
    }

    TakeItemScreen{
        id: theTakeItemScreen
    }

    RestaurantInfoScreen{
        id: theRestaurantInfoScreen
    }

    UsersManagementScreen{
        id: theUsersManagementScreen
    }

    function checkPermission(){
        let x = 0
        x = thePermissionHelper.checkIfAdmin(userID)
        if(x == 1){
            return true
        }else{
            message2.text = "You don't have permission"
            return false

        }
    }

    Rectangle {

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
            //height 58
            height: 75
            color: "#eeeeee"
            border.color: "#bababa"
        }

        Text {
            id: itemnameText
            x: 16
            y: 20
            text: "Management"
            font.pixelSize: 25
            font.bold: false
        }


        //QString itemName, QString supplierName, QString alertWhen, QString reorderWhen, QString supplierEmail

        Text {
            id: message
            x: 263
            y: 539
            width: 257
            height: 28
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 21
            font.bold: false
        }

        Image {
            id: borderImage1
            x: 430
            y: 193
            width: 200
            height: 200
            visible: checkPermission()
            source: "images/users.png"
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                onClicked: {
                    //console.info("image clicked!3")
                    thestackView.push(theUsersManagementScreen, {currentfridgeID: currentfridgeID, userID: userID})
                }
            }

            Text {
                id: itemnameText2
                x: 70
                y: 193
                text: "Users"
                font.pixelSize: 25
                font.bold: false
            }
        }

        Image {
            id: borderImage2
            x: 160
            y: 193
            width: 200
            height: 200
            visible: checkPermission()
            source: "images/forRest.png"
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                onClicked: {
                    thestackView.push(theRestaurantInfoScreen, {currentfridgeID: fridgeID, currentUserID: userID})
                    //console.info("image clicked!3")
                }
            }

            Text {
                id: itemnameText1
                x: 41
                y: 196
                text: "Restaurant"
                font.pixelSize: 25
                font.bold: false
            }

        }

        Text {
            id: message2
            x: 289
            y: 276
            width: 203
            height: 34
            font.pixelSize: 25
            horizontalAlignment: Text.AlignHCenter
            font.bold: false
        }







    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:2}D{i:3}D{i:4}D{i:5}D{i:7}D{i:8}D{i:9}D{i:11}
D{i:12}D{i:10}D{i:14}D{i:15}D{i:13}D{i:16}D{i:6}
}
##^##*/
