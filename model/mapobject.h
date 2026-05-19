#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <string>

class MapObject
{
public:
    MapObject(int id, float lat, float lon, std::string name, float distance, float altitude, int speed);

private:
    int id;
    float lat;
    float lon;
    std::string name;
    float distance;
    float altitude;
    int speed;
};

#endif // MAPOBJECT_H
