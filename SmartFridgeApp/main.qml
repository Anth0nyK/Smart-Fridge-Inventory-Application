import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
//import contact 1.0
//import group 1.0
//import MqttClient 1.0
//import backend 1.0
//import sendMessage 1.0
//import urlhelper 1.0
import profileinfo 1.0
import noticeHelper 1.0

Window {
    id: mainscreen
    visible: true
    //width: 840
    width: 1040
    maximumWidth: 1040
    minimumWidth: 1040
    //680 height
    height: 585
    maximumHeight: 585
    minimumHeight: 585

    property string currentUserName
    property string currentUserID
    property string fridgeID
    property int accountType
    property int isAdmin
    //property bool forRestaurant: true
    readonly property bool forRestaurant: accountType == 1
    //property string noticeImg: "images/bell.png"

    function checkNotice(){
        let x = 0
        x = theNoticeHelper.getNoticeStatus(currentUserID)
        if(x == 1){
            bellIMG.source = "images/bell2.png"
        }else{
            bellIMG.source = "images/bell.png"
        }
    }

    function loadFridgeScreen(){
        if (accountType == "1"){
            thestackView.push("qrc:/FridgeInventory.qml" , {currentfridgeID: fridgeID, userID: currentUserID })
        }else{
            thestackView.push("qrc:/FridgeInventoryForShop.qml" , {currentfridgeID: fridgeID, userID: currentUserID })
        }
    }

    function checkIfForRestaurant(){
        if(accountType == "1"){
            return true
        }else{
            return false
        }
    }

    NoticeHelper{
        id: theNoticeHelper
    }

    FridgeInventory{
        id: fridgeInvScreen
    }

    EditProfile{
        id: profilepage
    }

    ProfileHelper{
        id: profilehelper
    }


    Timer {
        interval: 3000
        running: true
        repeat: true
        onTriggered: checkNotice()
    }

    /*
    TextField {
        visible: false
        id: hostname
        text: "127.0.0.1"
    }

    TextField {
        visible: false
        id: portname
        text: "1883"
    }
*/

    Rectangle {
        id: root
        color: "#555753"
        anchors.fill: parent
    }

    Rectangle {
        id: userArea
        color: "#eeeeee"
        border.color: "#bababa"
        border.width: 2
        width: parent.width*0.25
        height: parent.height/7
        anchors.bottom: root.bottom
        anchors.left: root.left

        Rectangle {
            id: rectangle
            anchors.centerIn: userArea
            width: parent.width * 0.8
            height: parent.height * 0.8
            color: "#eeeeee"

            Image {
                id: image
                anchors.top: rectangle.top
                anchors.left: rectangle.left

                width: parent.height*0.5
                height: parent.height*0.5
                source: profilehelper.getImage(currentUserID)
                //source: ""
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: loggedInAs

                //text: "User: " + profilehelper.getUsername(currentUserID)
                text: qsTr("User: " + currentUserName)
                anchors.left: image.right
                anchors.verticalCenter: image.verticalCenter
                font.pixelSize: 12
            }

            Button {
                id: logoutbtn
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                width: parent.width * 0.45
                height: parent.height * 0.28
                text: qsTr("LOOUT")
                onClicked: {
                    mainscreen.hide()
                    loginscreen.show()
                }
            }

            Button {
                id: settingbtn
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                width: parent.width * 0.45
                height: parent.height * 0.28
                text: qsTr("PROFILE")
                onClicked: {
                    thestackView.clear()
                    //thestackView.push("qrc:/editProfile.qml", { userID: currentUserID, userImage: profilehelper.getImage(currentUserID)})

                    thestackView.push(profilepage, {currentUserID: currentUserID, currentfridgeID: fridgeID})
                    //thestackView.push("qrc:/editProfile.qml")
                }
            }


        }
    }

    Rectangle {
        id: contactarea
        color: "white"
        width: parent.width*0.25
        height: parent.height*0.85
        anchors.left: root.left
        anchors.top: root.top
    }

    Rectangle {
        id: contactareaheader
        color: "#eeeeee"
        border.color: "#bababa"
        height: contactarea.height*0.15
        width: contactarea.width
        anchors.top: contactarea.top
        anchors.left: contactarea.left


/*
        ToolBar {
            id: toolBar
            anchors.fill: parent
            Label {
                id: toplabel
                //text: qsTr("Contacts")
                font.pixelSize: 15
                font.bold: true
                anchors.centerIn: parent
            }
        }
        */

    }

    Rectangle {
        id: contactareaview
        color: "white"
        border.color: "#d8d8d8"
        border.width: 2
        height: contactarea.height*0.85
        width: contactarea.width
        anchors.bottom: contactarea.bottom
        anchors.left: contactarea.left

        Image {
            id: fridgeIMG
            x: 8
            y: 8
            width: 50
            height: 50
            source: "images/fridge.png"
            fillMode: Image.PreserveAspectFit
            MouseArea {
                anchors.fill: parent
                anchors.rightMargin: -186
                anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            onClicked: {
                thestackView.clear()
                loadFridgeScreen()
            }
            }
            Text {
                id: text6
                x: 56
                y: 12
                text: qsTr("Fridge")
                font.pixelSize: 20
            }
        }



        Image {
            id: orderIMG
            x: 8
            y: 74
            width: 50
            height: 50
            visible: checkIfForRestaurant()
            source: "images/orders.png"
            fillMode: Image.PreserveAspectFit
            MouseArea {
            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.bottomMargin: 0
            anchors.rightMargin: -186
            anchors.topMargin: 0
            onClicked: {
                thestackView.clear()
                thestackView.push("qrc:/Orders.qml" , {currentfridgeID: fridgeID, userID: currentUserID })
              }
            }
        }

        Text {
            id: text7
            x: 64
            y: 86
            visible: checkIfForRestaurant()
            text: qsTr("Orders")
            font.pixelSize: 20
        }

        Image {
            id: logIMG
            x: 10
            y: 140
            width: 50
            height: 50
            visible: checkIfForRestaurant()
            source: "images/history.png"
            fillMode: Image.PreserveAspectFit
            MouseArea {
            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.bottomMargin: 0
            anchors.rightMargin: -186
            anchors.topMargin: 0
            onClicked: {
                thestackView.clear()
                thestackView.push("qrc:/ActivityLog.qml" , {currentfridgeID: fridgeID, userID: currentUserID })
            }
            }
        }

        Text {
            id: text8
            x: 64
            y: 152
            visible: checkIfForRestaurant()
            text: qsTr("Activity log")
            font.pixelSize: 20
        }

        Image {
            id: bellIMG
            x: 8
            y: 207
            width: 50
            height: 50
            visible: checkIfForRestaurant()
            source: "images/bell.png"
            fillMode: Image.PreserveAspectFit
            MouseArea {
            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.bottomMargin: 0
            anchors.rightMargin: -186
            anchors.topMargin: 0
            onClicked: {
                thestackView.clear()
                thestackView.push("qrc:/Notifications.qml" , {currentfridgeID: fridgeID, userID: currentUserID })
                theNoticeHelper.resetNotice(currentUserID)
            }
            }
        }

        Text {
            id: text9
            x: 64
            y: 219
            visible: checkIfForRestaurant()
            text: qsTr("Notifications")
            font.pixelSize: 20
        }

        Image {
            id: peopleIMG
            x: 8
            y: 274
            width: 50
            height: 50
            visible: checkIfForRestaurant()
            source: "images/people.png"
            fillMode: Image.PreserveAspectFit
            MouseArea {
            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.bottomMargin: 0
            anchors.rightMargin: -186
            anchors.topMargin: 0
            onClicked: {
                thestackView.clear()
                thestackView.push("qrc:/ManagementScreen.qml" , {currentfridgeID: fridgeID, userID: currentUserID })
            }
            }
        }

        Text {
            id: text10
            x: 64
            visible: checkIfForRestaurant()
            y: 286
            text: qsTr("Management")
            font.pixelSize: 20
        }


/*
    ListView {
        objectName: "testlistview"
        clip: true
        id: thelistView
        anchors.fill: parent
        anchors.bottomMargin: 8
        anchors.topMargin: 8
        anchors.leftMargin: 8
        anchors.rightMargin: 8
        spacing: 20

        delegate: ItemDelegate {
            onClicked: {
                    thestackView.clear()
                    thestackView.push(model.link , {currentfridgeID: fridgeID, userID: currentUserID })
                    //thestackView.push("qrc:/chat2.qml", { chatroomHeader: model.GPName, topicID: model.TopicID, senderID: currentUserID})
            }

            x: 10
            width: parent.width
            height: contactareaview.height / 8

            Row {
                id: row2

                anchors.verticalCenter: parent.verticalCenter


                Rectangle {
                    width: 60
                    //height: width
                    height: 60
                    //color: "white"
                    //color: model.colorCode

                    Image {
                        id: listImage
                        width: parent.width - 10
                        height: parent.height - 10
                        //source: loadCT ? model.Image : model.Picture
                        source: model.icon
                        fillMode: Image.PreserveAspectFit
                    }
                }


                Text {
                    //text: loadCT ? model.UserName : model.GPName
                    text: model.name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                spacing: 10
            }
        }
        model: ListModel {
                ListElement {
                    name: "Fridge"
                    icon: "images/fridge.png"
                    link: "qrc:/FridgeInventory.qml"
                    //link: fridgeInvScreen
                }

                ListElement {
                    name: "Orders"
                    icon: "images/orders.png"
                    link: "qrc:/Orders.qml"
                }

                ListElement {
                    name: "History"
                    icon: "images/history.png"
                    link: "qrc:/ActivityLog.qml"
                }

                ListElement {
                    name: "Notifications"
                    icon: "images/bell.png"
                    //icon: checkNotice()
                    link: "qrc:/Notifications.qml"
                }
                ListElement{
                    name: "Management"
                    icon: "images/people.png"
                    link: "qrc:/ManagementScreen.qml"
                }
            }

    }
*/



    }

    Rectangle{
        id: chatarea
        color: "#fcfc7f"
        width: parent.width*0.75
        height: parent.height
        anchors.right: root.right
        anchors.top: root.top
    }

    Rectangle{
        id: chatareaview
        color: "#fefefe"
        width: chatarea.width
        height: chatarea.height
        anchors.top: chatarea.top
        anchors.left: chatarea.left




        Text {
            id: text1
            x: 164
            y: 206
            width: 453
            height: 107
            text: qsTr("Smart Fridge")
            font.pixelSize: 80
            font.bold: false
        }

        Text {
            id: text2
            x: 623
            y: 206
            text: qsTr("TM")
            font.pixelSize: 30
            font.bold: true
        }

        Text {
            id: text3
            x: 519
            y: 319
            text: qsTr("By Future Fridges")
            font.pixelSize: 20
        }

        Text {
            id: text4
            x: 657
            y: 552
            text: qsTr("+44 1234 123456")
            font.pixelSize: 15
        }

        Image {
            id: phoneimage
            x: 628
            y: 547
            width: 30
            height: 30
            source: "images/phone.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image1
            x: 78
            y: 220
            width: 80
            height: 80
            source: "images/bulb.png"
            fillMode: Image.PreserveAspectFit
        }

        StackView {
            id: thestackView
            //initialItem: stackView
            anchors.fill: parent

            popEnter: Transition {
                      PropertyAnimation{
                          property: "opacity"
                          from: 0
                          to: 1
                          duration: 1
                      }
                  }

              popExit: Transition {
                  PropertyAnimation{
                      property: "opacity"
                      from: 1
                      to: 0
                      duration: 1
                  }
              }

              pushEnter: Transition {
                        PropertyAnimation{
                            property: "opacity"
                            from: 0
                            to: 1
                            duration: 1
                        }
              }

              pushExit: Transition {
                  PropertyAnimation{
                      property: "opacity"
                      from: 1
                      to: 0
                      duration: 1
                  }
              }

              Image {
                  id: icon
                  x: 340
                  y: 393
                  width: 100
                  height: 100
                  source: forRestaurant ? "images/forRest.png" : "images/forShop.png"
              }

              Text {
                  id: text5
                  x: 196
                  y: 499
                  width: 388
                  height: 16
                  text: forRestaurant ? qsTr("For restaurants") : qsTr("For delivery")
                  //text: qsTr(forRestaurant.toString())
                  font.pixelSize: 12
                  horizontalAlignment: Text.AlignHCenter
              }
            }


        RoundButton {
            anchors.right: parent.right
            //anchors.verticalCenter: parent.verticalCenter
            anchors.top: parent.top
            anchors.topMargin: 18
            anchors.rightMargin: 8

            id: roundButton
            x: 840
            text: "X"
            font.bold: true
            onClicked: {
                thestackView.clear()
            }
        }
    }



}






/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:2}D{i:3}D{i:4}D{i:5}D{i:6}D{i:9}D{i:10}D{i:11}
D{i:12}D{i:8}D{i:7}D{i:13}D{i:14}D{i:17}D{i:18}D{i:16}D{i:20}D{i:19}D{i:21}D{i:23}
D{i:22}D{i:24}D{i:26}D{i:25}D{i:27}D{i:29}D{i:28}D{i:30}D{i:15}D{i:31}D{i:33}D{i:34}
D{i:35}D{i:36}D{i:37}D{i:38}D{i:48}D{i:49}D{i:39}D{i:50}D{i:32}
}
##^##*/
