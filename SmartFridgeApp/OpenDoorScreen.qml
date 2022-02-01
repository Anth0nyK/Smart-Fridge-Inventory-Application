import QtQuick 2.14
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import fridgeHandler 1.0

Page {
    id: page
    property string fridgeID
    property string userID
    width: 780
    height: 585

    UnlockedScreen{
        id: theUnlockedScreen
    }

    FridgeHandler{
        id: theFridgeHandler
    }


    function openFridge(){
        if(theFridgeHandler.getDoorStatus(fridgeID) == "OK"){
            message.text = ""
            thestackView.push(theUnlockedScreen, {fridgeID: fridgeID, userID: userID})
        }
        else{
            message.text = "Doors of the fridge are not all closed"
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
            text: "Fridge > Open door"
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
            id: borderImage
            x: 290
            y: 193
            width: 200
            height: 200
            source: "images/lockBig.png"
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                onClicked: {
                    //console.info("image clicked!3")
                    openFridge()
                }
            }

        }

        Text {
            id: itemnameText1
            x: 352
            y: 383
            text: "Unlock"
            font.pixelSize: 25
            font.bold: false
        }



    }


}
