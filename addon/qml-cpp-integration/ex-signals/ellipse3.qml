import QtQuick 2.0
import Shapes 3.0

Item {
    width: 300; height: 200

    Ellipse {
        x: 50; y: 35; width: 200; height: 100
        color: "blue"
        onReady: label.text = "Ready"
    }

    Text {
        id: label
        x: 50; y: 155; width: 200; height: 100
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 20
        text: "Not ready"
    }
}
