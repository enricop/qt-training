import QtQuick 1.0

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
        Image {
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            source: "../images/rocket.svg"
            scale: 0.4
        }
        Text {
            anchors.left: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            text: "Launch"
            font.pixelSize: 32
        }
    }

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        width: 350; height: 75
        color: Qt.rgba(0.5,0.5,0.5,0.5)
        radius: 10
        Image {
            anchors.left: parent.left
            anchors.leftMargin: 30
            anchors.verticalCenter: parent.verticalCenter
            source: "../images/clear.svg"
        }
        Text {
            anchors.left: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            text: "Cancel"
            font.pixelSize: 32
        }
    }
}
