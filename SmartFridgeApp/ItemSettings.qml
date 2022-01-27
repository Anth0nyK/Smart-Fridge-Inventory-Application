import QtQuick 2.14
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import iteminfo 1.0

Page {
    id: page
    property string itemID
    property string itemPic
    //property StackView theStack: StackView.view
    width: 780
    height: 585

    ItemHelper{
        id: itemtool
    }

    function changeItemPic(){
        if(pictureLink.text != "")
        {
            itemtool.changePicture(itemID,pictureLink.text)
            pictureLink.text = ""
            message.text = "Updated the item picture"
        }
    }

    function updateItemInfo(){
        if(itemnameField.text != "" && supplierField.text != "" && alertField != "" && reorderField.text != "" && emailField.text != ""){
            itemtool.updateItemInfo(itemnameField.text, supplierField.text, alertField.text,reorderField.text, emailField.text, itemID)
            message.text = "Updated the item info"
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
                theinventorymodel.updateinventoryModel()
            }
        }

        Text {
            id: itemnameText
            x: 16
            y: 20
            text: qsTr("Fridge > " + itemtool.getItemname(itemID) + " > Settings" )
            font.pixelSize: 25
            font.bold: false
        }

        Image {
            id: image
            x: 307
            y: 85
            width: 166
            height: 166
            source: itemPic
            fillMode: Image.PreserveAspectFit
        }

        Button {
            id: button
            x: 341
            y: 297
            text: qsTr("Upload a photo")
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
            x: 255
            y: 335
            text: "Item name:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: suppliertext
            x: 60
            y: 375
            text: "Supplier:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: alerttext
            x: 60
            y: 415
            text: "Alert when under:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: reordertext
            x: 60
            y: 455
            text: "Re-order when under:"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: supplieremailField
            x: 384
            y: 375
            text: "Supplier email:"
            font.pixelSize: 25
            font.bold: false
        }

        Rectangle {
            id: rectangle1
            x: 384
            y: 335
            width: 162
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2

            TextInput {
                id: itemnameField
                x: 10
                y: 8
                width: 146
                height: 20
                text: qsTr(itemtool.getItemname(itemID))
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: rectangle2
            x: 162
            y: 375
            width: 162
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2

            TextInput {
                id: supplierField
                x: 8
                y: 8
                width: 146
                height: 20
                text: qsTr(itemtool.getSupplierName(itemID))
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
                updateItemInfo()
            }
        }


        //QString itemName, QString supplierName, QString alertWhen, QString reorderWhen, QString supplierEmail
        Rectangle {
            id: rectangle5
            x: 309
            y: 257
            width: 162
            height: 34
            color: "#ffffff"
            radius: 5
            border.width: 2
            TextInput {
                id: pictureLink
                x: 6
                y: 7
                width: 146
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
            font.pixelSize: 21
            font.bold: false
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
        id: rectangle3
        x: 261
        y: 416
        width: 72
        height: 34
        color: "#ffffff"
        radius: 5
        border.width: 2

        TextInput {
            id: alertField
            x: 8
            y: 8
            width: 56
            height: 20
            text: qsTr(itemtool.getAlert(itemID))
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: rectangle4
        x: 306
        y: 456
        width: 72
        height: 34
        color: "#ffffff"
        radius: 5
        border.width: 2

        TextInput {
            id: reorderField
            x: 8
            y: 8
            width: 56
            height: 20
            text: qsTr(itemtool.getReorder(itemID))
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: rectangle6
        x: 553
        y: 376
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
            text: qsTr(itemtool.getSupplierEmail(itemID))
            font.pixelSize: 12
        }
    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:1}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:9}D{i:10}D{i:11}
D{i:12}D{i:13}D{i:15}D{i:14}D{i:17}D{i:16}D{i:18}D{i:2}D{i:21}D{i:20}D{i:23}D{i:22}
D{i:25}D{i:24}
}
##^##*/
