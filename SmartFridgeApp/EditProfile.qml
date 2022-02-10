import QtQuick 2.14
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import iteminfo 1.0
import activityLogHelper 1.0
import profileinfo 1.0

import usersManagementHelper 1.0

Page {
    id: page
    //property StackView theStack: StackView.view
    property string currentUserID
    property string currentfridgeID

    //property string thatUserID
    width: 780
    height: 585

    ProfileHelper{
        id: theProfileHelper
    }

    ItemHelper{
        id: itemtool
    }

    ActivityLogHelper{
        id: theActivityLogHelper
    }

    UsersManagementHelper{
        id: theUsersManagementHelper
    }

    function changeItemPic(){
        if(pictureLink.text != "")
        {
            image.source = pictureLink.text
            image.visible = true
            image2.visible = false
            //itemtool.changePicture(itemID,pictureLink.text)
            //pictureLink.text = ""
            //message.text = "Updated the item picture"
            //let action = "Profile picture of item: " + itemtool.getItemname(itemID) + " was updated"
            //theActivityLogHelper.createLog(action, theProfileHelper.getUsername(currentUserID), currentfridgeID)
        }
    }

    function deleteAccount(){
        let succeed = 0
        succeed = theUsersManagementHelper.deleteAccount(thatUserID)
        if(succeed == 1){
            message.text = "Account deleted"
            button2.visible = false
            button1.visible = false
            button3.visible = false
            button4.visible = false
        }
        if(succeed == 2){
            message.text = "Cannot delete an admin account"
        }
    }

    function updateItemInfo(){
        if(nameField.text != ""){
            //itemtool.updateItemInfo(nameField.text, phoneField.text, alertField.text,reorderField.text, emailField.text, itemID)
            let suceed = 0
            suceed = theUsersManagementHelper.updateInfo(image.source, nameField.text, emailField.text, phoneField.text, currentUserID)
            if(suceed == 1){
                message.text = "Updated the user info"
                //image.source = theUsersManagementHelper.getPic(thatUserID)

                let action = "User info of user: " + theProfileHelper.getUsername(currentUserID) + " was updated"
                theActivityLogHelper.createLog(action, theProfileHelper.getUsername(currentUserID), currentfridgeID)

            }
        }
    }

    function updatePW(){
        if(newpwField.text == newpw2Field.text){
            let succeed = 0
            succeed = theUsersManagementHelper.updatePW(oldpwField.text, newpwField.text, currentUserID)
            if(succeed == 1){
                message.text = "Updated the user password"
            }else{
                message.text = "Wrong password"
            }
        }else{
            message.text = "Passwords do not match"
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
            text: qsTr("Profile")
            //text: qsTr("Management > Users > " + theProfileHelper.getUsername(thatUserID))
            font.pixelSize: 25
            font.bold: false
        }

        Image {
            id: image
            x: 16
            y: 81
            visible: false
            width: 166
            height: 166
            source: theUsersManagementHelper.getPic(currentUserID)
            fillMode: Image.PreserveAspectFit

        }
        Image {
            id: image2
            x: 16
            y: 81
            visible: true
            width: 166
            height: 166
            source: theUsersManagementHelper.getPic(currentUserID)
            fillMode: Image.PreserveAspectFit
        }

        Button {
            id: button
            x: 59
            y: 293
            text: qsTr("Test a photo")
            enabled: true
            hoverEnabled: false
            font.bold: true
            flat: false
            background: Rectangle {
                //radius: roundButton.radius
                color: "#43b05c"
            }
            onClicked: {
                changeItemPic()
            }
        }

        Text {
            id: itemnameText1
            x: 188
            y: 81
            text: "Name:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: suppliertext
            x: 188
            y: 195
            text: "Phone number:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: supplieremailField
            x: 188
            y: 141
            text: "Email address:"
            font.pixelSize: 25
            font.bold: false
        }

        Rectangle {
            id: rectangle1
            x: 265
            y: 81
            width: 162
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2

            TextInput {
                id: nameField
                x: 10
                y: 8
                width: 146
                height: 20
                text: qsTr(theProfileHelper.getUsername(currentUserID))
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: rectangle2
            x: 362
            y: 194
            width: 203
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2

            TextInput {
                id: phoneField
                x: 8
                y: 8
                width: 187
                height: 20
                text: qsTr(theUsersManagementHelper.getTel(currentUserID))
                font.pixelSize: 12
            }
        }

        Button {
            id: button1
            x: 336
            y: 427
            text: qsTr("Change password")
            enabled: true
            hoverEnabled: false
            background: Rectangle {
                color: "#9e0000"
                //radius: roundButton.radius
            }
            flat: false
            font.bold: true
            onClicked: {
                updatePW()
            }
        }


        //QString itemName, QString supplierName, QString alertWhen, QString reorderWhen, QString supplierEmail
        Rectangle {
            id: rectangle5
            x: 16
            y: 253
            width: 166
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2
            TextInput {
                id: pictureLink
                x: 6
                y: 7
                width: 152
                height: 20
                text: ""
                font.pixelSize: 12
                horizontalAlignment: Text.AlignLeft
            }
        }

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

        Text {
            id: suppliertext1
            x: 188
            y: 293
            text: "Old password:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: suppliertext2
            x: 188
            y: 333
            text: "New password:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: suppliertext3
            x: 188
            y: 373
            text: "Confirm password:"
            font.pixelSize: 25
            font.bold: false
        }

        Button {
            id: button2
            x: 349
            y: 244
            text: qsTr("Save changes")
            flat: false
            enabled: true
            hoverEnabled: false
            background: Rectangle {
                color: "#9e0000"
            }
            font.bold: true
            onClicked: {
                updateItemInfo()
            }
        }

        Button {
            id: button4
            x: 343
            y: 509
            visible: false
            text: qsTr("Confirm delete")
            hoverEnabled: false
            enabled: true
            flat: false
            font.bold: true
            background: Rectangle {
                color: "#9e0000"
            }
            onClicked: {
                deleteAccount()
            }
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
        x: 363
        y: 143
        width: 203
        height: 34
        color: "#ffffff"
        radius: 5
        border.width: 2

        TextInput {
            id: emailField
            x: 8
            y: 8
            width: 187
            height: 20
            text: qsTr(theUsersManagementHelper.getEmail(currentUserID))
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: rectangle7
        x: 397
        y: 374
        width: 203
        height: 34
        color: "#ffffff"
        radius: 5
        border.width: 2
        TextInput {
            id: newpw2Field
            x: 8
            y: 8
            width: 187
            height: 20
            font.pixelSize: 12
            echoMode: TextInput.Password
        }
    }

    Rectangle {
        id: rectangle8
        x: 397
        y: 334
        width: 203
        height: 34
        color: "#ffffff"
        radius: 5
        border.width: 2
        TextInput {
            id: newpwField
            x: 8
            y: 8
            width: 187
            height: 20
            font.pixelSize: 12
            echoMode: TextInput.Password
        }
    }

    Rectangle {
        id: rectangle9
        x: 397
        y: 294
        width: 203
        height: 34
        color: "#ffffff"
        radius: 5
        border.width: 2
        TextInput {
            id: oldpwField
            x: 8
            y: 8
            width: 187
            height: 20
            font.pixelSize: 12
            echoMode: TextInput.Password
        }
    }


}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:2}D{i:3}D{i:4}D{i:6}D{i:7}D{i:8}D{i:9}D{i:10}
D{i:12}D{i:13}D{i:14}D{i:16}D{i:15}D{i:18}D{i:17}D{i:19}D{i:22}D{i:21}D{i:23}D{i:24}
D{i:25}D{i:26}D{i:27}D{i:29}D{i:31}D{i:5}D{i:34}D{i:33}D{i:36}D{i:35}D{i:38}D{i:37}
D{i:40}D{i:39}
}
##^##*/
