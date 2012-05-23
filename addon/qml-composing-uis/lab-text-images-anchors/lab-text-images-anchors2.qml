import QtQuick 2.0

Rectangle {
    width: 400; height: 200

    Image {
        source: "../images/background.png"
    }

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 15
        width: 350; height: 75
        color: Qt.rgba(1.0,0.25,0.25,0.5)
        radius: 10
    }

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        width: 350; height: 75
        color: Qt.rgba(0.5,0.5,0.5,0.5)
        radius: 10
    }
}
