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
                // Step 6: change model data on text change accepted
            }

            Text {
                text: "Last Name:"
            }

            TextInput {
                text: lastName
                // Step 6: change model data on text change accepted
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

        // Step 4: change bookstore's current author when selection changes

        focus: true
        anchors.fill: parent
    }
}
