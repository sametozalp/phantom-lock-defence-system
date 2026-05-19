#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <string>

class MapObject
{
public:
    MapObject(int id, float lat, float lon, std::string name);

private:
    int id;
    float lat;
    float lon;
    std::string name;
};

#endif // MAPOBJECT_H
