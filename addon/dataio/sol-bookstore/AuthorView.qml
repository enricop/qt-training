import QtQuick 2.0

Item {
    Component {
        id: authorDelegate

        Grid {
            columns: 2
            spacing: 5
            Text {
                text: "First Name:"
            }

            TextInput {
                text: firstName
                onAccepted: _bookStore.authorsModel.setData(ListView.currentIndex, "firstName", text)
            }

            Text {
                text: "Last Name:"
            }

            TextInput {
                text: lastName
                onAccepted: _bookStore.authorsModel.setData(ListView.currentIndex, "lastName", text)
            }
        }
    }

    ListView {
        model: _bookStore.authorsModel
        delegate: authorDelegate
        highlight: Rectangle { width: parent.width; color: "lightsteelblue"; radius: 5 }
        header: Rectangle {
            height: 20
            width: parent.width
            color: "lightblue"

            Text {
                text: "Author"
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
                    text: "Add Author"
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _bookStore.addAuthor()
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
                    text: "Remove Author"
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _bookStore.removeAuthor(ListView.currentIndex)
                    }
                }
            }
        }

        onCurrentIndexChanged: _bookStore.authorChanged(currentIndex)


        focus: true
        anchors.fill: parent
    }
}
