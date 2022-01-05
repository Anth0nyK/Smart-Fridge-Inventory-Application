import QtQuick 2.4
import QtQuick.Window 2.12
import QtQuick.Controls 2.3


Page {
    property string userID
    property string userImage
    width: 780
    height: 680

    Rectangle {

        anchors.fill: parent

        color: "#eeeeec"
        anchors.rightMargin: -1
        anchors.leftMargin: 1
        anchors.topMargin: 0
        //anchors.bottomMargin: -54

        Text {
            id: element
                x: 213
                y: 258
                width: 60
                height: 21
                text: qsTr("Username:")
                font.bold: true
                font.pixelSize: 16
            }

            TextField {
                id: usernameField
                x: 311
                y: 254
                width: 93
                height: 27
            }

            Button {
                id: saveUserID
                x: 485
                y: 254
                enabled: usernameField.length > 0
                text: qsTr("SAVE")
                font.bold: true
                background: Rectangle {
                    radius: 5
                    color: "grey"
                }
                onClicked: {
                    profilehelper.changeUsername(userID,usernameField.text)
                    usernameField.text = "";
                    message.text = "Updated, please login again"
                }
            }


            Text {
                id: element1
                x: 234
                y: 215
                text: qsTr("YourID: " + userID)
                font.bold: true
                font.pixelSize: 16
            }

            Text {
                id: element2
                x: 253
                y: 66
                text: qsTr("Your Profile")
                font.pixelSize: 25
            }

            Image {
                id: image
                x: 271
                y: 101
                width: 100
                height: 100
                fillMode: Image.PreserveAspectFit
                source: userImage
            }

            Text {
                id: element3
                x: 173
                y: 303
                width: 121
                height: 21
                text: qsTr("Profile picture:")
                font.pixelSize: 16
                font.bold: true
            }

            TextField {
                id: pictureField
                x: 311
                y: 300
                width: 93
                height: 27
            }

            Button {
                id: savepicture
                x: 485
                y: 299
                text: qsTr("SAVE")
                enabled: pictureField.length > 0
                background: Rectangle {
                    color: "#808080"
                    radius: 5
                }
                font.bold: true
                onClicked: {
                    profilehelper.changePicture(userID,pictureField.text)
                    pictureField.text = ""
                    message.text = "Updated, please login again"
                }
            }

            Text {
                id: element4
                x: 213
                y: 344
                width: 81
                height: 21
                text: qsTr("Password:")
                font.pixelSize: 16
                font.bold: true
            }

            TextField {
                id: pwField
                x: 311
                y: 341
                width: 93
                height: 27
            }

            Button {
                id: savepw
                x: 485
                y: 340
                text: qsTr("SAVE")
                enabled: pwField.length > 0
                background: Rectangle {
                    color: "#808080"
                    radius: 5
                }
                font.bold: true
                onClicked: {
                    profilehelper.changePW(userID,pwField.text)
                    pwField.text = ""
                    message.text = "Updated, please login again"
                }
            }

            Text {
                id: element5
                x: 410
                y: 303
                width: 60
                height: 21
                text: qsTr("(link)")
                font.pixelSize: 16
                font.bold: true
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

        }

}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.5;height:480;width:640}D{i:2}D{i:3}D{i:4}D{i:6}
D{i:7}D{i:8}D{i:9}D{i:10}D{i:11}D{i:13}D{i:14}D{i:15}D{i:17}D{i:18}D{i:1}
}
##^##*/
