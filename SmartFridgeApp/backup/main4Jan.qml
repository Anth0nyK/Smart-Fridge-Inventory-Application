import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
//import contact 1.0
//import group 1.0
//import MqttClient 1.0
//import backend 1.0
//import sendMessage 1.0
//import urlhelper 1.0
//import profileinfo 1.0

Window {
    id: mainscreen
    visible: true
    width: 840
    height: 680

    property string currentUserName
    property string currentUserID


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


    Rectangle {
        id: root
        color: "#555753"
        anchors.fill: parent
    }

    Rectangle {
        id: userArea
        color: "#d3d3d3"
        width: parent.width*0.25
        height: parent.height/7
        anchors.bottom: root.bottom
        anchors.left: root.left

        Rectangle {
            id: rectangle
            anchors.centerIn: userArea
            width: parent.width * 0.8
            height: parent.height * 0.8
            color: "light grey"

            Image {
                id: image
                anchors.top: rectangle.top
                anchors.left: rectangle.left

                width: parent.height*0.5
                height: parent.height*0.5
                //source: profilehelper.getImage(currentUserID)
                source: ""
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: loggedInAs
                //text: "User: " + profilehelper.getUsername(currentUserID)
                text: "User"
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
        color: "grey"
        height: contactarea.height*0.1
        width: contactarea.width
        anchors.top: contactarea.top
        anchors.left: contactarea.left



        ToolBar {
            id: toolBar
            anchors.fill: parent
            Label {
                id: toplabel
                text: qsTr("Contacts")
                font.pixelSize: 15
                font.bold: true
                anchors.centerIn: parent
            }
        }
    }

    Rectangle {
        id: contactareaview
        color: "white"
        height: contactarea.height*0.9
        width: contactarea.width
        anchors.bottom: contactarea.bottom
        anchors.left: contactarea.left



/*
        ListView {
            objectName: "testlistview"
            clip: true
            id: thelistView
            anchors.fill: parent
            spacing: 20

            delegate: ItemDelegate {
                onClicked: {
                    if(loadCT == true){
                        thestackView.clear()
                        thestackView.push("qrc:/chat.qml", { chatroomHeader: model.UserName, topicID: model.TopicID, senderID: currentUserID})
                    }
                    else{
                        thestackView.clear()
                        thestackView.push("qrc:/chat2.qml", { chatroomHeader: model.GPName, topicID: model.TopicID, senderID: currentUserID})
                    }
                }

                x: 10
                width: parent.width
                height: contactareaview.height / 8

                Row {
                    id: row2

                    anchors.verticalCenter: parent.verticalCenter


                    Rectangle {
                        width: 60
                        height: width
                        color: "white"

                        Image {
                            id: listImage
                            width: parent.width
                            height: parent.height
                            source: loadCT ? model.Image : model.Picture
                            fillMode: Image.PreserveAspectFit
                        }
                    }


                    Text {
                        text: loadCT ? model.UserName : model.GPName
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                    spacing: 10
                }
            }
            model: loadCT ? thetestContactmodel : thetestContactmodel2
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
        color: "grey"
        width: chatarea.width
        height: chatarea.height
        anchors.top: chatarea.top
        anchors.left: chatarea.left

        StackView {
            id: thestackView
            anchors.fill: parent
        }

        RoundButton {
            anchors.right: parent.right
            //anchors.verticalCenter: parent.verticalCenter
            anchors.top: parent.top

            id: roundButton
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
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:2}D{i:3}D{i:6}D{i:7}D{i:8}D{i:9}D{i:5}D{i:4}D{i:10}
D{i:13}D{i:12}D{i:11}D{i:14}D{i:15}D{i:17}D{i:18}D{i:16}
}
##^##*/
