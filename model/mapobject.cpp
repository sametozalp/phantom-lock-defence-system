#include "mapobject.h"

MapObject::MapObject(int id, float lat, float lon, std::string name, float distance, float altitude, int speed) {
    this->id = id;
    this->lat = lat;
    this->lon = lon;
    this->name = name;
    this->speed = speed;
    this->distance = distance;
    this->altitude = altitude;
}
