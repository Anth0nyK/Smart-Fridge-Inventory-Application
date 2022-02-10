import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import login 1.0
import profileinfo 1.0
import permissionHelper 1.0

Window {
    width: 700
    height: 500
    visible: true
    minimumWidth: 700
    minimumHeight: 500
    maximumHeight: 500
    maximumWidth: 700
    id: loginscreen

    property string userID
    property string fridgeID
    property string username
    property int accountType
    property int isAdmin

    LoginClass {
        id: logintool
    }

    ProfileHelper{
        id: profiletool
    }

    PermissionHelper{
        id: thePermissionHelper
    }

    function addPin() {
        console.log("")
        thetestContactmodel.updateModel();
    }

    function loginToAccount()
    {
        userID = logintool.loginToAccount(idField.text, pwField.text)

        console.log("userID = " + userID)

        if(userID == "Account does not exist.")
        {
            pwField.text = ""
        }
        else
        {
            fridgeID = profiletool.getFridgeID(userID)
            username = profiletool.getUsername(userID)
            accountType = profiletool.getAccountType(userID)
            isAdmin = thePermissionHelper.checkIfAdmin(userID)
            var component = Qt.createComponent("main.qml");
            var win = component.createObject(loginscreen,{currentUserID: userID,currentUserName: username, fridgeID: fridgeID, accountType: accountType, isAdmin: isAdmin});
            win.show();
            loginscreen.hide();
        }
    }

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent


        Rectangle {
            id: frame
            x: 163
            y: 290
            width: 376
            height: 175
            radius: 20
            color: "lightgrey"

            /*
            TextField {
                id: idField
                //text: qsTr("101")
                x: 144
                y: 34
                width: 180
                height: 25
            }
            */
            /*
            TextInput {
                id: pwField
                //text: qsTr("123")
                echoMode: TextInput.Password
                x: 144
                y: 83
                width: 180
                height: 22
            }
*/

            Text {
                id: userIDtext
                x: 31
                y: 26
                width: 107
                height: 40
                text: qsTr("UserID")
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 18
            }


            Text {
                id: userPWtext
                x: 31
                y: 75
                width: 107
                height: 40
                text: qsTr("Password")
                horizontalAlignment: Text.AlignLeft
                font.bold: true
                font.pixelSize: 18
                verticalAlignment: Text.AlignVCenter
            }






            Button {
                id: loginbutton
                x: 138
                y: 134
                width: 100
                height: 29
                text: qsTr("LOGIN")
                enabled: {
                    idField.length > 0;
                    pwField.length > 0;
                }
                background: Rectangle {
                    radius: 5
                    color: "#08b0e5"
                }

                onClicked: {loginToAccount()}
            }

            Rectangle {
                id: rectangle1
                x: 144
                y: 85
                width: 180
                height: 21
                color: "#ffffff"

                TextInput {
                    id: pwField
                    //text: qsTr("123")
                    echoMode: TextInput.Password
                    x: 8
                    y: 1
                    width: 164
                    height: 20
                    //text: qsTr("Text Input")
                    font.pixelSize: 12
                }

            }

            Rectangle {
                id: rectangle2
                x: 144
                y: 36
                width: 180
                height: 21
                color: "#ffffff"

            TextInput {
                id: idField
                x: 8
                y: 1
                width: 164
                height: 20
                //text: qsTr("Text Input")
                font.pixelSize: 12
                }
            }
        }

        Text {
            id: text1
            x: 126
            y: 102
            width: 449
            height: 137
            text: qsTr("Smart Fridge")
            font.pixelSize: 70
            horizontalAlignment: Text.AlignHCenter
            font.styleName: "Italic"
            font.family: "Verdana"

            Text {
                id: text2
                x: 367
                y: 96
                width: 90
                height: 18
                text: qsTr("By Future Fridges")
                font.pixelSize: 12
                font.bold: true
            }
        }

        Text {
            id: text3
            x: 561
            y: 102
            text: qsTr("TM")
            font.pixelSize: 12
            font.bold: true
        }

        Image {
            id: image
            x: 49
            y: 102
            width: 80
            height: 75
            source: "images/bulb.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image1
            x: 580
            y: 472
            width: 25
            height: 25
            source: "images/phone.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: text4
            x: 606
            y: 476
            text: qsTr("+44 1234 123456")
            font.pixelSize: 12
        }
    }




}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33}D{i:1}D{i:4}D{i:5}D{i:6}D{i:9}D{i:8}D{i:11}D{i:10}D{i:3}
D{i:13}D{i:12}D{i:14}D{i:15}D{i:16}D{i:17}D{i:2}
}
##^##*/
