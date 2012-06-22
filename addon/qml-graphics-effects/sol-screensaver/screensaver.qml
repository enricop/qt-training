import QtQuick 2.0

Rectangle {
    width: 600; height: 600
    color: "black"

    property int pointCount: 3

    function randomCoordinate(max) {
        return Math.floor(Math.random()*max)
    }

    function randomPoints() {
        var result = []
        for (var i=0; i<pointCount; i++) {
            result.push(Qt.point(randomCoordinate(width),
                                 randomCoordinate(height)))
        }
        return result;
    }

    function randomSpeed() {
        var result = Math.floor((Math.random() - 0.5) * 8)
        if (result ==0) result = 1
        return result
    }

    function randomSpeeds() {
        var result = []
        for (var i=0; i<pointCount; i++) {
            result.push(Qt.point(randomSpeed(), randomSpeed()))
        }
        return result;
    }

    function updatePoints() {
        for (var i=0; i<pointCount; i++) {
            var point = points[i]
            var speed = speeds[i]

            if (point.x + speed.x <= 0) {
                point.x = 0
                speed.x = -speed.x
            } else if (point.x + speed.x >= width) {
                point.x = width
                speed.x = -speed.x
            } else {
                point.x = point.x + speed.x
            }

            if (point.y + speed.y <= 0) {
                point.y = 0
                speed.y = -speed.y
            } else if (point.y + speed.y >= height) {
                point.y = height
                speed.y = -speed.y
            } else {
                point.y = point.y + speed.y
            }

            points[i] = point
            speeds[i] = speed
        }
    }

    property var points: randomPoints()
    property var speeds: randomSpeeds()

    Timer {
        interval: 20
        running: true
        repeat: true

        onTriggered: {
            updatePoints()
            canvas.requestPaint()
        }
    }

    Canvas {
        id: canvas
        anchors.fill: parent
        smooth: true

        onPaint: {
            var context = getContext("2d")
            context.clearRect(0, 0, width, height)

            context.strokeStyle = "pink"
            context.lineWidth = 2
            context.beginPath()

            for (var i=0; i<points.length; i++) {
                if (i==0) {
                    context.moveTo(points[i].x, points[i].y)
                } else {
                    context.lineTo(points[i].x, points[i].y)
                }
            }

            context.closePath()
            context.stroke()
        }
    }
}
