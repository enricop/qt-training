import QtQuick 2.0

Rectangle {
    width: 600; height: 600
    color: "azure"

    Canvas {
        anchors.fill: parent

        onPaint: {
            var context = getContext("2d")
            context.clearRect(0, 0, width, height)

            context.fillRule = Qt.OddEvenFill
            context.fillStyle = "forestgreen"
            context.beginPath()
            context.moveTo(60, 60)
            context.bezierCurveTo(540, 60, 60, 540, 540, 540)
            context.bezierCurveTo(540, 60, 60, 540, 60, 60)
            context.closePath()
            context.rect(120, 120, 360, 360)
            context.fill()
        }
    }
}

