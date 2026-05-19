#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <string>

class MapObject
{
public:
    MapObject(int lat, int lon, std::string name);

private:
    int lat;
    int lon;
    std::string name;
};

#endif // MAPOBJECT_H
