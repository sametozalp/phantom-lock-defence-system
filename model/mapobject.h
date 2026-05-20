#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <string>
#include <QObject>
#include <QString>

class MapObject : public QObject
{
    Q_OBJECT
public:
    MapObject(int id, float lat, float lon, QString name, float distance, float altitude, int speed);

    int getId() const;
    float getLat() const;
    float getLon() const;
    QString getName() const;
    float getDistance() const;
    float getAltitude() const;
    int getSpeed() const;

private:
    int id;
    float lat;
    float lon;
    QString name;
    float distance;
    float altitude;
    int speed;
};

#endif // MAPOBJECT_H
