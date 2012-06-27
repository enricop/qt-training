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
                onAccepted: _bookStore.bookModel.setData(ListView.currentIndex, "title", text)
            }

            Text {
                text: "Price:"
            }

            TextInput {
                text: price
                onAccepted: _bookStore.bookModel.setData(ListView.currentIndex, "price", text)
            }

            Text {
                text: "Notes:"
            }

            TextInput {
                text: notes
                onAccepted: _bookStore.bookModel.setData(ListView.currentIndex, "notes", text)
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
        footer: Rectangle {
            width: parent.width
            height: 30

            Rectangle {
                width: parent.width / 3
                height: parent.height
                radius: 5
                color: "lightgray"
                anchors.left: parent.left

                Text {
                    text: "Add Book"
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _bookStore.addBook()
                    }
                }
            }

            Rectangle {
                enabled: ListView.currentIndex != -1
                width: parent.width / 3
                height: parent.height
                radius: 5
                color: "lightgray"
                anchors.right: parent.right

                Text {
                    text: "Remove Book"
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _bookStore.removeBook(ListView.currentIndex)
                    }
                }
            }
        }


        anchors.fill: parent
    }
}
