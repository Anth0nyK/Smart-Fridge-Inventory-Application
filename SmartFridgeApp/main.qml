import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 6.2

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        id: button
        x: 307
        y: 404
        text: qsTr("Button")
    }
}
