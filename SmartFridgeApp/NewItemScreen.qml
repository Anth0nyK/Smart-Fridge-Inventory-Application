import QtQuick 2.14
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import iteminfo 1.0

Page {
    id: page
    property string fridgeID
    width: 780
    height: 585

    ItemHelper{
        id: itemtool
    }

    function changeItemPic(){
        if(pictureLink.text != "")
        {
            image.source = pictureLink.text
        }
    }
    //QString itemName, QString fridgeID , QString alertWhen, QString reorderWhen, QString supplierName, QString supplierEmail, QString itemPic
    function createItem(){
        if(itemnameField.text != "" && alertField.text != "" && reorderField.text != "" && supplierField.text != "" && supplieremailField.text != "" && pictureLink.text != ""){
            itemtool.addItem(itemnameField.text, fridgeID, alertField.text, reorderField.text, supplierField.text, supplierField.text, pictureLink.text)
            itemnameField.text = ""
            alertField.text = ""
            reorderField.text = ""
            supplierField.text = ""
            supplieremailField.text = ""
            pictureLink.text = ""
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
                thestackView.pop()
                theinventorymodel.updateinventoryModel()
            }
        }

        Text {
            id: itemnameText
            x: 16
            y: 20
            text: qsTr("Fridge > Add new item" )
            font.pixelSize: 25
            font.bold: false
        }

        Image {
            id: image
            x: 307
            y: 85
            width: 166
            height: 166
            source: "https://cdn-icons-png.flaticon.com/512/1160/1160358.png"
            fillMode: Image.PreserveAspectFit
        }

        Button {
            id: button
            x: 347
            y: 297
            text: qsTr("Test a picture")
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
                font.pixelSize: 12
            }
        }

        Button {
            id: button1
            x: 349
            y: 507
            width: 83
            height: 26
            text: qsTr("Add")
            enabled: true
            hoverEnabled: false
            background: Rectangle {
                color: "#43b05c"
                //radius: roundButton.radius
            }
            flat: false
            font.bold: true
            onClicked: {
                createItem()
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
            font.pixelSize: 12
        }
    }


}
