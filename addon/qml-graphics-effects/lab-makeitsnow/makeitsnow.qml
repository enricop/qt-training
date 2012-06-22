import QtQuick 2.0
import QtQuick.Particles 2.0

Image {
    id: picture
    source: "../images/tampere.jpg"
    smooth: true

    // Hint: use "../images/sizeTable.png" as sizeTable: value
    Image {
        source: "../images/snowflake.png"
    }
}
