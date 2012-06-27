import QtQuick 2.0

Rectangle {
    width: 500
    height: 600

    AuthorView {
        id: authorView

        anchors.top: parent.top
        anchors.bottom: bookView.top
        height: parent.height / 2
        width: parent.width
    }

    BookView {
        id: bookView

        height: parent.height / 2
        width: parent.width
        anchors.bottom: parent.bottom
    }
}
