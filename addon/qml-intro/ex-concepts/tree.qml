import QtQuick 1.0

Rectangle {
    width: 200; height: 200
    color: "black"

    Text {
        x: 25; y: 150
        text: "Qt Quick"
        color: "white"
        font.pixelSize: 32
    }

    Image {
        x: 50; y: 10
        source: "../images/rocket.svg"
    }
}
