import QtQuick 2.0

Rectangle {
    width: picture.width; height: picture.height

    Image {
        id: picture
        anchors.centerIn: parent
        source: "../images/tampere.jpg"
    }
}
