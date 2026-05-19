#include "mapobject.h"

MapObject::MapObject(int id, float lat, float lon, std::string name) {
    this->id = id;
    this->lat = lat;
    this->lon = lon;
    this->name = name;
}
