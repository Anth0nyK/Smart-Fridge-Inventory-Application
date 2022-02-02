import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import orderitemsmodel 1.0
import orderHelper 1.0

Page {
    property string userID
    property string currentfridgeID
    //property StackView theStack: StackView.view
    property string currentsupplierName
    property string currentsupplierEmail

    property int counter
    property string uUID
    property int done: 0

    width: 780
    height: 585

    OrderHelper{
        id: theOrderHelper
    }

    OrderConfirmScreen{
        id: theOrderConfirmScreen
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

    function getUUID(){
        uUID = theOrderHelper.getUUID()
    }


    function createOrder(){
        countItems()
        getUUID()
        let x = 0


        for (let i = 0; i < counter; i++) {
            x = x + theOrderHelper.addItemToOrder(uUID, gridView.getDelegateInstanceAt(i).itemName, gridView.getDelegateInstanceAt(i).itemCount)
        }
        if(x > 0){
            theOrderHelper.createOrder(uUID,currentfridgeID,currentsupplierName,currentsupplierEmail)
        }

        done = x
    }

    function checkIfDone(){
        if(done != 0){
            thestackView.push(theOrderConfirmScreen, {uuid: uUID, supplierName: currentsupplierName})
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
                text: qsTr("Orders > Select supplier >" + currentsupplierName)
                font.pixelSize: 25
            }

            Text {
                id: text3
                x: 25
                y: 79
                text: qsTr("What do you want to order in " + currentsupplierName + "?")
                font.pixelSize: 22
            }

        }


        GridView {
            id: gridView
            y: 118
            anchors.leftMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right
            contentWidth: 0
            anchors.rightMargin: 20
            clip: true
            height: 409
            cellWidth: 185
            cellHeight: 200
            delegate: ItemDelegate {
                objectName: "summaryDelegate"
                property int index: model.index
                property string itemCount: amountInput.value
                property string itemName: model.itemName
                /*
                onClicked: {
                        //console.info("model.itemID = " + model.itemID)
                        thestackView.push(theItemScreen, {itemID: model.itemID, itemPic: model.itemPic})
                        //thestackView.clear()
                        //thestackView.push("qrc:/chat2.qml", { chatroomHeader: model.GPName, topicID: model.TopicID, senderID: currentUserID})
                }*/
                x: 5
                width: 150
                height: 200
                Column {

                    Image{
                        id: itemImage
                        width: 150
                        height: 150
                        source: model.itemPic
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
                        id: itemText
                        //text: name
                        //text: model.itemName
                        //text: qsTr(model.itemName + " x" +model.itemCount + "asd: " + itemName )
                        text: qsTr(model.itemName)
                        font.bold: true
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Rectangle {
                        id: rectangle2
                        x: 0
                        y: 375
                        width: 162
                        height: 34
                        color: "#ffffff"
                        radius: 5
                        border.width: 2
                        /*
                        TextInput{
                            id: amountInput
                            x: 8
                            y: 8
                            width: 146
                            height: 20
                            font.pixelSize: 12
                        }
                        */
                        SpinBox {
                            id: amountInput
                            x: 8
                            y: 8
                            width: 146
                            height: 20
                            from: 0
                            font.pointSize: 12
                        }
                    }


                }
            }
            model: OrderItemsModel{
                id: theOrderItemsModel
                fridgeID: currentfridgeID
                supplierName: currentsupplierName
                supplierEmail: currentsupplierEmail
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
                thesuppliermodel.updatesupplierModel()
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
                createOrder()
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
