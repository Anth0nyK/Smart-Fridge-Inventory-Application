import QtQuick 2.14
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import iteminfo 1.0
import activityLogHelper 1.0
import profileinfo 1.0
import restaurantinfoHelper 1.0

Page {
    id: page
    //property string itemID
    //property string itemPic
    //property StackView theStack: StackView.view
    property string currentUserID
    property string currentfridgeID
    width: 780
    height: 585

    ProfileHelper{
        id: theProfileHelper
    }

    RestaurantinfoHelper{
        id: theRestaurantInfoHelper
    }

    ActivityLogHelper{
        id: theActivityLogHelper
    }



    function updateInfo(){
        if(restaurantNameField.text != "" && address1Field.text != "" && telField.text != ""){
            let succeed = 0
            succeed = theRestaurantInfoHelper.update(restaurantNameField.text, address1Field.text, address2Field.text, address3Field.text, telField.text, currentfridgeID)
            if(succeed == 1){
                message.text = "Updated the info"
                let action = "Restaurant information was updated"
                theActivityLogHelper.createLog(action, theProfileHelper.getUsername(currentUserID), currentfridgeID)
            }
        }
        else{
            message.text = "Please fill in the essential fields"
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

        Button {
            id: backbutton
            x: 726
            y: 81
            text: qsTr("Back")
            font.pointSize: 13
            font.bold: true
            onClicked: {
                message.text = ""
                thestackView.pop()
                //theinventorymodel.updateinventoryModel()
            }
        }

        Text {
            id: itemnameText
            x: 16
            y: 20
            text: "Management > Restaurant details"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: itemnameText1
            x: 207
            y: 134
            text: "name:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: suppliertext
            x: 207
            y: 188
            text: "address:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: supplieremailField
            x: 207
            y: 346
            text: "tel:"
            font.pixelSize: 25
            font.bold: false
        }

        Rectangle {
            id: rectangle1
            x: 349
            y: 134
            width: 268
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2

            TextInput {
                id: restaurantNameField
                x: 10
                y: 8
                width: 250
                height: 20
                text: qsTr(theRestaurantInfoHelper.getName(currentfridgeID))
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: rectangle2
            x: 349
            y: 188
            width: 268
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2

            TextInput {
                id: address1Field
                x: 8
                y: 8
                width: 252
                height: 20
                text: qsTr(theRestaurantInfoHelper.getAddress1(currentfridgeID))
                font.pixelSize: 12
            }
        }

        Button {
            id: button1
            x: 349
            y: 507
            text: qsTr("Save changes")
            enabled: true
            hoverEnabled: false
            background: Rectangle {
                color: "#9e0000"
                //radius: roundButton.radius
            }
            flat: false
            font.bold: true
            onClicked: {
                updateInfo()
            }
        }


        //QString itemName, QString supplierName, QString alertWhen, QString reorderWhen, QString supplierEmail

        Text {
            id: message
            x: 262
            y: 539
            width: 257
            height: 28
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 21
            font.bold: false
        }

        Text {
            id: itemnameText2
            x: 16
            y: 81
            text: "Restaurant details"
            font.pixelSize: 25
            font.bold: false
        }

        Rectangle {
            id: rectangle3
            x: 349
            y: 243
            width: 268
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2
            TextInput {
                id: address2Field
                x: 8
                y: 8
                width: 252
                height: 20
                text: qsTr(theRestaurantInfoHelper.getAddress2(currentfridgeID))
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: rectangle4
            x: 349
            y: 297
            width: 268
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2
            TextInput {
                id: address3Field
                x: 8
                y: 8
                width: 252
                height: 20
                text: qsTr(theRestaurantInfoHelper.getAddress3(currentfridgeID))
                font.pixelSize: 12
            }
        }

        Text {
            id: itemnameText3
            x: 207
            y: 412
            text: qsTr("FridgeID: " + currentfridgeID )
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: text1
            x: 623
            y: 134
            text: qsTr("*")
            font.pixelSize: 18
        }

        Text {
            id: text2
            x: 624
            y: 188
            text: qsTr("*")
            font.pixelSize: 18
        }

        Text {
            id: text3
            x: 625
            y: 346
            text: qsTr("*")
            font.pixelSize: 18
        }

/*

        C1.TableView {
            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.topMargin: 296
            columnSpacing: 1
            rowSpacing: 1
            clip: true

            //model: TableModel {}
            C1.TableViewColumn { role: "itemName" ; title: "name"}
            model: InventoryModel{
                id: theinventorymodel;
                fridgeID: "1"
            }
        }
*/

/*
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

    Rectangle {
        id: rectangle6
        x: 350
        y: 347
        width: 269
        height: 34
        color: "#ffffff"
        radius: 5
        border.width: 2

        TextInput {
            id: telField
            x: 8
            y: 8
            width: 253
            height: 20
            text: qsTr(theRestaurantInfoHelper.getTel(currentfridgeID))
            font.pixelSize: 12
        }
    }


}


/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}D{i:1}D{i:2}D{i:3}D{i:5}D{i:6}D{i:7}D{i:8}D{i:9}D{i:10}D{i:12}
D{i:11}D{i:14}D{i:13}D{i:15}D{i:17}D{i:18}D{i:20}D{i:19}D{i:22}D{i:21}D{i:23}D{i:24}
D{i:25}D{i:26}D{i:4}D{i:28}D{i:27}
}
##^##*/
