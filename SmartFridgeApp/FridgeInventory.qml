import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import inventorymodel 1.0

Page {
    property string userID
    property string userImage
    property string currentfridgeID
    //property StackView theStack: StackView.view
    property int counter

    width: 780
    height: 585

    ItemScreen{
        id: theItemScreen
    }

    NewItemScreen{
        id: theNewItemScreen
    }

    OpenDoorScreen{
        id: theoOpenDoorScreen
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

            Image {
                id: mailButton
                x: 450
                y: 21
                width: 65
                height: 34
                source: "images/mail.png"

                fillMode: Image.PreserveAspectFit
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.info("image clicked!")
                    }
                }
                Text {
                    id: sendReportTxt
                    x: 1
                    y: 27
                    text: qsTr("Send report")
                    font.pixelSize: 12
                }
            }

            Image {
                id: peopleButton
                x: 520
                y: 21
                width: 65
                height: 34
                source: "images/people.png"

                fillMode: Image.PreserveAspectFit
                MouseArea {
                    anchors.fill: parent
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    onClicked: {
                        console.info("image clicked!2")
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

            Image {
                id: unlockButton
                x: 590
                y: 21
                width: 65
                height: 34
                source: "images/lock.png"

                fillMode: Image.PreserveAspectFit
                MouseArea {
                    anchors.fill: parent
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    onClicked: {
                        //console.info("image clicked!3")
                        thestackView.push(theoOpenDoorScreen, {fridgeID: currentfridgeID, userID: currentUserID})
                    }
                }
                Text {
                    id: unlockButtonTxt
                    x: 1
                    y: 27
                    text: qsTr("Open door")
                    font.pixelSize: 12
                }
            }

            Text {
                id: text3
                x: 25
                y: 61
                text: ""
                font.pixelSize: 25
            }

            Button {
                id: button
                x: 368
                y: 26
                text: qsTr("test")
                onClicked: {
                          //testing()
                        countItems()
                      }
            }
        }

        GridView {
            id: gridView
            y: 97
            anchors.leftMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right
            contentWidth: 0
            anchors.rightMargin: 20
            clip: true
            height: 473
            cellWidth: 185
            cellHeight: 200
            delegate: ItemDelegate {
                objectName: "summaryDelegate"
                property int index: model.index
                property string itemName: amountInput.text
                onClicked: {
                        //console.info("model.itemID = " + model.itemID)
                        thestackView.push(theItemScreen, {itemID: model.itemID, itemPic: model.itemPic})
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
                        text: qsTr(model.itemName + " x" +model.itemCount + "asd: " + itemName )
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

                        TextInput{
                            id: amountInput
                            x: 8
                            y: 8
                            width: 146
                            height: 20
                            font.pixelSize: 12
                        }
                    }


                }
            }
            model: InventoryModel{
                id: theinventorymodel;
                fridgeID: currentfridgeID
            }

            RoundButton {
                id: roundButton
                x: 680
                y: 388
                width: 60
                height: 60
                text: "+"
                checked: false
                checkable: true
                flat: true
                highlighted: true
                font.pointSize: 15
                font.bold: true
                background: Rectangle {
                    radius: roundButton.radius
                    color: "#43b05c"
                }
                onClicked: {
                    thestackView.push(theNewItemScreen, {fridgeID: currentfridgeID})
                }
            }

            Text {
                id: text2
                x: 684
                y: 448
                width: 53
                height: 17
                color: "#43b05c"
                text: qsTr("New item")
                font.pixelSize: 12
                font.bold: true
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



/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:2}D{i:3}D{i:6}D{i:8}D{i:9}D{i:7}D{i:11}D{i:12}
D{i:10}D{i:14}D{i:15}D{i:13}D{i:16}D{i:17}D{i:5}D{i:26}D{i:28}D{i:18}D{i:4}
}
##^##*/
