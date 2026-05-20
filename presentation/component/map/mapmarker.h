#ifndef MAPMARKER_H
#define MAPMARKER_H

#include <QObject>
#include <QVariantList>
#include <QVariantMap>

class MapMarker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList markers READ markers WRITE setMarkers NOTIFY markersChanged)

public:
    explicit MapMarker(QObject *parent = nullptr);

    QVariantList markers() const;
    void setMarkers(const QVariantList &markers);

signals:
    void markersChanged();

private:
    QVariantList m_markers;
};

#endif // MAPMARKER_H
