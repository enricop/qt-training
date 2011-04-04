import QtQuick 1.0

Rectangle {
    width: 400; height: 400
    color: "lightblue"

    Rectangle {
        y: 150; width: 100; height: 100
        color: "green"

        NumberAnimation on x {
            from: 0; to: 150; duration: 1000
            easing.type: "OutExpo"
        }
    }
}
