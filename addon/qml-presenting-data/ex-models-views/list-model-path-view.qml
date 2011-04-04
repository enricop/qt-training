import QtQuick 1.0

Rectangle {
    width: 250; height: 250; color: "white"

    ListModel {
        id: nameModel
        ListElement { file: "../images/rocket.svg"
                      name: "rocket" }
        ListElement { file: "../images/clear.svg"
                      name: "clear" }
        ListElement { file: "../images/arrow.svg"
                      name: "arrow" }
        ListElement { file: "../images/book.svg"
                      name: "book" }
    }

    Component {
        id: nameDelegate
        Column {
            Image {
                id: delegateImage
                anchors.horizontalCenter: delegateText.horizontalCenter
                source: file; width: 64; height: 64; smooth: true
                fillMode: Image.PreserveAspectFit
            }
            Text {
                id: delegateText
                text: name; font.pixelSize: 24
            }
        }
    }

    PathView {
        anchors.fill: parent
        model: nameModel
        delegate: nameDelegate
        path: Path {
            startX: 50; startY: 50
            PathLine { x: 200; y: 50 }
            PathLine { x: 200; y: 200 }
            PathLine { x: 50; y: 200 }
            PathLine { x: 50; y: 50 }
        }
    }
}
