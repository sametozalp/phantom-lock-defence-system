#include "mapobject.h"

MapObject::MapObject(int lat, int lon, std::string name) {
    this->lat = lat;
    this->lon = lon;
    this->name = name;
}
