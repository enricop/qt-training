import QtQuick 2.0
import QtQuick.Particles 2.0

Image {
    id: picture
    source: "../images/tampere.jpg"
    smooth: true

    ParticleSystem {
        anchors.fill: parent

        Emitter {
            id: emitter
            y: 0
            width: parent.width

            emitRate: 4
            lifeSpan: 15000
            lifeSpanVariation: 500
            speed: PointDirection { y: 20; yVariation: 10; xVariation: 10 }
            size: 64
        }

        Affector {
            anchors.fill: parent

            onAffectParticles: {
                for (var i=0; i<particles.length; i++) {
                    var particle = particles[i];
                    if (particle.r == 0.0) {
                        particle.r = Math.random() - 0.5;
                    }
                    particle.rotation += particle.r * dt;
                    particle.update = 1;
                }
            }
        }

        ImageParticle {
            source: "../images/snowflake.png"
            sizeTable: "../images/sizeTable.png"
            redVariation: 20
        }
    }
}
