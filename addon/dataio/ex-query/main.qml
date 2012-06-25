import QtQuick 2.0

Rectangle {
    width: 300
    height: 300

    Component {
        id: bookDelegate

        Column {
            height: 70
            Text {
                text: title
            }

            Text {
                text: price
            }

            Text {
                text: notes
            }
        }
    }

    ListView {
        model: _model
        delegate: bookDelegate
        section.delegate: Rectangle {
            color: "red"
            height: 20
            width: parent.width

            Text {
                text: section
            }
        }
        section.property: "author"

        anchors.fill: parent
    }
}
