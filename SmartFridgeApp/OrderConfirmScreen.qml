import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3


Page {

    width: 780
    height: 585

    property string uuid
    property string supplierName

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
            id: message
            x: 241
            y: 417
            width: 159
            height: 23
            font.pixelSize: 20
            text:""
        }

            Image {
                id: image
                x: 240
                y: 143
                width: 300
                height: 300
                source: "images/order.png"
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: text1
                x: 270
                y: 446
                text: qsTr("Order confirmed")
                font.pixelSize: 30
                horizontalAlignment: Text.AlignHCenter
                font.bold: false
            }

            Text {
                id: text2
                x: 337
                y: 492
                width: 87
                height: 27
                text: qsTr("Order ID: #" + uuid)
                font.pixelSize: 15
                horizontalAlignment: Text.AlignHCenter
                font.bold: false
            }

            Text {
                id: text3
                x: 292
                y: 519
                text: qsTr(supplierName + " will contact you very soon")
                font.pixelSize: 15
                horizontalAlignment: Text.AlignHCenter
                font.bold: false
            }

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


}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:2}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:1}
}
##^##*/
