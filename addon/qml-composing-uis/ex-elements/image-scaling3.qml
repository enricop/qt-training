import QtQuick 1.0

Rectangle {
    width: 400; height: 400
    color: "black"

    Image {
        x: 150; y: 150
        source: "../images/rocket.svg"
        transform: Scale { xScale: 2.0; yScale: 2.0 }
        transformOrigin: Item.Center
    }
}
