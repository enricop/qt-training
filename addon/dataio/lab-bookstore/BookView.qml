import QtQuick 2.0

Item {
    Component {
        id: bookDelegate

        Grid {
            columns: 2
            spacing: 5
            Text {
                text: "Title:"
            }

            TextInput {
                text: title
                // Step 6: change model data on text change accepted
            }

            Text {
                text: "Price:"
            }

            TextInput {
                text: price
                // Step 6: change model data on text change accepted
            }

            Text {
                text: "Notes:"
            }

            TextInput {
                text: notes
                // Step 6: change model data on text change accepted
            }
        }
    }

    ListView {
        model: _bookStore.bookModel
        delegate: bookDelegate
        highlight: Rectangle { width: parent.width;  color: "lightsteelblue"; radius: 5 }
        header: Rectangle {
            height: 20
            width: parent.width
            color: "lightblue"

            Text {
                text: "Book"
                anchors.centerIn: parent
            }
        }

        anchors.fill: parent
    }
}
