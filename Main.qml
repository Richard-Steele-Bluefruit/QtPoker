import QtQuick
import QtQuick.Window

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Poker Hand Analyzer")

    Rectangle {
        id: pokerTable
        width: parent.width
        height: parent.height
        color: "green"

        // Cards in the middle for the flop, turn, and river
        Row {
            id: communityCards
            width: parent.width * 2/3
            height: parent.height * 1/2
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 10
            spacing: 10

            Component {
                id: cardComponent

                Rectangle {
                    width: communityCards.width / 5 - communityCards.spacing
                    height: communityCards.height
                    color: pokerTable.color

                    Image {
                        source: modelData
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                    }
                }
            }

            Repeater {
                model: communityCards.cards //[
                //    "qrc:/cards/2_of_clubs.png",
                //    "qrc:/cards/3_of_clubs.png",
                //    "qrc:/cards/4_of_clubs.png",
                //    "qrc:/cards/5_of_clubs.png",
                //    "qrc:/cards/6_of_clubs.png"
                //]
                delegate: cardComponent
            }

            Component.onCompleted: {
                deck.removeRandomCard()
            }
        }

        // Cards at the bottom for the player's hand
        Row {
            id: playerHand
            width: childrenRect.width
            height: communityCards.height
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 10
            spacing: 10

            Repeater {
                model: [
                    "qrc:/cards/7_of_clubs.png",
                    "qrc:/cards/8_of_clubs.png",
                ]
                delegate: cardComponent
            }
        }
    }
}
