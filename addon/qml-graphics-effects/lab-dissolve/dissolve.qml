import QtQuick 2.0

Rectangle {
    width: picture.width; height: picture.height

    Image {
        id: picture
        anchors.centerIn: parent
        source: "../images/tampere.jpg"
    }

    // Hint: For help you can look at the commented shader
    // code in shader-extract-hint.qml
}
