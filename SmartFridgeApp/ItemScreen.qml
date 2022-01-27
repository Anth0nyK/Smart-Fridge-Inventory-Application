import QtQuick 2.14
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
//import QtQuick.Controls 1.4 as C1
import Qt.labs.qmlmodels

import itemmodel 1.0
import iteminfo 1.0
import inventorymodel 1.0
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

    ItemSettings{
        id: theitemsettings
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
            id: nametext
            x: 172
            y: 113
            text: qsTr("Item name:")
            font.pixelSize: 20
        }

        Text {
            id: itemnameText
            x: 16
            y: 20
            text: qsTr("Fridge > " + itemtool.getItemname(itemID) )
            font.pixelSize: 25
            font.bold: false
        }

        Image {
            id: image
            x: 16
            y: 113
            width: 133
            height: 135
            source: itemPic
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: suppliertext
            x: 172
            y: 146
            text: qsTr("Supplier:")
            font.pixelSize: 20
        }

        Text {
            id: alerttext
            x: 172
            y: 179
            text: qsTr("Alert when under:")
            font.pixelSize: 20
        }

        Text {
            id: reordertext
            x: 172
            y: 212
            text: qsTr("Re-order when under:")
            font.pixelSize: 20
        }

        Text {
            id: nametext1
            x: 397
            y: 113
            text: qsTr("Quantity:")
            font.pixelSize: 20
        }

        Text {
            id: itemnameField
            x: 277
            y: 113
            text: qsTr(itemtool.getItemname(itemID))
            font.pixelSize: 20
            font.bold: true
        }

        Text {
            id: supplierField
            x: 255
            y: 146
            text: qsTr(itemtool.getSupplierName(itemID))
            font.pixelSize: 20
            font.bold: true
        }

        Text {
            id: alertField
            x: 335
            y: 179
            text: qsTr(itemtool.getAlert(itemID))
            font.pixelSize: 20
            font.bold: true
        }

        Text {
            id: reorderField
            x: 370
            y: 212
            text: qsTr(itemtool.getReorder(itemID))
            font.pixelSize: 20
            font.bold: true
        }

        Text {
            id: quantityField
            x: 483
            y: 113
            text: qsTr(itemtool.getItemCount(itemID))
            font.pixelSize: 20
            font.bold: true
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

        ListView {
            id: listView
            x: 16
            y: 303
            width: 756
            height: 268
            clip: true
            delegate: Item {
                id: item1
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    z: 0
                    anchors.topMargin: 0

                    spacing: 200

                    Text {
                        text: itemDataID
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }

                    Text {
                        text: insertDate
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }

                    Text {
                        text: expiryDate
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                }
            }
            model: ItemModel{
                id: theitemmodel
                theitemID: itemID

            }
        }

        Text {
            id: nametext2
            x: 16
            y: 270
            text: qsTr("No.")
            font.pixelSize: 20
        }

        Text {
            id: nametext3
            x: 222
            y: 270
            text: qsTr("Date inserted")
            font.pixelSize: 20
        }

        Text {
            id: nametext4
            x: 495
            y: 270
            text: qsTr("Expiry date")
            font.pixelSize: 20
        }

        Image {
            id: settingButton
            x: 590
            y: 21
            width: 65
            height: 34
            source: "images/setting.png"

            fillMode: Image.PreserveAspectFit
            MouseArea {
                anchors.fill: parent
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                onClicked: {
                    //console.info("image clicked!")
                    thestackView.push(theitemsettings, {itemID: itemID, itemPic: itemPic})
                    theitemmodel.updateitemModel()
                }
            }
            Text {
                id: sendReportTxt
                x: 12
                y: 29
                text: qsTr("settings")
                font.pixelSize: 12
            }
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
    D{i:0;formeditorZoom:0.9}D{i:1}D{i:3}D{i:4}D{i:5}D{i:6}D{i:7}D{i:8}D{i:9}D{i:10}D{i:11}
D{i:12}D{i:13}D{i:14}D{i:15}D{i:16}D{i:17}D{i:24}D{i:25}D{i:26}D{i:28}D{i:29}D{i:27}
D{i:2}
}
##^##*/
