import QtQuick 1.0

Rectangle {
    width: 400; height: 200; color: "lightblue"

    Rectangle {
        color: "red"
        width: parent.width
        height: 2
        anchors.verticalCenter: parent.verticalCenter
    }
    Image {
        id: book
        source: "../images/book.svg"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -parent.width/4
        anchors.verticalCenter: parent.verticalCenter
    }
    Text {
        text: "Writing"
        font.family: "Helvetica"
        font.pointSize: parent.width/20
        anchors.left: book.right
        anchors.leftMargin: parent.width/16
        anchors.baseline: book.verticalCenter
    }
}
