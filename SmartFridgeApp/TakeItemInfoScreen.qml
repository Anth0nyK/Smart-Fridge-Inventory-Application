import QtQuick 2.14
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import iteminfo 1.0
import activityLogHelper 1.0
import profileinfo 1.0

Page {
    id: page
    property string itemID
    property string itemPic
    property string currentfridgeID

    property string status
    property string userID

    //property StackView theStack: StackView.view
    width: 780
    height: 585

    ItemHelper{
        id: itemtool
    }

    ActivityLogHelper{
        id: theActivityLogHelper
    }

    ProfileHelper {
        id: theProfileHelper
    }


    function takeItem(){
        if(amountInput.value != 0){
            status = itemtool.takeItem(itemID, amountInput.value)
            if(status == "error"){
                message.text = "Invalid input"
                amountInput.value = 0
                }
            if(status == "tooLarge"){
                message.text = "Amount is larger than the quantity"
                amountInput.value = 0
            }
            if(status == "OK"){
                message.text = "Took out " + amountInput.value + " from the fridge"
                quantity1.visible = false
                quantity2.visible = true
                quantity2.text = qsTr("Quantity: " + itemtool.getItemCount(itemID))
                let action = "Took out " + itemtool.getItemname(itemID) + " x" + amountInput.value
                theActivityLogHelper.createLog(action, theProfileHelper.getUsername(userID), currentfridgeID)
            }
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
                theinventorymodel3.updateinventoryModel()
                quantity1.visible = true
                quantity2.visible = false
                //theinventorymodel2.updateinventoryModel()
            }
        }

        Text {
            id: itemnameText
            x: 25
            y: 21
            text: "Fridge > Open door > Unlocked > Insert item"
            font.pixelSize: 25
            font.bold: false
        }

        Image {
            id: image
            x: 290
            y: 131
            width: 200
            height: 200
            source: itemPic
            fillMode: Image.PreserveAspectFit

            Rectangle {
                id: rectangle1
                x: 92
                y: 300
                width: 123
                height: 32
                color: "#ffffff"
                radius: 4
                border.width: 2

                /*
                TextInput {
                    id: amountInput
                    x: 8
                    y: 8
                    width: 107
                    height: 20
                    font.pixelSize: 12
                }*/

                SpinBox {
                    id: amountInput
                    x: 8
                    y: 4
                    width: 110
                    height: 25
                    from: 0
                }
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
            enabled: {
                amountInput.value > 0;
            }
            flat: false
            font.bold: true
            onClicked: {
                takeItem()
            }
        }


        //QString itemName, QString supplierName, QString alertWhen, QString reorderWhen, QString supplierEmail

        Text {
            id: message
            x: 262
            y: 553
            width: 257
            height: 28
            font.pixelSize: 21
            horizontalAlignment: Text.AlignHCenter
            font.bold: false
        }

        Text {
            id: itemnameText1
            x: 25
            y: 82
            text: "How many did you take out?"
            font.pixelSize: 22
            font.bold: true
        }

        Text {
            id: quantity1
            x: 290
            y: 388
            text: qsTr("Quantity: " + itemtool.getItemCount(itemID))
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: itemnameText3
            x: 290
            y: 337
            text: qsTr("Name: " + itemtool.getItemname(itemID))
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: itemnameText4
            x: 290
            y: 428
            text: "Amount"
            font.pixelSize: 25
            font.bold: false
        }

        Text {
            id: quantity2
            x: 291
            y: 388
            visible: false
            text: qsTr("Quantity: " + itemtool.getItemCount(itemID))
            font.pixelSize: 25
            font.bold: false
        }



    }


}
