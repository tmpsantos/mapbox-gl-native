import QtGraphicalEffects 1.0
import QtPositioning 5.0
import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

import QQuickMapboxGL 1.0

ApplicationWindow {
    id: window

    title: "Mapbox GL QML example"
    width: 1024
    height: 768
    visible: true

    color: "#30b2d0"

    RowLayout {
        anchors.fill: parent
        anchors.margins: 50
        anchors.topMargin: 150
        anchors.bottomMargin: 150
        spacing: anchors.margins

        Flipable {
            id: flip1

            Layout.fillWidth: true
            Layout.fillHeight: true

            transform: Rotation {
                origin.x: flip1.width / 2
                origin.y: flip1.height / 2

                axis.x: 0; axis.y: 1; axis.z: 0

                angle: flipSlider.value
            }

            front: Rectangle {
                anchors.fill: parent

                color: window.color

                QQuickMapboxGL {
                    id: mapStreets

                    anchors.fill: parent
                    visible: false

                    style: "mapbox://styles/mapbox/streets-v9"

                    center: QtPositioning.coordinate(60.170448, 24.942046) // Helsinki
                    zoomLevel: 14
                    minimumZoomLevel: 0
                    maximumZoomLevel: 20

                    pitch: pitchSlider.value

                    color: "red"
                    copyrightsVisible: true
                }

                Rectangle {
                    id: maskStreets

                    anchors.fill: parent

                    radius: 30
                    clip: true
                    visible: false
                }

                OpacityMask {
                    anchors.fill: maskStreets

                    source: mapStreets
                    maskSource: maskStreets
                }

                MouseArea {
                    anchors.fill: parent

                    property var lastX: 0
                    property var lastY: 0

                    onWheel: mapStreets.zoomLevel += 0.2 * wheel.angleDelta.y / 120

                    onPressed: {
                        lastX = mouse.x
                        lastY = mouse.y
                    }

                    onPositionChanged: {
                        mapStreets.pan(mouse.x - lastX, mouse.y - lastY)

                        lastX = mouse.x
                        lastY = mouse.y
                    }
                }
            }

            back: Rectangle {
                anchors.fill: parent

                radius: maskStreets.radius

                Image {
                    anchors.centerIn: parent

                    sourceSize.width: parent.width - 200

                    source: "demo1.png"
                }
            }
        }

        Flipable {
            id: flip2

            Layout.fillWidth: true
            Layout.fillHeight: true

            transform: Rotation {
                origin.x: flip2.width / 2
                origin.y: flip2.height / 2

                axis.x: 1; axis.y: 0; axis.z: 0

                angle: flipSlider.value
            }

            front: Rectangle {
                anchors.fill: parent

                color: window.color

                QQuickMapboxGL {
                    id: mapSatellite

                    anchors.fill: parent
                    visible: false

                    style: "mapbox://styles/mapbox/satellite-streets-v9"

                    center: QtPositioning.coordinate(37.774009, -122.426255) // San Francisco
                    zoomLevel: 14
                    minimumZoomLevel: 0
                    maximumZoomLevel: 20

                    bearing: bearingSlider.value

                    color: "red"
                    copyrightsVisible: true
                }

                Rectangle {
                    id: maskSatellite

                    anchors.fill: parent

                    radius: maskStreets.radius
                    clip: true
                    visible: false
                }

                OpacityMask {
                    anchors.fill: maskSatellite

                    source: mapSatellite
                    maskSource: maskSatellite
                }

                MouseArea {
                    anchors.fill: parent

                    property var lastX: 0
                    property var lastY: 0

                    onWheel: mapSatellite.zoomLevel += 0.2 * wheel.angleDelta.y / 120

                    onPressed: {
                        lastX = mouse.x
                        lastY = mouse.y
                    }

                    onPositionChanged: {
                        mapSatellite.pan(mouse.x - lastX, mouse.y - lastY)

                        lastX = mouse.x
                        lastY = mouse.y
                    }
                }
            }

            back: Rectangle {
                anchors.fill: parent

                radius: maskStreets.radius

                Image {
                    anchors.centerIn: parent

                    sourceSize.width: parent.width - 30

                    source: "demo2.png"
                }
            }
        }

        Slider {
            id: pitchSlider

            Layout.fillHeight: true
            orientation: Qt.Vertical

            value: 0
            minimumValue: 0
            maximumValue: 60
        }

        Slider {
            id: bearingSlider

            Layout.fillHeight: true
            orientation: Qt.Vertical

            value: 0
            minimumValue: 0
            maximumValue: 180
        }

        Slider {
            id: flipSlider

            Layout.fillHeight: true
            orientation: Qt.Vertical

            value: 0
            minimumValue: 0
            maximumValue: 180
        }
    }
}
