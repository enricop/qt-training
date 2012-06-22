import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    width: 400; height: 600
    color: "black"

    ParticleSystem {
        anchors.fill: parent

        Emitter {
            x: parent.width/2
            y: parent.height

            emitRate: 500
            lifeSpan: 5000
            lifeSpanVariation: 500
            size: 16

            speed: AngleDirection { magnitude: 300; angle: -90; angleVariation: 2 }
            acceleration: PointDirection { y: -100; xVariation: 10 }
        }

        ImageParticle {
            source: "../images/particle.png"
            sizeTable: "../images/sizeTable.png"
            redVariation: 20
        }

        Gravity {
            magnitude: 200
        }
    }
}
