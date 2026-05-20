#include "mapmarker.h"

MapMarker::MapMarker(QObject *parent)
    : QObject(parent)
{
}

QVariantList MapMarker::markers() const
{
    return m_markers;
}

void MapMarker::setMarkers(const QVariantList &markers)
{
    if (m_markers != markers) {
        m_markers = markers;
        emit markersChanged();
    }
}

void MapMarker::onMarkerClicked(int id)
{
    emit markerClicked(id);
}
