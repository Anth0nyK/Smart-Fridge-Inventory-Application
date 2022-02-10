import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import inventorymodel 1.0
import orderDeliverModel 1.0
import iteminfo 1.0
import fridgeHandler 1.0


Page {
    property string userID
    property string currentfridgeID
    property string currentorderID

    width: 780
    height: 585

    ItemHelper{
        id: theitemHelper
    }

    FridgeHandler{
        id: theFridgeHandler
    }


    property int counter

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

    function checkIfconfirm(){
        countItems()
        //getUUID()
        let x = 0
        message.text = ""+ counter
        for (let i = 0; i < counter; i++) {
            //console.log("testing 123:" + gridView.getDelegateInstanceAt(i).needed)
            if(gridView.getDelegateInstanceAt(i).theneeded != 0){

                x = x + 1
            }
        }

        if(x == 0){
            theitemHelper.updateDeliverStatus(currentorderID)
            message.text = "Delivered. Items in order are all delivered"
            theFridgeHandler.updateRearDoorStatus(currentfridgeID,"0")
        }else{
            //theitemHelper.updateDeliverStatus(currentorderID)
            message.text = "Some items are still missing"
        }

    }


    InsertItemInfoScreenForShop {
        id: theInsertItemInfoScreen
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
                text: qsTr("Fridge > Unlocked > Insert item")
                font.pixelSize: 25
            }

            Text {
                id: text2
                x: 25
                y: 82
                text: qsTr("What did you put in?")
                font.pixelSize: 22
                font.bold: true
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
                theinventorymodel.updateinventoryModel()
                theinventorymodel2.updateinventoryModel()
            }
        }

        Button {
        id: button
        x: 330
        y: 538
        width: 120
        height: 26
        text: qsTr("Confirm and Lock")
        background: Rectangle {
            color: "#43b05c"
        }
        hoverEnabled: false
        enabled: true
        flat: false
        font.bold: true
        onClicked: {
            checkIfconfirm()
        }
        }

        GridView {
            id: gridView
            y: 122
            anchors.leftMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right
            contentWidth: 0
            anchors.rightMargin: 20
            clip: true
            height: 410
            cellWidth: 185
            cellHeight: 200
            delegate: ItemDelegate {
                objectName: "summaryDelegate"
                property int index: model.index
                property string theneeded: model.needed
                onClicked: {
                        //console.info("model.itemID = " + model.itemID)
                        thestackView.push(theInsertItemInfoScreen, {itemPic: model.image, itemName: model.itemName, orderID: currentorderID, userID: userID})
                        //thestackView.clear()
                        //thestackView.push("qrc:/chat2.qml", { chatroomHeader: model.GPName, topicID: model.TopicID, senderID: currentUserID})
                }
                x: 5
                width: 150
                height: 200
                Column {

                    Image{
                        id: itemImage
                        width: 150
                        height: 150
                        source: model.image
                        fillMode: Image.PreserveAspectFit
                    }
                    /*
                    Rectangle {
                        width: 150
                        height: 150
                        //color: colorCode
                        radius: 10
                        border.width: 1
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    */
                    Text {
                        x: 5
                        //text: name
                        //text: model.itemName
                        text: qsTr(model.itemName)
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Text {
                        y: 15
                        //text: name
                        //text: model.itemName
                        text: qsTr("Require: " +model.needed)
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                }
            }
            /*
            model: InventoryModel{
                id: theinventorymodel2;
                fridgeID: currentfridgeID
            }
            */
            model: OrderDeliverModel{
                id: theOrderDeliverModel;
                orderID: currentorderID;
            }

            function getDelegateInstanceAt(index) {
                for(var i = 0; i < contentItem.children.length; ++i) {
                    var item = contentItem.children[i];
                    // We have to check for the specific objectName we gave our
                    // delegates above, since we also get some items that are not
                    // our delegates here.
                    if (item.objectName == "summaryDelegate" && item.index == index)
                        return item;
                }
                return undefined;
            }

            Text {
                id: message
                x: 300
                y: 382
                width: 140
                height: 28
                font.pixelSize: 22
                horizontalAlignment: Text.AlignHCenter
            }

        }


    }



}
