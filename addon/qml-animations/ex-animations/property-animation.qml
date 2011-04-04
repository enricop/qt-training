import QtQuick 1.0

Rectangle {
    width: 400; height: 400; color: "lightblue"

    Rectangle {
        id: rectangle1
        x: 150; y: 150; color: "green"
    }

    PropertyAnimation {
        target: rectangle1
        properties: "width,height"
        from: 0; to: 100; duration: 1000
        running: true
    }
}
