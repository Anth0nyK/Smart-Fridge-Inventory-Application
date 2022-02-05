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



    function updateItemInfo(){
        if(nameField.text != "" && userIDField.text != ""){
            if(pwField.text == pw2Field.text){
                if(pwField.length > 5){
                    //itemtool.updateItemInfo(nameField.text, phoneField.text, alertField.text,reorderField.text, emailField.text, itemID)
                    let suceed = 0
                    //suceed = theUsersManagementHelper.updateInfo(image1.source, nameField.text, emailField.text, phoneField.text, thatUserID)
                    suceed = theUsersManagementHelper.createaAccount(userIDField.text, pwField.text, nameField.text, theProfileHelper.getAccountType(currentUserID), currentfridgeID, image.source, emailField.text, phoneField.text)
                    if(suceed == 1){
                        message.text = "Created a new account"
                        //image.source = theUsersManagementHelper.getPic(thatUserID)

                        let action = "New user: " + nameField.text + " was created"
                        theActivityLogHelper.createLog(action, theProfileHelper.getUsername(currentUserID), currentfridgeID)

                        userIDField.text= ""
                        pwField.text = ""
                        pw2Field.text = ""
                        nameField.text = ""
                        emailField.text = ""
                        phoneField.text = ""
                }else{
                        message.text = "UserID was taken"

                    }



                }else{
                    message.text = "Password needs to be at least 6 characters"
                }
            }
            else{
                message.text = "Passwords do not match"
                pwField.text = ""
                pw2Field.text = ""
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
                theusermodel.updateusersmodel()
                image.visible = false
                image2.visible = true

            }
        }

        Text {
            id: itemnameText
            x: 16
            y: 20
            text: "Management > Create account"
            font.pixelSize: 25
            font.bold: false
        }

        Image {
            id: image
            x: 16
            y: 81
            width: 166
            visible: false
            height: 166
            source: "images/default.png"
            fillMode: Image.PreserveAspectFit

        }
        Image {
            id: image2
            x: 16
            y: 81
            visible: true
            width: 166
            height: 166
            source: "images/default.png"
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
            y: 141
            text: "Name:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: suppliertext
            x: 188
            y: 221
            text: "Phone number:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: supplieremailField
            x: 188
            y: 181
            text: "Email address:"
            font.pixelSize: 25
            font.bold: false
        }

        Rectangle {
            id: rectangle1
            x: 265
            y: 141
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
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: rectangle2
            x: 362
            y: 221
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
                font.pixelSize: 12
            }
        }

        Button {
            id: button1
            x: 343
            y: 426
            text: qsTr("Create account")
            enabled: true
            hoverEnabled: false
            background: Rectangle {
                color: "#43b05c"
                //radius: roundButton.radius
            }
            flat: false
            font.bold: true
            onClicked: {
                updateItemInfo()
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
            id: suppliertext2
            x: 188
            y: 333
            text: "Password:"
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

        Text {
            id: itemnameText2
            x: 188
            y: 101
            text: "ID:"
            font.pixelSize: 25
            font.bold: false
        }

        Rectangle {
            id: rectangle3
            x: 265
            y: 101
            width: 162
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2
            TextInput {
                id: userIDField
                x: 10
                y: 8
                width: 146
                height: 20
                font.pixelSize: 12
            }
        }

        Text {
            id: text1
            x: 433
            y: 101
            text: qsTr("*")
            font.pixelSize: 12
        }

        Text {
            id: text2
            x: 433
            y: 141
            width: 37
            height: 16
            text: qsTr("*")
            font.pixelSize: 12
        }

        Text {
            id: text3
            x: 603
            y: 333
            width: 37
            height: 16
            text: qsTr("*")
            font.pixelSize: 12
        }

        Text {
            id: text4
            x: 603
            y: 373
            width: 37
            height: 16
            text: qsTr("*")
            font.pixelSize: 12
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
        x: 362
        y: 182
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
            id: pw2Field
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
            id: pwField
            x: 8
            y: 8
            width: 187
            height: 20
            font.pixelSize: 12
            echoMode: TextInput.Password
        }
    }


}
