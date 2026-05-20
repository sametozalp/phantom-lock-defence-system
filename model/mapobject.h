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

    int getId();

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
