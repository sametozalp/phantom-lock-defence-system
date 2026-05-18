import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
    width: 800
    height: 600
    focus: true // for handle keyboard event

    Keys.onPressed: (event) => {
        var step = 40;

        switch (event.key) {
            case Qt.Key_Right:
                map.pan(step, 0);
                break;
            case Qt.Key_Left:
                map.pan(-step, 0);
                break;
            case Qt.Key_Down:
                map.pan(0, step);
                break;
            case Qt.Key_Up:
                map.pan(0, -step);
                break;
        }
    }

    ListModel { id: markerModel }

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(39.9334, 32.8597)
        zoomLevel: 12
    }

    Rectangle {
        width: 40
        height: 40
        radius: 5

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10

        Text {
            anchors.centerIn: parent
            text: "+"
            font.bold: true
            font.pixelSize: 20
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                map.zoomLevel += 1
            }
        }
    }

    Rectangle {
        width: 40
        height: 40
        radius: 5

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.rightMargin: 10

        Text {
            anchors.centerIn: parent
            text: "-"
            font.bold: true
            font.pixelSize: 20
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                map.zoomLevel -= 1
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.NoButton

        onWheel: function(wheel) {
          if (wheel.angleDelta.y > 0)
              map.zoomLevel += 1
          else
              map.zoomLevel -= 1
        }
    }
}